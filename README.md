Download the fix2064sacd.exe (Windows 64bit) or build from source code. Then run:

```ps
PS > fix2064sacd.exe -i Source_ISO_file -o Target_ISO_file
```

## Compile from source code

Follow [MinGW](https://code.visualstudio.com/docs/cpp/config-mingw#_prerequisites) guide.

1. Get [MYYS2](https://github.com/msys2/msys2-installer/releases/download/2023-05-26/msys2-x86_64-20230526.exe)

2. Install MinGW-w64 toolchain in MSYS2 terminal

    `pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain`

   Enter and Y

3. In folder containing fix2064sacd.c file, run:

   `gcc -o fix2064sacd.exe fix2064sacd.c`
