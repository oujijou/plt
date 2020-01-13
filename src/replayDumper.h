#pragma once

#include <string>
#include <iostream>
#include <fstream>

inline void logReplay(std::string file, std::string content)
{
    std::ofstream ofstream(file);
    ofstream << content << std::endl;
    ofstream.close();
}