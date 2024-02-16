#include <iostream>
#include <Windows.h>
#include <fstream>
#include "BinaryTree.h"
using namespace std;

int main() {
	BinaryTree tree;

    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the input file!" << std::endl;
        return 1;
    }

    int value;
    while (inputFile >> value) {
        tree.Insert(value);
    }

    inputFile.close();

	NodeTree* maxSubtreeRoot = tree.FindMaxSubtree();
	if (maxSubtreeRoot != nullptr)
		std::cout << "Root value of the largest subtree: " << maxSubtreeRoot->info << std::endl;


	return 0;
}