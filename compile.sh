#!/usr/bin/env bash
gcc -c `sdl2-config --cflags` *.c;
mv *.o ./compiled_files;
gcc ./compiled_files/*.o `sdl2-config --libs` -lSDL2_ttf -o exe;
