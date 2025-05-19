#pragma once
#include <vector>
#include <d3d11.h>
#include <string>
#include <memory>
#include <tge/animation/animation.h>
#include <tge/animation/pose.h>
#include <tge/model/model.h>

using Microsoft::WRL::ComPtr;

namespace Tga
{
	
	class AnimationSaver
	{
	private:
		std::shared_ptr<const Animation> myAnimation = nullptr;
		std::shared_ptr<const Model> myModel = nullptr;
		float myFPS = 0.f;

		LocalSpacePose myLocalSpacePoseForTexture;
		Matrix4x4f myBoneTransforms[MAX_ANIMATION_BONES];
		std::vector<Tga::Matrix4x4f> myBoneMatrices;
		std::unordered_map<int, std::vector<Tga::Matrix4x4f>> fullAnimationBoneMatricies;
		ComPtr<ID3D11Texture2D> myBoneTexture = nullptr;
		ID3D11ShaderResourceView* myBoneTextureSRV = nullptr;

	public:
		void Init(const std::shared_ptr<const Animation>& animation, const std::shared_ptr<const Model>& model);

		// Call update frame to make a texture with the bone information
		void UpdateFrame();
		void SaveAnimationPostions(unsigned int currentFrame);
		void WriteToTexture(std::unordered_map<int, std::vector<Tga::Matrix4x4f>> aFullAnimationBoneMatriciesMap);

		bool GetIsInterpolating() const { return myIsInterpolating; }
		void AnimationPlayer::SetIsInterpolating(bool shouldInterpolate) { myIsInterpolating = shouldInterpolate; }

		float GetFramesPerSecond() const { return myFPS; }
		void AnimationPlayer::SetFramesPerSecond(float someFPS)
		{
			myFPS = someFPS;
		}

		std::shared_ptr<const Animation> GetAnimation() const { return myAnimation; }
		
		unsigned int AnimationPlayer::GetFrame() { return static_cast<unsigned int>(myTime * myFPS); }

		bool IsValid() const { return myModel ? true : false; }
	};
}

