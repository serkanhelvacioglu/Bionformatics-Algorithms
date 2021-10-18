/*           Frequent Word Problem           */
//    Input: A string Text and an integer k.
//    Output: All most frequent k-mers in Text.
/* It reads txt file, takes text and integer k and returns the most frequent k-mers.*/


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

const string filename="dataset_2_13-1.txt";



map<string, int> FrequencyTable(string Text, int k);
int MaxMap(map<string, int> Map);
vector<string> BetterFrequentWords(string Text,int k);


int main()
{
    
    ifstream file(filename);
    string pattern;
    string k_mer;
    getline(file,pattern);
    getline(file,k_mer);
    int k_merInt=stoi(k_mer);
    
    vector<string> theMostFrequentKMers;
    theMostFrequentKMers = BetterFrequentWords(pattern,k_merInt);

    for (string frequentKMer: theMostFrequentKMers)
    {cout << frequentKMer << ' '; }
}

map<string, int> FrequencyTable(string Text, int k)
{
    map<string, int> freqMap;   
    int n = Text.length();
    for (int i = 0; i < n-k+1; i++)
    {
        string pattern = Text.substr(i,k);
        if (freqMap.count(pattern)<=1)
        {
            freqMap[pattern]+=1;
        }
        else
        {
            freqMap.insert({pattern,1});
        }
    }
    return freqMap;
}

int MaxMap(map<string, int> Map)
{
    map<string, int>::iterator itr;
    int temp=0;
    for (itr = Map.begin(); itr != Map.end();++itr) {
        if (itr->second>temp)
        {
            temp=itr->second;
        }  
    }
    return temp;
}

vector<string> BetterFrequentWords(string Text,int k)
{
    vector<string> FrequentPatterns;
    map<string, int>::iterator itr;
    map<string, int> freqMap = FrequencyTable(Text, k);
    int max = MaxMap(freqMap);
    for (itr=freqMap.begin(); itr !=freqMap.end(); ++itr)
    {
        if (itr->second==max)
        {
            FrequentPatterns.push_back(itr->first);
        }
    }
    return FrequentPatterns;
    
}
