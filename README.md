# projgen
A simple C++ project creation program

## What can this program do?<br>
+ Creates a folder with name of the project<br>
+ Creates "include", "lib", and "src"<br>
+ Creates Makefile (and others!) and C++ source file with sample code<br>
+ Create custom build methods!

## How to use?<br>
+ First parameter is the project name<br>
+ Second parameter is the build method (built in), it can be:<br>
  - `-makefile` for Makefile
  - `-sh` for Linux Shell script
  - `-batch` for Windows Console script
  - `-script` for both Windows and Linux build script

## How can I create a custom build method?<br>
+ You create a text file
+ You create the build system code as usual
+ Instead of the (for example) `main.cpp` you put `^.cpp`
+ `^` means the name of the project
+ Please note that source files (by default) are in the `src` folder

## How can I use a custom build method?<br>
Instead of writing `-makefile` or like `-script` you just input the name of the custom build method! <br>

## Example build method<br>
`g++ src/^.cpp -o ^ -Iinclude -Llib`<br>
(`^` means the name of the project)<br>
So what will be created is (project name is game)<br>
`g++ src/game.cpp -o game -Iinclude -Llib`<br>
