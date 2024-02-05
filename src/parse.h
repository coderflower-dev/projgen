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


//lol CTRL-C CTRL-V from some other projects i made





//lol code from my secret code collection ;)
//1/22/2024
#pragma once
//Designed to convert an iostream into a C++ string
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

//IOSTREAM -> STRING; Just input the file location
std::string iotos(std::string location)
{
    std::ifstream file(location);
    //stringstream example by https://stackoverflow.com/questions/20594520/what-exactly-does-stringstream-do glhrmv and richard.g
    std::ostringstream stream;
    stream << file.rdbuf(); //chatgpt
    return stream.str();
}

//IOSTREAM -> STRING; Use this if you have an iostream setup
std::string iotosIF(std::ifstream file)
{
    //stringstream example by https://stackoverflow.com/questions/20594520/what-exactly-does-stringstream-do glhrmv and richard.g
    std::ostringstream stream;
    stream << file.rdbuf(); //chatgpt
    return stream.str();
}

//even more code I made sometime ago
//Code to parse, parsed code, split by, which item
std::string parse(std::string input, std::string projectName)
{
    std::string temporary;
    for(auto x : input)
    {
        //If this special tag is found then add the project name
        if(x == '^')
        {
            temporary += projectName;
        }
        else
        {
            temporary += x;
        }
    }
    return temporary;
}

//^ means projectName
