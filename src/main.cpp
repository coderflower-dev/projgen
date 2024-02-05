/*
Copyright 2024 therealdrflower.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#include "parse.h"

int main(int argc, char* argv[])
{
    namespace fs = std::filesystem;

    //If the first param. is empty, use default name
    std::string projectName = "ididnotpickone";
    if(argc > 0 && argv[1] != nullptr)
        projectName = std::string(argv[1]);


    //Folders
    fs::path projectPath(projectName);
    fs::path srcPath = projectPath / "src";
    fs::path libPath = projectPath / "lib";
    fs::path includePath = projectPath / "include";


    //If the second param. is empty, use default makefile
    std::string buildName = "defaultMakefile";
    if(argc > 1 && argv[2] != nullptr)
        buildName = argv[2];

    //Base code (Makefile and source)
    std::string codeSample = "#include <iostream>\n\nint main()\n{\n\tstd::cout << \"Hello, World!\";\n\treturn 0;\n}";
    std::string makeSample = "all:\n\tg++ src/" + projectName + ".cpp -o " + projectName + " -Iinclude -Llib\n";

    try{

         if(fs::create_directories(projectName)) //Main project path
         {
            std::cout << "\nProject file created\n";
         }
         else std::cout << "That file exists already!\n";

        if(fs::create_directories(srcPath)) //Source code folder
            std::cout << "\nSource folder created\n";
        if(fs::create_directories(libPath)) //Libs folder
            std::cout << "Library folder created\n";
        if(fs::create_directories(includePath)) //Includes folder
            std::cout << "Include folder created\n";

        // Create text files

        //Source file
        std::string codePath = projectName + "/src/" + projectName + ".cpp";
        std::ofstream codeFile(codePath); //Create file
        if(codeFile)
            std::cout << "\nSource file created\n";
        codeFile << codeSample;

        //Use default makefile
        if(buildName == "defaultMakefile")
        {
            std::string makePath = projectName + "/Makefile";
            std::ofstream makeFile(makePath);
            if(makeFile)
                std::cout << "Makefile created\n\n";
            makeFile << makeSample;
        }
        else
        {
            std::string makeCustomUnparsed = iotos(buildName);
            std::string makeCustomParsed = parse(makeCustomUnparsed,projectName);
            std::string makeCustomPath = projectName + "/" + "Makefile";
            std::ofstream makeCustomFile(makeCustomPath);
            if(makeCustomFile)
                std::cout << "Custom Makefile created\n\n";
            makeCustomFile << makeCustomParsed;
        }


    } catch (const fs::filesystem_error& e)
    {
        std::cerr << "Error occured! " << e.what() << "\n";
    }

}
