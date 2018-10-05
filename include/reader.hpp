#pragma once
#ifndef reader_hpp
#define reader_hpp
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
int readdoc(fstream *,string);
int find_next_comment(fstream *,int&);
int count_doc_lines(fstream *inFile, int &line);
#endif
