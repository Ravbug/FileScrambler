# FileScrambler
Simple file shuffling utility, written in C++

## Compilation
This project uses CMake.
```sh
mkdir build && cd build
cmake .. && cmake --build . --config Release
```

## Targets provided
1. HellpackGen
   - This is a utility for shuffling Minecraft textures and sounds. To use, copy the `sounds` and `textures` directories from your 
Minecraft Java Edition install into the same directory as the executable, and run `./HellpackGen`
   - You can get the `textures` folder by unzipping the version jar, and you can get the `sounds` folder by using my [Minecraft Sounds Extractor](https://github.com/Ravbug/MCSoundsExtractorCPP)
