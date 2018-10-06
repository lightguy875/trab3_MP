
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
	line = 0;
	int b, c, l;
	string a;
	if (inFile->is_open())
	{
		while (!inFile->eof())
		{
			getline(*inFile, a);
			b = a.find("/*");
			c = a.find("//");

			if (b != -1 && c != -1)
			{
				if (c < b)
				{
					line++;
					l = a.find("\\");
					if (l != -1)
					{
						while (l != -1 )
						{
							line++;
							getline(*inFile, a);
							l = a.find("\\");
						}
					}
				}
				else if (c > b)
				{
					line++;
					l = a.find("*/");
					if (l == -1)
					{
						while (l == -1)
						{
							line++;
							getline(*inFile, a);
                            l = a.find("*/");
						}
					}
				}
			}
			else if (b != -1 && c == -1)
			{
				line++;
				l = a.find("*/");
				if (l == -1)
				{
					while (l == -1)
					{
						line++;
						getline(*inFile, a);
                        l = a.find("*/");
					}
				}
			}

			else if (b == -1 && c != -1)
			{
				
					line++;
					l = a.find("\\");
					if (l != -1)
					{
						while (l != -1 )
						{
							line++;
							getline(*inFile, a);
							l = a.find("\\");
						}
					}
				
				
			}
            else if (a.size() == 0)
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
