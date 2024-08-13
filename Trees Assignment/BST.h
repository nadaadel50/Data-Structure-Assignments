#ifndef TREES_ASSIGNMENT_BST_H
#define TREES_ASSIGNMENT_BST_H
#include "Item.h"

#include <bits/stdc++.h>


class Node{
private:
    Item data;
    Node *left;
    Node *right;
public:
    Node(const Item &data): data(data), left(nullptr), right(nullptr){};
    Item getData(){
        return data;
    };
    Node* getLeft() const {
        return left;
    }
    Node* getRight() const {
        return right;
    }
    void setData(Item item){
        data = item;
    }
    void setLeft(Node* node) {
        left = node;
    }
    void setRight(Node* node) {
        right = node;
    }
};


class BST{
private:
    Node *root;
public:
    BST(){
        root = nullptr;
    }
    Node *getRoot(){
        return root;
    }
    void insertItem(Item item){
        Node *newNode = new Node(item);
        // If tree is empty
        if(root == nullptr){
            root = new Node(item);
            return;
        }
        Node *parent = nullptr;
        Node *current = root;
        while(current != nullptr){
            parent = current;
            if(item.getPrice() < current->getData().getPrice()){
                current = current->getLeft();
            }
            else{
                current = current->getRight();
            }
        }
        if(item.getPrice() < parent->getData().getPrice()){
            parent->setLeft(newNode);
            cout << "Node has been inserted successfully!" << endl;
        }
        else{
            parent->setRight(newNode);
            cout << "Node has been inserted successfully!" << endl;
        }
    }

    Node* deleteItem(Node* node,Item item){
        // Base Case
        if(node == nullptr){
            return node;
        }
        // If the item to be deleted is smaller than root then it is in the left subtree
        if(node->getData().getPrice() > item.getPrice()){
            node->setLeft(deleteItem(node->getLeft(), item));
        }
            // Else if the item to be deleted is greater then it is in the right subtree
        else if(node->getData().getPrice() < item.getPrice()){
            node->setRight(deleteItem(node->getRight(), item));
        }
            // Else if it is same as root, then we will delete it, in case it has one child or no children
        else {
            if (node->getData().getName() == item.getName() && node->getData().getCategory() == item.getCategory()) {
                if (node->getLeft() == nullptr) {
                    Node *temp = node->getRight();
                    delete node;
                    cout << "Node has been deleted successfully!" << endl;
                    return temp;
                } else if (node->getRight() == nullptr) {
                    Node *temp = node->getLeft();
                    delete node;
                    cout << "Node has been deleted successfully!" << endl;
                    return temp;
                }
                // If it has 2 children (last case)
                Node *successorParent = node;
                Node *successor = node->getRight();
                while (successor->getLeft() != nullptr) {
                    successorParent = successor;
                    successor = successor->getLeft();
                }
                node->setData(successor->getData());
                successorParent->setLeft(successor->getRight());
                delete successor;
                cout << "Node has been deleted successfully!" << endl;
            }
            else{
                node->setLeft(deleteItem(node->getLeft(), item));
                node->setRight(deleteItem(node->getRight(), item));
            }
        }
        return node;
    }

    void inorder(Node* node, vector<Item>& items) {
        if (node != nullptr) {
            inorder(node->getLeft(), items);
            items.push_back(node->getData());
            inorder(node->getRight(), items);
        }
    }

    void displaypreOrder(Node *node){
        if(node != nullptr){
            node->getData().print();
            displaypreOrder(node->getLeft());
            displaypreOrder(node->getRight());
        }
    }

    void displayAscByName(Node *node){
        vector<Item> items;
        inorder(root, items);
        sort(items.begin(), items.end(), Item::compareByName);
        cout << "*******************SORTED BY NAME ASCENDING*******************" << endl;
        for(auto& item: items){
            item.print();
        }
        cout << "-----------------------------------------------------------------------" << endl;
        cout << endl;
    }

    void displayDesByName(Node *node){
        vector<Item> items;
        inorder(root, items);
        sort(items.rbegin(), items.rend(), Item::compareByName);
        cout << "*******************SORTED BY NAME DESCENDING*******************" << endl;
        for(auto& item: items){
            item.print();
        }
        cout << "-----------------------------------------------------------------------" << endl;
        cout << endl;
    }

    void displayAscByPrice(Node *node){
        vector<Item> items;
        inorder(root, items);
        sort(items.begin(), items.end(), Item::compareByPrice);
        cout << "*******************SORTED BY PRICE ASCENDING*******************" << endl;
        for(auto& item: items){
            item.print();
        }
        cout << "-----------------------------------------------------------------------" << endl;
        cout << endl;
    }

    void displayDesByPrice(Node *node){
        vector<Item> items;
        inorder(root, items);
        sort(items.rbegin(), items.rend(), Item::compareByPrice);
        cout << "*******************SORTED BY PRICE DESCENDING*******************" << endl;
        for(auto& item: items){
            item.print();
        }
        cout << "-----------------------------------------------------------------------" << endl;
        cout << endl;
    }


};
#endif //TREES_ASSIGNMENT_BST_H
