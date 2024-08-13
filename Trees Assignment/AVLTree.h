#ifndef DS_AVLTREE_H
#define DS_AVLTREE_H
#include <bits/stdc++.h>
#include "Item.h"

struct AVLNode{
    Item data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(const Item& item):data(item),left(nullptr),right(nullptr),height(0){}

};

class AVLTree{
    AVLNode* root;

    int height(AVLNode* node){
        return node? node->height :0;
    }

    int BalanceFactor(AVLNode* node){
        return node ? height(node->left)-height(node->right) : 0;
    }

    //In case of left left
    AVLNode* RightRotation(AVLNode* y){
        AVLNode* x= y->left;
        AVLNode* z= x->right;
        x->right=y;
        y->left=z;

        y->height=max(height(y->left) , height(y->right))+1;
        x->height=max(height(x->left) , height(x->right))+1;

        return x;     //pointer to the new root for this part
    }

    AVLNode* LeftRotation(AVLNode* x){
        AVLNode* y= x->right;
        AVLNode* z= y->left;
        y->left=x;
        x->right=z;

        y->height=max(height(y->left) , height(y->right))+1;
        x->height=max(height(x->left) , height(x->right))+1;

        return y;     //pointer to the new root for this part
    }

    AVLNode* insert(AVLNode* node, const Item& item) {
        if(!node)
            return new AVLNode(item);
        if(item < node->data){
            node->left=insert(node->left,item);
        }
        else if(item > node->data){
            node->right=insert(node->right,item);
        }
        else{
            return node;
        }

        node->height = max(height(node->left) ,height(node->right))+1;
        //check if the tree is balanced or not
        int balancefc = BalanceFactor(node);

        if(balancefc > 1 && item < node->left->data){
            return RightRotation(node);
        }
        if(balancefc < -1 && item < node->right->data){
            return LeftRotation(node);
        }
        if(balancefc > 1 && item > node->left->data){
            node->left = LeftRotation(node->left);
            return RightRotation(node);
        }
        if(balancefc < -1 && item < node->right->data){
            node->right = RightRotation(node->right);
            return LeftRotation(node);
        }

        return node;
    }
    AVLNode* Delete (AVLNode*node,const Item& item){
        AVLNode*temp;
        if (node==NULL)
            return node ;
        else if (item<node->data)
            node->left= Delete(node->left,item);
        else if (item>node->data)
            node->right= Delete(node->right,item);
        else {
            if (node->right==NULL){
                temp =node->left;
                delete node;
                return temp;
            }
            else if (node ->left==NULL){
                temp=node->right;
                delete node ;
                return temp;
            }
            else {
                temp= minNode(node->right);
                node->data=temp->data;
                node->right= Delete(node->right,temp->data);
            }
        }
        int bf= BalanceFactor(node);
        if (bf==2&& BalanceFactor(node->left)>=0)
            return RightRotation(node);
        else if (bf==2&& BalanceFactor(node)<0) {
            node->left = LeftRotation(node->left);
            return RightRotation(node);
        }
        else if (bf==-2&& BalanceFactor(node->right)<=0)
            return LeftRotation(node);
        else if (bf==-2&& BalanceFactor(node->right)==1) {
            node->right = RightRotation(node->right);
            return LeftRotation(node);
        }
        return node;

    }

    AVLNode* minNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

public:
    AVLNode* get_root(){
        return root;
    }
    AVLTree():root(nullptr){}
    void insert(const Item& item){
        root = insert(root,item);
    }
    AVLNode* DeleteCall (const Item& item){
        return Delete(root,item);
    }
    void inorder(AVLNode* node, vector<Item>& items) {
        if (node != nullptr) {
            inorder(node->left, items);
            items.push_back(node->data);
            inorder(node->right, items);
        }
    }

    void displayInorder(AVLNode*node){
        if(node != nullptr){
            displayInorder(node->left);
            node->data.print();
            displayInorder((node->right));
        }
    }

    void displayAscByName(AVLNode *node){
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

    void displayDesByName(AVLNode *node){
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

    void displayAscByPrice(AVLNode *node){
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

    void displayDesByPrice(AVLNode *node){
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

#endif //DS_AVLTREE_H

