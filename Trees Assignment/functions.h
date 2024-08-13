#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Item.h"
#include "BST.h"
using namespace std;


vector<Item> readItemsFromFile(const string& filename){
    ifstream file(filename);
    vector<Item> items;
    string line;
    int numOfItems;

    if (file.is_open()) {
        getline(file, line);
        numOfItems = stoi(line);

        while (getline(file, line)) {
            string name = line;
            getline(file, line);
            string category = line;
            getline(file, line);
            int price = stoi(line);
            items.push_back(Item(name,category , price));
        }
    }
    else{
        cerr << "Error opening file." << endl;
    }
    return items;
}


#endif // FUNCTIONS_H_INCLUDED
