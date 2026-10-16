#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include "./pugixml-master/src/pugixml.hpp"

int main(int argc, char* argv[])
{
    //パスを変数に代入
    char* inputFilePath = argv[1];

    //もしパスが指定されていない・１つ以上指定している場合は標準入力に対象パスを入力させる
    if (argc != 2)
    {
        while(inputFilePath == nullptr)
        {
            std::cout << "Please provide a valid input file path: ";
            std::cin >> inputFilePath;
        }
    }
    
    //XMLファイルを読み込む
    pugi::xml_document doc_tgt;
    pugi::xml_parse_result result_tgt = doc_tgt.load_file(inputFilePath);

    if(!result_tgt)
    {
        std::cerr << "Error loading XML file: " << result_tgt.description() << std::endl;
        return 1;
    }
}