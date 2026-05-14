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
    long  vRead, lRead, sRead;
    long  vSort, lSort, sSort;

    // Vstcotor read 
    auto start = high_resolution_clock::now();
    ifstream fin1("codes.txt");
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
        s.insert(line); 
    }
    fin3.close();
    sRead = duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();

    // Vector sort
    start = high_resolution_clock::now();
    sort(v.begin(), v.end());
    vSort = duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();

    // List sort
    start = high_resolution_clock::now();
    lSort = duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();
    l.sort();

    // Set sort
    sSort = -1;
    
    return 0;
}