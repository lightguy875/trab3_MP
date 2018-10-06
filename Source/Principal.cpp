/**
 * @file Principal.cpp
 * @author Luís Eduardo (lightguy875@github.com)
 * @brief Arquivo principal do código
 * @version 0.1
 * @date 2018-10-06
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "../include/reader.hpp"
#include <iostream>

/**
 * @brief Função principal do programa 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    int inutializedLines = 0;

    int alldocLines = 0;

    int utilizedLines = 0;

    fstream inFile;
    // Definição do arquivo a ser lido
    string readFile = "Sample/program.cpp";
    // Leitura do arquivo
    readdoc(&inFile, readFile);

    count_doc_lines(&inFile, alldocLines);
    // Retorno para a primeira linha do arquivo principal
    inFile.clear();

    inFile.seekg(0, ios::beg);
    // Contagem de linhas comentadas ou em branco
    count_coment(&inFile, inutializedLines);

    utilizedLines = alldocLines - inutializedLines;
    // Expoxição de dados coletados
    cout << "A quantidade de linhas totais do programa são:" << alldocLines << endl;

    cout << "A quantidade de linhas de código efetivo são:" << utilizedLines << endl;

    cout << "A quantidade de linhas comentadas ou em branco são:" << inutializedLines << endl;

    return 0;
}
