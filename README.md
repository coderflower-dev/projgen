# projgen
Generate C++ projects with ease!

## What can this program do?<br>
+ Creates a folder with name of the project<br>
+ Creates "include", "lib", and "src"<br>
+ Creates Makefile (and others!) and C++ source file with sample code<br>
+ Allows you to use custom build sample code!

## How to use this program?<br>
+ First parameter is the project name<br>
+ Second parameter is the build method (built in, check below of how to use custom one), it can be:<br>
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
+ [Video explaning how to do it](https://www.youtube.com/watch?v=76D7_6vsli4&ab_channel=DrFlower)

## How can I use a custom build method?<br>
Instead of writing `-makefile` or like `-script` you just input the path/name of the custom build methdo! <br>

## Example build method<br>
`g++ src/^.cpp -o ^ -Iinclude -Llib`<br>
(`^` means the name of the project)<br>
So what will be created is (project name is game)<br>
`g++ src/game.cpp -o game -Iinclude -Llib`<br>
