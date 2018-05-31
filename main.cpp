
#include "swappair.h"
#include "funkcijos.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using std::string;
using std::cout;


int main(int argc, char* argv[]) {

testing::InitGoogleTest(&argc, argv);
RUN_ALL_TESTS();
    functions obj;
    obj.checkfile("text.txt");
    std::map<string, size_t> Words;
    std::map<string, std::vector<int>> LineNumber;
    std::multimap<size_t, string> SortedWords;

    obj.WordCounter(Words, LineNumber);
    WordSortingByFrequency(Words, SortedWords);
    obj.CreateOutputFile(SortedWords, LineNumber);



    return 0;
}