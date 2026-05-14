// COMSC-210 | Lab 36 | Tianyi Cao
#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
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
    set<string> s; 

    string line;
    long long vRead, lRead, sRead;
    long long vSort, lSort, sSort;
    long long vIns, lIns, sIns;

    // Vstcotor read 
    auto start = high_resolution_clock::now();
    ifstream fin1("codes.txt");
    if (!fin1) {
        cout << "Error: Cannot open codes.txt. Make sure it is in the same folder." << endl;
        return 1;
    }
    if (!fin1) { cout << "Error opening codes.txt"; return 1; }
    while (getline(fin1, line)) {
        v.push_back(line);
    }
    fin1.close();
    vRead = duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();

    // List read
    start = high_resolution_clock::now();
    ifstream fin2("codes.txt");
    while (getline(fin2, line)) {
        l.push_back(line);
    }
    fin2.close();
    lRead = duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();

    // Set read
    start = high_resolution_clock::now();
    ifstream fin3("codes.txt");
    while (getline(fin3, line)) {
        s.insert(line); // BST insert
    }
    fin3.close();
    sRead = duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();

    // Vector sort
    start = high_resolution_clock::now();
    sort(v.begin(), v.end());
    vSort = duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();

    // List sort
    start = high_resolution_clock::now();
    l.sort();
    lSort = duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();

    // Set sort
    sSort = -1;

    // Vector insert
    start = high_resolution_clock::now();
    v.insert(v.begin() + v.size() / 2, "TESTCODE");
    vIns = duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();

    // 2. List Insert
    start = high_resolution_clock::now();
    auto itL = l.begin();
    advance(itL, l.size() / 2); 
    l.insert(itL, "TESTCODE");
    lIns = duration_cast<nanoseconds>(high_resolution_clock::now() - start + 1).count();

    // 3. Set (BST) Insert
    start = high_resolution_clock::now();
    s.insert("TESTCODE"); 
    sIns = duration_cast<nanoseconds>(high_resolution_clock::now() - start + 1).count();
    
    // Output results
    cout << left << setw(15) << "Operation" << setw(15) << "Vector" << setw(15) << "List" << setw(15) << "Set (BST)" << endl;
    cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;

    cout << left << setw(15) << "Read" 
         << setw(15) << vRead 
         << setw(15) << lRead 
         << setw(15) << sRead << endl;
         
    cout << left << setw(15) << "Sort" 
         << setw(15) << vSort 
         << setw(15) << lSort 
         << setw(15) << sSort << endl;

    cout << left << setw(15) << "Insert" 
        << setw(15) << vIns 
        << setw(15) << lIns 
        << setw(15) << sIns << endl;

    return 0;
}