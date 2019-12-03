#!/usr/bin/env bash
gcc -c `sdl2-config --cflags` *.c;
mv *.o ./c_files;
gcc ./c_files/*.o `sdl2-config --libs` -lSDL2_ttf -o exe;
