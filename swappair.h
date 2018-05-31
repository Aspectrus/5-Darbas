

#ifndef INC_5_DARBAS_SWAPPAIR_H
#define INC_5_DARBAS_SWAPPAIR_H
#include <iostream>
#include <iomanip>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
using std::string;

std::pair<size_t, string> swap_pair (const std::pair<string, size_t> p)
{
    return std::make_pair(p.second, p.first);
}

void WordSortingByFrequency(std::map<string, size_t> Words, std::multimap<size_t, string> &SortedWords)
{
    std::transform(Words.begin(),
                   Words.end(),
                   std::inserter(SortedWords, SortedWords.begin()),
                   swap_pair);

}
#endif //INC_5_DARBAS_SWAPPAIR_H
