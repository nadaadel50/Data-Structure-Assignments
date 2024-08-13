#include <bits/stdc++.h>
#define ll long long
#define Maya() ios_base::sync_with_stdio(false),cin.tie(NULL);
#define el "\n"
#define testcase int t; cin>>t; while(t--)

#include"functions.h"
#include "Item.h"
#include"MaxHeape.h"
#include "MinHeape.h"
#include "BST.h"
using namespace std;


int main() {

    cout << "Hi, Please Write Name of Items File" << el;
    string name; cin >> name;
    vector <Item > v = readItemsFromFile(name);
    cout << "Select Tree:" << el << "1. BST" <<el << "2. AVL" << el <<"3. Heap" << el;
    int n; cin >> n;
    switch (n){
        case 1: {
            BST bst;
            for(int i = 0; i < v.size(); i++){
                bst.insertItem(v[i]);
            }
            int x = 0;
            while (x != 8) {
                cout << endl;
                cout << "Select from List: " << el;
                cout << "1. Add item" << el << "2. Delete item" << el << "3. Display BST" <<
                      el << "4. Display items ASC by names" <<
                     el << "5. Display items DES by names" << el << "6. Display items ASC by prices" << el
                     << "7. Display items DES by prices" << el << "8. Exit" << el;
                cin >> x;
                string NameOfItem, categoryOfItem;
                int priceOfItem;
                if (x == 1) {
                    cout << "Enter Name of the item:" << endl;
                    cin >> NameOfItem;
                    cout << "Enter Category of the item:" << endl;
                    cin >> categoryOfItem;
                    cout << "Enter price of the item:" << endl;
                    cin >> priceOfItem;
                    Item newItem(NameOfItem, categoryOfItem, priceOfItem);
                    bst.insertItem(newItem);
                } else if (x == 2) {
                    cout << "Enter Name of the item:" << endl;
                    cin >> NameOfItem;
                    cout << "Enter Category of the item:" << endl;
                    cin >> categoryOfItem;
                    cout << "Enter price of the item:" << endl;
                    cin >> priceOfItem;
                    Item newItem(NameOfItem, categoryOfItem, priceOfItem);
                    bst.deleteItem(bst.getRoot(), newItem);
                } else if (x == 3) {
                    bst.displaypreOrder(bst.getRoot());
                    cout << endl;
                } else if (x == 4) {
                    bst.displayAscByName(bst.getRoot());
                } else if (x == 5) {
                    bst.displayDesByName(bst.getRoot());
                } else if (x == 6) {
                    bst.displayAscByPrice(bst.getRoot());
                } else if (x == 7) {
                    bst.displayDesByPrice(bst.getRoot());
                }
                else{
                    break;
                }

            }
        }
     case 2:{
           AVLTree avl;
            int chosen;
            string name,category;
            int price;
            for(int i = 0; i < v.size(); i++){
                avl.insert(v[i]);}
            do{
                cout<<"Welcome to AVL Menu! \n";
                cout << "1. Add item\n2. Remove item\n3. Display items\n4. Display sorted by name (ascending)\n";
                cout << "5. Display sorted by name (descending)\n6. Display sorted by price (ascending)\n";
                cout << "7. Display sorted by price (descending)\n8. Back to main menu\n";
                cout << "Choose a number: ";
                cin>>chosen;



                switch (chosen) {
                    case 1:

                        cout << "Enter Name of the item:" << endl;
                        cin >> name;
                        cout << "Enter Category of the item:" << endl;
                        cin >> category;
                        cout << "Enter price of the item:" << endl;
                        cin >> price;
                        avl.insert(Item(name,category,price));



                        break;
                    case 2:
                        cout<<"Enter the name of the Item : ";
                        getline(cin,name);
                        cout<<"Enter the category of the Item : ";
                        getline(cin,category);
                        cout<<"Enter the price of the Item : ";
                        cin>>price;
                        cin.ignore();
                        avl.DeleteCall(Item(name,category,price));
                        break;
                    case 3:avl.displayInorder(avl.get_root());
                        break;
                    case 4:avl.displayAscByName(avl.get_root());
                        break;
                    case 5:avl.displayDesByName(avl.get_root());
                        break;
                    case 6:avl.displayAscByPrice(avl.get_root());
                        break;
                    case 7:avl.displayDesByPrice(avl.get_root());
                        break;
                }
            } while (chosen != 8);
            break;
        }


        }
    case 3:{
            cout << "Select Sort:" << el << "1. ascending by name" <<el  << "2. ascending by price" <<el << "3. descending by name" <<  el << "4. descending by price" <<  el;
            int x; cin >> x;
            if(x == 1){
                 MaxHeap<Item,MAXCompareByName> maxHeap(v,MAXCompareByName());
                 cout << "Select from List: " << el;
                    cout << "1. add item." << el << "2. delete item" << el << "3. sort" <<el<< "4. print" << el;
                    int y ;
                    while(cin >> y){
                        if(y == 1){
                            string name, category; int price;
                            cin >> name >> category >> price ;
                            maxHeap.Insert(Item(name,category, price));
                        }
                        else if(y == 2){
                            maxHeap.Delete();
                        }
                        else if(y == 3){
                            maxHeap.sort();
                        }
                        else maxHeap.print();
                    }
            }
            else if(x == 2){
                MaxHeap<Item,MAXCompareByPrice> maxHeap(v,MAXCompareByPrice());
                cout << "Select from List: " << el;
                cout << "1. add item." << el << "2. delete item" << el << "3. sort" <<el <<  "4. print" << el;
                int y ;
                while(cin >> y){
                    if(y == 1){
                        string name, category; int price;
                        cin >> name >> category >> price ;
                        maxHeap.Insert(Item(name,category, price));
                    }
                    else if(y == 2){
                        maxHeap.Delete();
                    }
                    else if(y == 3){
                        maxHeap.sort();
                    }
                    else maxHeap.print();
                }
            }
        
     else if (x == 3) {
                MinHeap<Item, MAXCompareByName> minHeap(v, MAXCompareByName());
                cout << "Select from List: " << el;
                cout << "1. add item." << el << "2. delete item" << el << "3. sort" << el << "4. print" << el;
                int y;
                while (cin >> y) {
                    if (y == 1) {
                        string name, category; int price;
                        cout << "Enter item (name category price): ";
                        cin >> name >> category >> price;
                        minHeap.Insert(Item(name, category, price));
                    } else if (y == 2) {
                        minHeap.Delete();
                    } else if (y == 3) {
                        minHeap.sort();
                    } else if (y == 4) {
                        minHeap.print();
                    }
                }
            } else if (x == 4) {
                MinHeap<Item, MAXCompareByPrice> minHeap(v, MAXCompareByPrice());
                cout << "Select from List: " << el;
                cout << "1. add item." << el << "2. delete item" << el << "3. sort" << el << "4. print" << el;
                int y;
                while (cin >> y) {
                    if (y == 1) {
                        string name, category; int price;
                        cout << "Enter item (name category price): ";
                        cin >> name >> category >> price;
                        minHeap.Insert(Item(name, category, price));
                    } else if (y == 2) {
                        minHeap.Delete();
                    } else if (y == 3) {
                        minHeap.sort();
                    } else if (y == 4) {
                        minHeap.print();
                    }
                }
            }
    break;
}


    }

    /*
    Item item1("water","drink", 7);
    Item item2("apple","fruite", 13);
    Item item3("cake","sweet",10);
    MaxHeap<Item,MAXCompareByName> maxHeap({item1, item2, item3},MAXCompareByName());
    maxHeap.sort();
    maxHeap.print();

    MaxHeap<Item,MAXCompareByPrice> Heap({item1, item2, item3},MAXCompareByPrice());
    Heap.sort();
    Heap.print();
*/
}
