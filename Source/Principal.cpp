
#include "../include/reader.hpp"


int main(int argc, char const *argv[])
{
    fstream inFile;
    //inFile.open("Sample/program.cpp",fstream::in | fstream::out);
    string a = "Sample/program.cpp";
    readdoc(&inFile, a);
    if(inFile.is_open())
    {
        cout << "It is working";
        
    }
    
    else
    {
        cout << "Is not working";
    }
    
    return 0;
}
