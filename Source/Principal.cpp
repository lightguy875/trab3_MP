
#include "../include/reader.hpp"
#include <iostream>


int main(int argc, char const *argv[])
{
    int inutialized_lines = 0;
    int all_doc_files = 0;
    int utilized_lines = 0;
    fstream inFile;
    string a = "Sample/program.cpp";
    string b;
    readdoc(&inFile, a);
    count_doc_lines(&inFile, all_doc_files);
    inFile.clear();
    inFile.seekg(0, ios::beg);
    count_coment(&inFile,inutialized_lines);
    utilized_lines = all_doc_files - inutialized_lines;
    cout << "A quantidade de linhas de código efetivo são:" << utilized_lines << endl; 
     
    return 0;
}
