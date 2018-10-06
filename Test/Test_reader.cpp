
#include "../include/reader.hpp"
#include <gtest/gtest.h>

    TEST(Reading_file_successfully, reading)
{
    fstream inFile;
    string a = "Sample/program.cpp";
    EXPECT_EQ( 0 ,readdoc(&inFile,a));
    EXPECT_EQ(1,inFile.is_open());
} 

TEST(GET_ALL_DOC_LINES,all_lines_count)
{
    fstream inFile;
    int line = 0;
    string a = "Sample/program.cpp";
    EXPECT_EQ(-1, count_doc_lines(&inFile, line));
    EXPECT_EQ(0, readdoc(&inFile, a));
    EXPECT_EQ(1, inFile.is_open());
    EXPECT_NE(-1,count_doc_lines(&inFile,line));
    EXPECT_NE(0,line);
}

 TEST(find_comment_in_a_file,commenttary)
{
    int line = 0;
    fstream inFile;
    string a = "Sample/program.cpp";
    EXPECT_EQ(-1,count_coment(&inFile, line));
    readdoc(&inFile,a);
    EXPECT_NE(-1,count_coment(&inFile,line));
}
 


int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
} 
