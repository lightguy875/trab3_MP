
#include "../include/reader.hpp"
#include <iostream>


int main(int argc, char const *argv[])
{
    fstream inFile;
    //inFile.open("Sample/program.cpp",fstream::in | fstream::out);
    string a = "Sample/program.cpp";
    string b;
    readdoc(&inFile, a);
    getline(inFile, b);
    getline(inFile, b);
    getline(inFile, b);
    printf("%c, %i",b,b);

    /*  if(inFile.is_open())
    {
        cout << "It is working";
        
    }
    
    else
    {
        cout << "Is not working";
    } */
     
    return 0;
}
