#ifndef DataLoader_H
#define DataLoader_H

#include <string>
#include <vector>

using namespace std;

class DataLoader
{
public:
    static vector<string> readDataFromFile(const string &filename);
};

#endif