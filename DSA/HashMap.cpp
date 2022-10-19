//********************************************************************************************************
//
// Purpose: Set up a Hash Table
//
// Written By: Xhovani Mali
//
// Compiler: G++
//
// Description:  Basically, a HashMap allows you to store items with identifiers. 
//               They are stored in a table format with the identifier being hashed using a hashing algorithm. 
//               Typically they are more efficient to retrieve items than search trees etc
//
//********************************************************************************************************

#include <iostream>
#include <vector>
#include <list>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;


class HashTable {
    private: 
        static const int hashGroups = 10;
        list<pair<int, string>> table[hashGroups]; // List 1, Index 0, List 2, Index 1...
    
    public: 
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};

//****************************************************
// Function: isEmpty
//
// Purpose: To show the heading for screen output.
//
//****************************************************
bool HashTable::isEmpty() const {
    int sum{};
    for (int i{}; i < hashGroups; i++){
        sum += table[i].size();
    }
    
    if (!sum) {
       return true; 
    }
    return false;
}

//****************************************************
// Function: hashFunction
//
// Purpose: Key: 905, in return, this function will spit out 5
//
//****************************************************
int HashTable::hashFunction(int key) {
    return key % hashGroups;
}

//****************************************************
// Function: insertItem
//
// Purpose: 
//
//****************************************************
void HashTable::insertItem(int key, string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;

    for (; bItr != end(cell); bItr++){
        if (bItr->first == key){
            keyExists = true;
            bItr->second = value;
            cout << "[WARNING] Key exists. Value replaced." << "\n";
            break;
        }
    }

    if (!keyExists){
        cell.emplace_back(key, value);
    }

    return;
}

//****************************************************
// Function: removeItem
//
// Purpose: 
//
//****************************************************
void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;

    for (; bItr != end(cell); bItr++){
        if (bItr->first == key){
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "[INFO] Item removed." << "\n";
            break;
        }
    }

    if (!keyExists){
        cout << "[WARNING] Key not found. Pair not removed." << "\n";
    }
    return

}

//****************************************************
// Function: searchTable
//
// Purpose: To show the heading for screen output.
//
//****************************************************
string HashTable::searchTable(int key) {

}

//****************************************************
// Function: printTable
//
// Purpose: To show the heading for screen output.
//
//****************************************************
void HashTable::printTable() {

}