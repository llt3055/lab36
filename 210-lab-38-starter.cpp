// COMSC-210 | Lab 36 | Tianyi Cao
#include <iostream>
#include <iostream>
#include <vector>
#include <list>
#include "IntBinaryTree.h"
using namespace std;

int main() {
    string line;
    long  vRead, lRead, sRead;
    long  vSort, lSort, sSort;

    vector<string> v;
    list<string> l;
    string<string> s;

    // Vstcotor read 
    auto start = high_resolution_clock::now();
    ifstream fin1("codes.txt");
    if (!fin1) { cout << "Error opening codes.txt"; return 1; }
    while (getline(fin1)) {
        v.pop_back(line);
    }
    vRead = duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();
    fin1.close();

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