#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

const string filename="dataset_9_3.txt";

int HammingDistance(string genome_one,string genome_two);
string genome1;
string genome2;

int main()
{
    string filename("dataset_9_3.txt");
    vector<string> lines;
    string line;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (getline(input_file, line)){
        lines.push_back(line);
    }
    genome1 = lines[0];
    genome2 = lines[1];
    HammingDistance(genome1,genome2);
    
}

int HammingDistance(string Genome1, string Genome2)
{
   int hammingDistanceResult=0;
    for (int i = 0; i<= Genome1.size();i++) {
        if (Genome1[i]!=Genome2[i])
        {
            hammingDistanceResult = hammingDistanceResult + 1 ;
            cout<< hammingDistanceResult<<" : "<<Genome1[i]<< " - " << Genome2[i]<<"\n";
        }  
    }
    return 0;
}


