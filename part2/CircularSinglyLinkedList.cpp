
#include<iostream>
#include<bits/stdc++.h>
#include <stdexcept>
using namespace std;
typedef long long ll;

template<typename T>
class CircularSinglyLinkedList{
private:
    struct Node{
        T data;
        Node *next;
    };
    Node *first;
    Node *last;
    int length;
public:
    CircularSinglyLinkedList(){
        first = NULL;
        last = NULL;
        length = 0;
    }
    void insertAtHead(T element){
        Node *newNode = new Node;
        newNode->data = element;
        if(isEmpty()){
            first = last = newNode;
            newNode->next = first;
        }
        else{
            newNode->next = first;
            first = newNode;
            last->next = first;
        }
        length++;
    }
    void insertAtTail(T element){
        Node *newNode = new Node;
        newNode->data = element;
        if(isEmpty()){
            first = last = newNode;
            newNode->next = first;
        }
        else{
            last->next = newNode;
            last = newNode;
            last->next = first;
        }
        length++;
    }
    void insertAt(T element, int index){
        if(index < 0 || index > length){
            throw std::out_of_range("Index out of range");
        }
        else{
            if(index == 0){
                insertAtHead(element);
            }
            else if(index == length){
                insertAtTail(element);
            }
            else{
                Node *newNode = new Node;
                newNode->data = element;
                Node *current = first;
                for(int i = 1; i < index; i++){
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
                length++;
            }
        }
    }
    void removeAtHead(){
        if(isEmpty()){
            throw out_of_range("List is empty");
        }
        else if(length == 1){
            delete first;
            last = first = nullptr;
            length--;
        }
        else{
            Node *current = first;
            first = first->next;
            delete current;
            length--;
            last->next = first;
        }
    }
    void removeAtTail(){
        if(isEmpty()){
            throw out_of_range("List is empty");
        }
        else if(length == 1){
            delete first;
            last = first = nullptr;
            length--;
        }
        else{
            Node *current = last;
            delete current;
            last = first;
            for(int i = 1; i < length-1; i++){
                last = last->next;
            }
            last->next = first;
            length--;
        }
    }
    void removeAt(int index){
        if(isEmpty()){
            throw out_of_range("List is empty");
        }
        else if(index < 0 || index >= length){
            throw std::out_of_range("Index out of range");
        }
        else if(index == 0){
            removeAtHead();
        }
        else if(index == length-1){
            removeAtTail();
        }
        else{
            Node *current = first;
            Node *prev = first;
            for (int i = 1; i <= index; i++) {
                prev = current;
                current = current->next;
            }
            prev->next = current->next;
            delete current;
            length--;
        }
    }
    T retrieveAt(int index){
        if(index < 0 || index >= length){
            throw std::out_of_range("Index out of range");
        }
        else if(index == 0){
            return first->data;
        }
        else if(index == length-1){
            return last->data;
        }
        else{
            Node *current = first;
            for(int i = 1; i < index; i++){
                current = current->next;
            }
            current = current->next;
            return current->data;
        }
    }
    void replaceAt(T element, int index){
        if(isEmpty()){
            throw out_of_range("List is empty");
        }
        else if(length <= index){
            throw std::out_of_range("Index out of range");
        }
        else if(index == 0){
            first->data = element;
        }
        else if(index == length-1){
            last->data = element;
        }
        else{
            Node *current = first;
            for(int i = 1; i < index; i++){
                current = current->next;
            }
            current = current->next;
            current->data = element;
        }
    }
    bool isExist(T element){
        if(isEmpty()){
            throw out_of_range("List is empty");
        }
        else{
            Node *current = first;
            int counter = 0;
            while(current && counter < length){
                if(current->data == element){
                    cout << element << " is found at index " << counter << endl;
                    return true;
                }
                current = current->next;
                counter++;
            }
            cout << element << " is not found." << endl;
            return false;
        }
    }

    bool isItemAtEqual(T element, int index){
        T item = retrieveAt(index);
        return item == element;
    }

    void swap(int firstItemIdx, int secondItemIdx) {
        if (isEmpty()) {
            throw out_of_range("List is empty");
        }
        else if (firstItemIdx == secondItemIdx) {
            cout << "It's the same index!" << endl;
        }
        else if (firstItemIdx >= length || secondItemIdx >= length || firstItemIdx < 0 || secondItemIdx < 0 ) {
            throw std::out_of_range("Index out of range");
        }
        else if(firstItemIdx == 0 && secondItemIdx == length-1){
            Node *prev1 = nullptr;
            Node *prev2 = first;
            Node *current1 = first;
            Node *current2 = last;

            // Traverse to the node before the last node
            while (prev2->next != last) {
                prev2 = prev2->next;
            }

            // Update previous pointers
            prev2->next = current1;
            last->next = current1->next;
            first = current2;
            last = current1;
            last->next = first;
        }
        else if(firstItemIdx == length-1 && secondItemIdx == 0){
            Node *prev1 = first;
            Node *prev2 = nullptr;
            Node *current1 = last;
            Node *current2 = first;

            while(prev1->next != last){
                prev1 = prev1->next;
            }

            prev1->next = current2;
            last->next = current2->next;
            first = current1;
            last = current2;
            last->next = first;

        }
        else {
            Node *prev1 = nullptr;
            Node *prev2 = nullptr;
            Node *current1 = first;
            Node *current2 = first;


            for (int i = 0; i < firstItemIdx; i++) {
                prev1 = current1;
                current1 = current1->next;
            }
            for (int i = 0; i < secondItemIdx; i++) {
                prev2 = current2;
                current2 = current2->next;
            }


            std::swap(current1->next, current2->next);


            if (prev1) {
                prev1->next = current2;
            } else {
                first = current2;
            }
            if (prev2) {
                prev2->next = current1;
            } else {
                first = current1;
            }


            if (current1->next == first) {
                last = current1;
            } else if (current2->next == first) {
                last = current2;
            }

        }
    }
    bool isEmpty(){
        return length == 0;
    }
    int linkedListSize(){
        return length;
    }
    void clear(){
        if(isEmpty()){
            throw out_of_range("List is empty");
        }
        else{
            while(!isEmpty()){
                removeAtHead();
            }
        }
    }
    void print(){
        Node *current = first;
        for(int i = 1; i <= length; i++){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    ~CircularSinglyLinkedList(){
        clear();
    }
};



int main(){

    CircularSinglyLinkedList<int>myList;

    myList.insertAtHead(5);
    myList.insertAtHead(8);
    myList.insertAtHead(1);
    myList.print();


    myList.insertAtTail(34);
    myList.insertAtTail(2);
    myList.insertAtTail(55);
    myList.insertAtTail(22);
    myList.print();

    myList.insertAt(4,2);
    myList.insertAt(33, 4);
    myList.print();

    myList.removeAt(5);
    myList.print();

    myList.removeAtTail();
    myList.print();

    myList.removeAtHead();
    myList.print();

    cout << "Element at index 2: " << myList.retrieveAt(2) << endl;

    myList.replaceAt(6,3);
    myList.print();

    myList.isExist(0);
    myList.isExist(4);

    cout << "Size: " << myList.linkedListSize() << endl;

    myList.swap(0,3);
    myList.print();


    cout <<  myList.isItemAtEqual(5,2) << endl; // 1  (true)

    myList.swap(0,5);
    myList.print();

    myList.insertAtTail(44);
    myList.print();

    myList.clear();
    myList.insertAtHead(5);
    myList.print();
    
    return 0;
}
