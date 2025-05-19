#include "stdafx.h"
#include "AnimationSaver.h"
#include <tge/engine.h>
#include <tge/graphics/DX11.h>
#include <tge/graphics/GraphicsEngine.h>
#include <DirectXTex/DirectXTex.h>
#include <fstream>
#include <tge/settings/settings.h> 
#include <io.h>

using namespace Tga;

void AnimationPlayer::Init(const std::shared_ptr<const Animation>& animation, const std::shared_ptr<const Model>& model)
{
	myModel = model;
	myAnimation = animation;
	myFPS = animation->FramesPerSecond;
}

void AnimationPlayer::UpdateFrame()
{
	for (unsigned int frameNumber = 0; frameNumber < myAnimation->Length; frameNumber++)
	{
		// Update animation and save positions of bones.
		const Skeleton* skeleton = myModel->GetSkeleton();
		for (size_t j = 0; j < skeleton->Joints.size(); j++)
		{
			const auto& currentFrameJointXform = myAnimation->Frames[frameNumber].LocalTransforms.find(skeleton->Joints[j].Name)._Ptr->_Myval.second;
			Matrix4x4f jointXform = currentFrameJointXform.GetMatrix();

			Matrix4x4f Result = jointXform;
			myLocalSpacePoseForTexture.JointTransforms[j] = Result;
		}

		myLocalSpacePoseForTexture.Count = skeleton->Joints.size();
		SaveAnimationPostions(frameNumber);
	}
}

void Tga::AnimationPlayer::SaveAnimationPostions(unsigned int currentFrame)
{
	const Skeleton* skeleton = myModel->GetSkeleton();
	if (currentFrame < myAnimation->Length - 1)
	{
		myLocalSpacePoseForTexture.Count = skeleton->Joints.size();
		ModelSpacePose modelSpacePose;
		myModel->GetSkeleton()->ConvertPoseToModelSpace(myLocalSpacePoseForTexture, modelSpacePose);
		myModel->GetSkeleton()->ApplyBindPoseInverse(modelSpacePose, myBoneTransforms);
		fullAnimationBoneMatricies[currentFrame].resize(myLocalSpacePoseForTexture.Count);
		for (size_t i = 0; i < myLocalSpacePoseForTexture.Count; i++)
		{
			fullAnimationBoneMatricies[currentFrame][i] = myBoneTransforms[i];
		}
	}
	else if (currentFrame == myAnimation->Length - 1)
	{
		myLocalSpacePoseForTexture.Count = skeleton->Joints.size();
		ModelSpacePose modelSpacePose;
		myModel->GetSkeleton()->ConvertPoseToModelSpace(myLocalSpacePoseForTexture, modelSpacePose);
		myModel->GetSkeleton()->ApplyBindPoseInverse(modelSpacePose, myBoneTransforms);
		fullAnimationBoneMatricies[currentFrame].resize(myLocalSpacePoseForTexture.Count);
		for (size_t i = 0; i < myLocalSpacePoseForTexture.Count; i++)
		{
			fullAnimationBoneMatricies[currentFrame][i] = myBoneTransforms[i];
		}
		WriteToTexture(fullAnimationBoneMatricies);
	}
	else
	{
		std::cout << "Done!" << std::endl;
	}
}

