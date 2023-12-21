#include "DataLoader.h"
#include <fstream>

vector<string> DataLoader::readDataFromFile(const string &filename)
{
    vector<string> data;
    ifstream file(filename);
    string line;

    while (getline(file, line))
    {
        data.push_back(line);
    }

    return data;
}