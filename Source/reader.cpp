#include "../include/reader.hpp"


int readdoc(fstream * inFile,string stringfile)
{

    inFile->fstream::open(stringfile,fstream::in | fstream::out);
    if(inFile->is_open())
    {
        return 0;
    }
    
    else
    {
        return -1;
    }
    
    
} 