void Tga::AnimationPlayer::WriteToTexture(std::unordered_map<int, std::vector<Tga::Matrix4x4f>> aFullAnimationBoneMatriciesMap)
{
	D3D11_TEXTURE2D_DESC texDesc = {};
	texDesc.Width = static_cast<unsigned int>(myModel->GetSkeleton()->Joints.size()) * 4;  // 4 floats per row (each matrix row)
	texDesc.Height = myAnimation->Length; // Total rows for all instances
	texDesc.MipLevels = 1;
	texDesc.ArraySize = 1;
	texDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	texDesc.SampleDesc.Count = 1;
	texDesc.Usage = D3D11_USAGE_DYNAMIC;
	texDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	texDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	HRESULT hr = Tga::DX11::Device->CreateTexture2D(&texDesc, nullptr, &myBoneTexture);
	if (FAILED(hr))
	{
		// Handle failure
	}

	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
	srvDesc.Format = texDesc.Format;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MostDetailedMip = 0;
	srvDesc.Texture2D.MipLevels = 1;

	hr = Tga::DX11::Device->CreateShaderResourceView(myBoneTexture.Get(), &srvDesc, &myBoneTextureSRV);
	if (FAILED(hr))
	{
		OutputDebugStringA("Failed to create BoneTexture SRV!\n");
	}

	D3D11_MAPPED_SUBRESOURCE mappedResource;
	hr = Tga::DX11::Context->Map(myBoneTexture.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(hr))
	{
		// Handle error
		return;
	}

	BYTE* destData = reinterpret_cast<BYTE*>(mappedResource.pData);
	UINT rowPitch = mappedResource.RowPitch; // Number of bytes per row

	// and each bone matrix occupies 4 texels.
	size_t frameCount = myAnimation->Length; // total frames instances
	size_t bonesInAnimation = myModel->GetSkeleton()->Joints.size(); // number of bones per animation

	// For each frame (each row)
	for (unsigned int frame = 0; frame < frameCount; frame++)
	{
		// Destination pointer for this animations row
		BYTE* destRow = destData + (frame * rowPitch);

		// For each bone matrix for this enemy
		for (size_t b = 0; b < bonesInAnimation; b++)
		{

			// Pointer to the source bone matrix (16 floats)
			const float* src = reinterpret_cast<const float*>(&fullAnimationBoneMatricies[frame][b]);

			// Each bone matrix takes 4 texels.
			size_t texelOffset = b * 4;

			// For each texel (0 to 3) in this bone matrix:
			for (int c = 0; c < 4; c++)
			{
				// Destination for this texel:
				BYTE* destTexel = destRow + ((texelOffset + c) * sizeof(float) * 4);
				// Copy 4 floats (one row of the bone matrix) into the texel.
				memcpy(destTexel, src + (c * 4), sizeof(float) * 4);
			}
		}
	}

	Tga::DX11::Context->Unmap(myBoneTexture.Get(), 0);
	//GetPathAndSetFileName
	std::wstring path = Tga::Settings::ResolveAssetPathW(myModel->GetPath());
	std::wstring baseFileName = path.substr(0, path.find_last_of(L'.'));
	std::size_t found = path.find_last_of(L"/\\");
	std::wstring folderPath = baseFileName.substr(0, found);
	std::wstring filename =  baseFileName.substr(baseFileName.find_last_of(L"/\\") + 1, baseFileName.length());
	std::wstring suffix = L"_ANIM.dds";
	std::wstring prefix = L"/T_";
	path = folderPath+ prefix + filename + suffix;

	//WriteTexture
	DirectX::ScratchImage img;
	hr = CaptureTexture(Tga::DX11::Device, Tga::DX11::Context, myBoneTexture.Get(), img);
	if (FAILED(hr)) { /* report error */ }
	hr = SaveToDDSFile(img.GetImages(), img.GetImageCount(),
		img.GetMetadata(), DirectX::DDS_FLAGS_NONE,
		path.c_str());

	//Write binary file for FPS and Duration of stuff;
	std::wstring data = L"_BIN.bin";
	filename = filename + data;
	std::ofstream animationData(filename, std::ios::binary);
	
	if (!animationData)
	{
		std::cout << "Cannot open file!" << std::endl;
		return;
	}

	std::string asset = FromWstring(folderPath);
	animationData.write(reinterpret_cast<const char*>(&myAnimation->Duration), sizeof(float));
	animationData.write(reinterpret_cast<const char*>(&myFPS), sizeof(float));
	animationData.close();
	if (!animationData.good())
	{
		std::cout << "Error occurred at writing time!" << std::endl;
	}
	std::wstring oldPath = Tga::Settings::GetBinPathW() + filename;
	std::wstring newPath = baseFileName + data;

	//Move file to the right folder_
	bool result = MoveFileW(oldPath.c_str(), newPath.c_str());

	if (result)
		printf("File was moved!");
	else
		printf("File wasn't moved!");
}
