#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

const string filename="dataset_2_13-1.txt";

vector<char> ReverseComplement(string fileName);

int main()
{
    vector<char> reverseComplement = ReverseComplement(filename);
    for (char frequentKMer: reverseComplement)
    {cout << frequentKMer; }
}

vector<char> ReverseComplement(string fileName)
{
    vector<char> complement;

    FILE* input_file = fopen(fileName.c_str(), "r");

    char c;
    while ((c = fgetc(input_file)) != EOF) {
        char nucleotide = c;
       switch (nucleotide)
       {
       case 'A':
            complement.insert(complement.begin(),'T');
            break;       
       
       case 'G':
            complement.insert(complement.begin(),'C');
            break;

        case 'C':
            complement.insert(complement.begin(),'G');
            break;

        case 'T':
            complement.insert(complement.begin(),'A');
            break; 
       }
    }
    cout << endl;
    fclose(input_file);

    return complement;
}
