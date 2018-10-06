#pragma once
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>

using namespace std;
int readdoc(fstream *,string);
int count_coment(fstream *inFile, int &line);
int count_doc_lines(fstream *inFile, int &line);

