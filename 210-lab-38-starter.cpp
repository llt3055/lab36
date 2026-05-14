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

    int choice;
    string entry;

    do {
        cout << "\n--- Binary Tree Management Menu ---" << endl;
        cout << "1. Add a record" << endl;
        cout << "2. Delete a record" << endl;
        cout << "3. Search for a record" << endl;
        cout << "4. Modify a record" << endl;
        cout << "5. Display all records (In-Order)" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;


        
    } while (choice = 6);

    return 0;
}