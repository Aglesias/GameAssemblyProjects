This is mostly school project code that was used creating games in an in house engine at The Game Assembly.

       * Animation saver is a project that writes bone possitions from an animations and writes it to a texture 
       to be able to make looping animations play by reading the positions from the texture, this to unload the CPU 
       since it wont need to do a lot of the matrix math associated with animations.

       * Binary template is a template class to read/write binary files to be able to achive faster loading times.
       In our game projects at school it was mainly use to reduce loading times in debug mode since all the data was 
       originally loaded from a json file. Load times where reduced from 20 sec to 0.5 sec.

       * Thread pool is a thread pool that uses lambda expressions to be able to push jobs. Nothing more, nothing less.
       Would like to iterate on it to have childed work and work stealing as well. A fun project for the future.
