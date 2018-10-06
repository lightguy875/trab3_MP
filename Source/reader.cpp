
#include "../include/reader.hpp"

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
						while (l != -1 && !inFile->eof())
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
					l = a.find("*\\");
					if (l == -1)
					{
						while (l == -1 && !inFile->eof())
						{
							line++;
							getline(*inFile, a);
						}
					}
				}
			}
			else if (b != -1 && c == -1)
			{
				line++;
				l = a.find("*\\");
				if (l == -1)
				{
					while (l == -1 && !inFile->eof())
					{
						line++;
						getline(*inFile, a);
					}
				}
			}

			else if (b == -1 && c != -1)
			{
				if (c < b)
				{
					line++;
					l = a.find("\\");
					if (l != -1)
					{
						while (l != -1 && !inFile->eof())
						{
							line++;
							getline(*inFile, a);
							l = a.find("\\");
						}
					}
				}
				else if (a == "\n")
				{
					line++;
				}
			}
		}
        return l;
	}
    else
    {
        cout << "No file openned" << endl;
        return -1;
    }
}
