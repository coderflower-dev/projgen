/*
BSD 2-Clause License

Copyright (c) 2024, DrFlower

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

int main(int argc, char **argv)
{
    namespace fs = std::filesystem;

    //Folders
    fs::path projectPath = argv[1];
    fs::path srcPath = projectPath / "src";
    fs::path libPath = projectPath / "lib";
    fs::path includePath = projectPath / "include";

    //Arguments to string
    std::string projectName = std::string(argv[1]);
    std::string buildName = std::string(argv[2]);

    //-makefile
    //-batch
    //-sh
    //-script

    //Base code (Makefile and source)
    std::string codeSample = "#include <iostream>\n\nint main()\n{\n\tstd::cout << \"Hello, World!\";\n\treturn 0;\n}";
    std::string makeSample = "all:\n\tg++ src/" + projectName + ".cpp -o " + projectName + " -Iinclude -Llib\n";
    std::string batchSample = "g++ src/" + projectName + ".cpp -o " + projectName + " -Iinclude -Llib\n";
    std::string shellSample = "g++ src/" + projectName + ".cpp -o " + projectName + " -Iinclude -Llib\n";

    try{

         if(fs::create_directories(projectPath)) //Main project path
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

        //Makefile
        if(buildName == "-makefile")
        {
            std::string makePath = projectName + "/Makefile";
            std::ofstream makeFile(makePath);
            if(makeFile)
                std::cout << "Makefile created\n\n";
            makeFile << makeSample;
        }
        //Batch based
        else if(buildName == "-batch")
        {
            std::string batchPath = projectName + "/build.bat";
            std::ofstream batchFile(batchPath);
            if(batchFile)
                std::cout << "Batch building file created\n\n";
            batchFile << batchSample;
        }
        else if(buildName == "-sh")
        {
            std::string shPath = projectName + "/build.sh";
            std::ofstream shFile(shPath);
            if(shFile)
                std::cout << "Shell building file created\n\n";
            shFile << shellSample;
        }
        else if(buildName == "-script")
        {
            //Unix Shell
            std::string shPath = projectName + "/build.sh";
            std::ofstream shFile(shPath);
            if(shFile)
                std::cout << "Shell building file created\n";
            shFile << shellSample;

            
            //Windows Batch
            std::string batchPath = projectName + "/build.bat";
            std::ofstream batchFile(batchPath);
            if(batchFile)
                std::cout << "Batch building file created\n\n";
            batchFile << batchSample;
        }
        else
        {
            std::cout << "Error! Build method not selected!\n";
        }


    } catch (const fs::filesystem_error& e)
    {
        std::cerr << "Error occured! " << e.what() << "\n";
    }

}
