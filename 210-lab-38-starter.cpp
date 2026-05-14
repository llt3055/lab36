// COMSC-210 | Lab 36 | Tianyi Cao
#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "IntBinaryTree.h" 

using namespace std;
using namespace std::chrono;

int main() {
    vector<string> v;
    list<string> l;
    IntBinaryTree bst;

    string line;
    long long vRead, lRead, bstRead;
    
    // 1. Read data from file into vector, list, and BST
    ifstream fin1("codes.txt");
    if (!fin) { cout << "Error opening codes.txt"; return 1; }

    // Vector read 
    auto start = high_resolution_clock::now();
    while (getline(fin, line)) {
        bst.insertNode(line);
    }
    fin1.close();
    bstRead = duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();

    auto start = high_resolution_clock::now();
    while (getline(fin, line)) {
        bst.insertNode(line);
    }
    fin.close();
    bstRead = duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();

    return 0;
}