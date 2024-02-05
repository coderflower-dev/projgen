# projgen
Generate C++ projects with ease!

## What can this program do?<br>
+ Creates a folder with name of the project<br>
+ Creates `include`, `lib`, and `src`<br>
+ Creates Makefile and a C++ source file with sample code<br>
+ Allows you to use custom build scripts!

## How to use this program?
+ Type in the name of project as the first parameter
+ Optionaly enter the path of the custom Makefile you wish to use

## How can I create a custom Makefile sample code?<br>
+ You create a Makefile
+ You create the Makefile code as usual
+ Instead of the (for example) `main.cpp` you put `^.cpp`
+ `^` means the name of the project
+ Please note that source files (by default) are in the `src` folder
+ [Video explaning how to do it](https://www.youtube.com/watch?v=76D7_6vsli4&ab_channel=DrFlower) (Note this video is outdated, yet should still work)

## Example custom Makefile<br>
`g++ src/^.cpp -o ^ -Iinclude -Llib`<br>
(`^` means the name of the project)<br>
So what will be created is (project name is game)<br>
`g++ src/game.cpp -o game -Iinclude -Llib`<br>

## Sample Makefiles<br>
These are located at `makefile_sample`

### TODO:
+ Make one big file for custom Makefile and Sample Code
+ Add more .PG sample files
