/**
 * @file reader.cpp
 * @author Luís Eduardo (lightguy875@github.com)
 * @brief 
 * @version 0.1
 * @date 2018-10-06
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "../include/reader.hpp"

/**
 * @brief Função de leitura do arquivo
 * 
 * @param inFile 
 * @param stringfile 
 * @return int 
 */
int readdoc(fstream *inFile, string stringfile)
{
    //@brief Abre o arquivo especificado em stringFile
    inFile->fstream::open(stringfile, fstream::in | fstream::out);
	if (inFile->is_open())
	{
        // O arquivo foi aberto com sucesso
        return 0;
	}

	else
	{
        // O arquivo não foi aberto
        return -1;
	}
}
/**
 * @brief Função que conta todas as linhas do programa
 * 
 * @param inFile 
 * @param line 
 * @return int 
 */
int count_doc_lines(fstream *inFile, int &line)
{
    /**
     * @brief Variáveis para analisar o aquivo
     * 
     */
	line = 0;
	string a;
	if (inFile->is_open())
	{
		while (!inFile->eof())
		{
            // contagem das linhas totais do programa
            getline(*inFile, a);
			line++;
		}
        // retorno de controle se o arquivo foi aberto
        return 0;
	}

	else
	{
        // retorno de controle se o arquivo não foi aberto
        return -1;
	}
}
/**
 * @brief Função que conta todos os comentários do programa juntamente com quebra de linha
 * 
 * @param inFile 
 * @param line 
 * @return int 
 */
int count_coment(fstream *inFile, int &line)
{
    /**
     * @brief variáveis necessárias para analisar os comentários do arquivo
     * 
     */
	line = 0;
	int longComment, shortComment, substringPointer;
	string lineGetter;
    string lineGetterAux;

	if (inFile->is_open())
	{
		while (!inFile->eof())
		{
            getline(*inFile, lineGetter);
            lineGetterAux = lineGetter;
            boost::erase_all(lineGetterAux, " "); // Remove espaços em branco do programa
            // procura se existe uma linha comentada dentro do arquivo principal
            longComment = lineGetter.find("/*");
            shortComment = lineGetter.find("//");
            //exposição dos 4 casos possíveis de se encontrar ou não um comentário

            // 1º caso existe /* e //
            if (longComment != -1 && shortComment != -1)
            {
                // Se // vem antes de /*
                if (shortComment < longComment)
                {
					line++;
                    substringPointer = lineGetter.find("\\");
                    if (substringPointer != -1)
                    {
                        while (substringPointer != -1)
                        {
							line++;
                            getline(*inFile, lineGetter);
                            substringPointer = lineGetter.find("\\");
                        }
					}
				}
                // Se /* vem antes de //
                else if (shortComment > longComment)
                {
					line++;
                    substringPointer = lineGetter.find("*/");
                    if (substringPointer == -1)
                    {
                        while (substringPointer == -1)
                        {
							line++;
                            getline(*inFile, lineGetter);
                            substringPointer = lineGetter.find("*/");
                        }
					}
				}
			}
            // 2º caso existe /* mas não //
            else if (longComment != -1 && shortComment == -1)
            {
				line++;
                substringPointer = lineGetter.find("*/");
                if (substringPointer == -1)
                {
                    while (substringPointer == -1)
                    {
						line++;
                        getline(*inFile, lineGetter);
                        substringPointer = lineGetter.find("*/");
                    }
				}
			}
            // 3º caso existe // mas não /*
            else if (longComment == -1 && shortComment != -1)
            {
				
					line++;
                    // Procura por barra invertidas para encontrar comentários em linhas novas se ja ouve //
                    substringPointer = lineGetter.find("\\");
                    if (substringPointer != -1)
                    {
                        while (substringPointer != -1)
                        {
							line++;
                            getline(*inFile, lineGetter);
                            substringPointer = lineGetter.find("\\");
                        }
					}
				
				
			}
            // 4º caso se existe linhas vazias
            else if (lineGetterAux.size() == 0)
            {
                line++;
            }
        }
        // Retorno de controle se o arquivo foi lido
        return 0;
	}
    else
    {
        // Retorno de controle se o arquivo não foi lido
        return -1;
    }
}
