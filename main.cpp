#include "BST.h"
#include "AVL.h"
#include "DataLoader.h"
#include "Timer.h"
#include <iostream>
#include <fstream>

void compareTrees(const vector<string> &data, const string &treeType, ofstream &outputFile)
{
    Timer timer;
    if (treeType == "BST")
    {
        BST bst;
        timer.start();
        for (int i = 0; i < data.size(); ++i)
        {
            bst.insert(data[i]);
        }
        timer.stop();
        outputFile << "BST insertion time: " << timer.elapsedMilliseconds() << " ms\n";

        timer.start();
        for (int i = 0; i < data.size(); ++i)
        {
            bst.search(data[i]);
        }
        timer.stop();
        outputFile << "BST search time: " << timer.elapsedMilliseconds() << " ms\n";
    }
    else if (treeType == "AVL")
    {
        AVL avl;
        timer.start();
        for (int i = 0; i < data.size(); ++i)
        {
            avl.insert(data[i]);
        }
        timer.stop();
        outputFile << "AVL insertion time: " << timer.elapsedMilliseconds() << " ms\n";

        timer.start();
        for (int i = 0; i < data.size(); ++i)
        {
            avl.search(data[i]);
        }
        timer.stop();
        outputFile << "AVL search time: " << timer.elapsedMilliseconds() << " ms\n";
    }
}

int main()
{
    vector<string> randomData = DataLoader::readDataFromFile("data/random_data.txt");
    vector<string> orderedData = DataLoader::readDataFromFile("data/ordered_data.txt");
    vector<string> nearlyOrderedData = DataLoader::readDataFromFile("data/nearly_ordered_data.txt");

    ofstream outputFile("data/results.txt");

    outputFile << "Random data size: " << randomData.size() << "\n";
    outputFile << "Ordered data size: " << orderedData.size() << "\n";
    outputFile << "Nearly ordered data size: " << nearlyOrderedData.size() << "\n";

    outputFile << "\nComparing with random data\n";
    compareTrees(randomData, "BST", outputFile);
    compareTrees(randomData, "AVL", outputFile);

    outputFile << "\nComparing with ordered data\n";
    compareTrees(orderedData, "BST", outputFile);
    compareTrees(orderedData, "AVL", outputFile);

    outputFile << "\nComparing with nearly ordered data\n";
    compareTrees(nearlyOrderedData, "BST", outputFile);
    compareTrees(nearlyOrderedData, "AVL", outputFile);

    outputFile.close();

    return 0;
}