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
    if (!fin1) { cout << "Error opening codes.txt"; return 1; }

    // Vector read 
    auto start = high_resolution_clock::now();
    ifstream fin1("codes.txt");
    if (!fin1) { cout << "Error opening codes.txt"; return 1; }
    while (getline(fin1, line)) {
        v.push_back(line);
    }
    fin1.close();
    bstRead = duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();

    ifstream fin2("codes.txt");
    while (getline(fin2, line)) {
        l.push_back(line);
    }
    fin2.close();
    lRead = duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();

    // BST read
    ifstream fin3("codes.txt");
    start = high_resolution_clock::now();
    while (getline(fin3, line)) {
        bst.insertNode(line);
    }
    fin3.close();
    bstRead = duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();

 



    cout << "\n Milestone 3: Displaying BST Contents (In-Order)" << endl;
    bst.displayInOrder(); 
    cout << "End of BST Output\n" << endl;
    
    // Output results
    cout << left << setw(15) << "Operation" << setw(15) << "Vector" << setw(15) << "List" << setw(15) << "BST (Custom)"<< endl;
    cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;

    cout << left << setw(15) << "Read" 
         << setw(15) << vRead 
         << setw(15) << lRead bstRead = duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();
         
         << setw(15) << bstRead << endl;
         
    cout << left << setw(15) << "Sort" 
         << setw(15) << vSort 
         << setw(15) << lSort 
         << setw(15) << bstSort << endl;

    return 0;
}