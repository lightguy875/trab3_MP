
#include "../include/reader.hpp"
#include <iostream>


int main(int argc, char const *argv[])
{
    int inutializedLines = 0;

    int alldocLines = 0;

    int utilizedLines = 0;

    fstream inFile;

    string readFile = "Sample/program.cpp";

    readdoc(&inFile, readFile);

    count_doc_lines(&inFile, alldocLines);

    inFile.clear();

    inFile.seekg(0, ios::beg);

    count_coment(&inFile, inutializedLines);

    utilizedLines = alldocLines - inutializedLines;

    cout << "A quantidade de linhas totais do programa são:" << alldocLines << endl;

    cout << "A quantidade de linhas de código efetivo são:" << utilizedLines << endl;

    cout << "A quantidade de linhas comentadas ou em branco são:" << inutializedLines << endl;

    
    
    return 0;
}
