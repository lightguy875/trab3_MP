/**
 * @file reader.hpp
 * @author Luís Eduardo (lightguy875@github.com)
 * @brief Arquivo de includes
 * @version 0.1
 * @date 2018-10-06
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>

using namespace std;
/**
 * @brief Função de leitura de arquivo
 * 
 * @param inFile 
 * @param readFile 
 * @return int 
 */
int readdoc(fstream *inFile,string readFile);

/**
 * @brief Contagem de comentários ou linhas em branco
 * 
 * @param inFile 
 * @param line 
 * @return int 
 */
int count_coment(fstream *inFile, int &line);

/**
 * @brief Contagem de todas as linhas do documento
 * 
 * @param inFile 
 * @param line 
 * @return int 
 */
int count_doc_lines(fstream *inFile, int &line);

