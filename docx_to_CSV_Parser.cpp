#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include "./pugixml-master/src/pugixml.hpp"

int main(int argc, char* argv[])
{
    char* inputFilePath = argv[1];
    if (argc != 2)
    {
        while(inputFilePath == nullptr)
        {
            std::cout << "Please provide a valid input file path: ";
            std::cin >> inputFilePath;
        }
    }
    
    pugi::xml_document doc_tgt;
    pugi::xml_parse_result result_tgt = doc_tgt.load_file(inputFilePath);

    if(!result_tgt)
    {
        std::cerr << "Error loading XML file: " << result_tgt.description() << std::endl;
        return 1;
    }
}