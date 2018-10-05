
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
int count_doc_lines(fstream * inFile,int& line)
{
    line = 0;
    string a;
   if(inFile->is_open())
   {
       while(!inFile->eof())
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
int find_next_comment(fstream * inFile,int& line)
{
    int b,c;
    string a;
    if(inFile->is_open())
    {
        std::getline(*inFile,a);
        b = a.find("/*");
        c = a.find("//");
     
        if(b != -1 || c != -1)
        {
            
            
            return 0;
            
        }

        else
        {
            return -1;
        }


        
    }
    
    else
    {
        cout<< "No file openned" << endl;
        return -1;
    }
    
}