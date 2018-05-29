#include <iostream>
#include <iomanip>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

using std::string;
using std::cout;

void checkfile(std::string FileName)
{
    std::ifstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        file.open(FileName);
    }
    catch (std::ios_base::failure &fail) {
        cout << "Exception opening/reading file";
    }
    file.close();
}

void TransformStringToLowerCase(string &word)
{
    transform(word.begin(), word.end(), word.begin(), ::tolower);
}

void RemovePunctuation(string &line)
{
    string result;
    std::remove_copy_if(line.begin(), line.end(),
                        std::back_inserter(result),
                        std::ptr_fun<int, int>(&std::ispunct)
    );
    line=result;
}
int MaxWordSize=0;

void WordCounter (std::map<string, size_t> &Words, std::map<string, std::vector<int>> &LineNumber)
{
    std::ifstream inputfile("text.txt");
    int TempLineCount=1;
    int RepeatingLine;
    string TempLine;

    while(std::getline (inputfile, TempLine))
    {

        RemovePunctuation(TempLine);
        TransformStringToLowerCase(TempLine);
        std::istringstream LineStream (TempLine);
        string InputWord;
        while(LineStream>>InputWord)
        {


            if (Words.find(InputWord) == Words.end())
            {
                Words[InputWord] = 1;
                LineNumber[InputWord].push_back(TempLineCount);
            }
            else
            {
                Words[InputWord]++;
                string temp=' '+std::to_string(TempLineCount);
                if(*(LineNumber[InputWord].end()-1)!=TempLineCount)
                    LineNumber[InputWord].push_back(TempLineCount);

                if(MaxWordSize<InputWord.length())
                    MaxWordSize=InputWord.length();
            }


        }
        TempLineCount++;
    }
    inputfile.close();
}

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

void CreateOutputFile(std::multimap<size_t, string> Words, std::map<string, std::vector<int>> LineNumber)
{
    std::ofstream output("result.txt");
    output<<"Žodis "<<std::setw(30)<<"Pasikartojimų kiekis"<<std::setw(14)<<"eilutės\n";
    for(const auto it: Words)
    {
        if(it.first>1)
        {

            output<<std::left<<std::setw(15)<<it.second<<std::setw(25)<<it.first<<LineNumber[it.second][0];
            for( auto i=1; i<LineNumber[it.second].size(); i++)
            {
                output<<", "<<LineNumber[it.second][i];
            }
            output<<'\n';

        }

    }

}

int main() {
    checkfile("text.txt");
    std::map<string, size_t> Words;
    std::map<string, std::vector<int>> LineNumber;
    std::multimap<size_t, string> SortedWords;

WordCounter(Words, LineNumber);
WordSortingByFrequency(Words, SortedWords);
CreateOutputFile(SortedWords, LineNumber);



    return 0;
}