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
        l.pop_back(line);
    }
    lRead = duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();
    fin2.close();

    // Set read
    start = high_resolution_clock::now();
    ifstream fin3("codes.txt");
    while (getline(fin3)) {
        s.insert(line);
    }
    sRead = duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();
    fin3.close();

    return 0;
}