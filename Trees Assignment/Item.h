#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

# include <bits/stdc++.h>
#include <fstream>

using namespace std;
class Item{
private:
    string itemName;
    string category;
    int price;
public:
    Item(string name , string c , int pr){
        itemName=name;
        category=c;
        price=pr;
    }

    string getName() const{
        return itemName;
    }

    string getCategory() const{
        return category;
    }


    int getPrice() const{
        return price;
    }

    bool operator<(const Item& other)const{
        return itemName<other.itemName;
    }

    bool operator>(const Item& other)const{
        return itemName>other.itemName;
    }

    static bool compareByName(Item& item1, Item& item2) {
        return item1.getName() < item2.getName();
    }
    static bool compareByPrice(Item& item1, Item& item2) {
        return item1.getPrice() < item2.getPrice();
    }

    void print() const{
        cout<<"Item : "<<itemName<<", Category : "<<category<<", Price : "<<price<<endl;
    }

};

struct MAXCompareByName {
    bool operator()(const Item& a, const Item& b)  {
        return (a.getName() > b.getName());
    }
};

struct MAXCompareByPrice {
    bool operator()(const Item& a, const Item& b) {
        return (a.getPrice() > b.getPrice());
    }
};


struct MINCompareByName {
    bool operator()(const Item& a, const Item& b)  {
        return (a.getName() < b.getName());
    }
};

struct MINCompareByPrice {
    bool operator()(const Item& a, const Item& b) {
        return (a.getPrice() < b.getPrice());
    }
};





#endif // ITEM_H_INCLUDED
