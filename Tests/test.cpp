#include "../funkcijos.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test{
    public:
        functions ob;

        ClassDeclaration()
        {

        }

    };
}
TEST_F(ClassDeclaration, RemovePunctuation)
{
    string text= "1,1,1,1,asd'a'";
    ob.RemovePunctuation(text);
    EXPECT_EQ(text,"1111asda");
     text= "ar, tai, a.'''q";
    ob.RemovePunctuation(text);
    EXPECT_EQ(text,"ar tai aq");



}

TEST_F(ClassDeclaration, TransformStringToLowerCase)
{
    string text = "ABCD";
    ob.TransformStringToLowerCase(text);
    EXPECT_EQ(text,"abcd");
    text = "ABcCDc";
    ob.TransformStringToLowerCase(text);
    EXPECT_EQ(text,"abccdc");

}

TEST_F(ClassDeclaration, Test3)
{
    std::map<string, size_t> W;
    std::map<string, std::vector<int>> L;
    ob.WordCounter(W, L);
    


}


