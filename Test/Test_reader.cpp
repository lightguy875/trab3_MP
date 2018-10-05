//#include <catch2/catch.hpp>
#include <iostream>
#include <gtest/gtest.h>
#include "../include/reader.hpp"



TEST(Reading_file_successfully,reading)
{
    fstream inFile;
    string a = "Sample/program.cpp";
    EXPECT_EQ( 0 ,readdoc(&inFile,a));
    EXPECT_EQ(1,inFile.is_open());
} 

int main(int argc, char const *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
} 
