
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

	inFile->fstream::open(stringfile, fstream::in | fstream::out);
	if (inFile->is_open())
	{
		return 0;
	}

	else
	{
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
	line = 0;
	string a;
	if (inFile->is_open())
	{
		while (!inFile->eof())
		{
			getline(*inFile, a);
			line++;
		}

		return 0;
	}

	else
	{
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
            boost::erase_all(lineGetterAux, " "); /// @brief Remove espaços em branco do programa
            ///@brief procura se existe uma linha comentada dentro do arquivo principal
            longComment = lineGetter.find("/*");
            shortComment = lineGetter.find("//");
            /// exposição dos 4 casos possíveis de se encontrar ou não um comentário

            /// 1º caso existe /* e //
            if (longComment != -1 && shortComment != -1)
            {
                /// Se // vem antes de /*
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
                /// Se /* vem antes de //
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
            /// 2º caso existe /* mas não //
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
            /// 3º caso existe // mas não /*
            else if (longComment == -1 && shortComment != -1)
            {
				
					line++;
                    // Procura por barra invertidas para encontrar comentários em linhas novas
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
            else if (lineGetterAux.size() == 0)
            {
                line++;
            }
        }
        
        return 0;
	}
    else
    {
                return -1;
    }
}
