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
