
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
    int line;
    string a = "Sample/program.cpp";
    EXPECT_EQ(0, readdoc(&inFile, a));
    EXPECT_EQ(1, inFile.is_open());
    EXPECT_NE(0,count_doc_lines(&inFile,line));
}

TEST(find_comment_in_a_file,commenttary)
{
    int line;
    fstream inFile;
    string a = "Sample/program.cpp";
    readdoc(&inFile,a);
    EXPECT_EQ(-1, find_next_comment(&inFile, line));
}



int main(int argc, char const *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
} 
