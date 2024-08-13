
#include<iostream>
#include<bits/stdc++.h>
#include <stdexcept>
using namespace std;

template<typename T>
class CircularDoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
    };

    Node* first;
    Node* last;
    int length;

public:
    CircularDoublyLinkedList(){
        first = nullptr;
        last = nullptr;
        length = 0;
    }
    void insertAtHead(T element) {
        Node* newNode = new Node;
        newNode->data = element;
        if (isEmpty()) {
            first = last = newNode;
            newNode->next = newNode->prev = newNode;
        } else {
            newNode->next = first;
            newNode->prev = last;
            first->prev = newNode;
            last->next = newNode;
            first = newNode;
        }
        length++;
    }

    void insertAtTail(T element) {
        Node* newNode = new Node;
        newNode->data = element;
        if (isEmpty()) {
            first = last = newNode;
            newNode->next = newNode->prev = newNode;
        } else {
            newNode->next = first;
            newNode->prev = last;
            first->prev = newNode;
            last->next = newNode;
            last = newNode;
        }
        length++;
    }

    void insertAt(T element, int index) {
        if (index < 0 || index > length) {
            throw out_of_range("Index out of range");
        } else if (index == 0) {
            insertAtHead(element);
        } else if (index == length) {
            insertAtTail(element);
        } else {
            Node* newNode = new Node;
            newNode->data = element;
            Node* current = first;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            length++;
        }
    }

    void removeAtHead() {
        if (isEmpty()) {
            throw out_of_range("List is empty");
        } else if (length == 1) {
            delete first;
            first = last = nullptr;
        } else {
            Node* temp = first;
            first = first->next;
            first->prev = last;
            last->next = first;
            delete temp;
        }
        length--;
    }

    void removeAtTail() {
        if (isEmpty()) {
            throw out_of_range("List is empty");
        } else if (length == 1) {
            delete last;
            first = last = nullptr;
        } else {
            Node* temp = last;
            last = last->prev;
            last->next = first;
            first->prev = last;
            delete temp;
        }
        length--;
    }

    void removeAt(int index) {
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of range");
        } else if (index == 0) {
            removeAtHead();
        } else if (index == length - 1) {
            removeAtTail();
        } else {
            Node* current = first;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            length--;
        }
    }

    T retrieveAt(int index) {
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of range");
        } else {
            Node* current = first;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            return current->data;
        }
    }

    void replaceAt(T element, int index) {
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of range");
        } else {
            Node* current = first;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            current->data = element;
        }
    }

    bool isExist(T element) {
        if(isEmpty()){
            throw out_of_range("List is empty");
        }
        Node* current = first;
        for (int i = 0; i < length; i++) {
            if (current->data == element) {
                cout << element << " is found. " << endl;
                return true;
            }
            current = current->next;
        }
        cout << element << " is not found." << endl;
        return false;
    }

    bool isItemAtEqual(T element, int index) {
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of range");
        } else {
            Node* current = first;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            return current->data == element;
        }
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
        else{
            Node* firstItem = first;
            Node* secondItem = first;
            for (int i = 0; i < firstItemIdx; i++) {
                firstItem = firstItem->next;
            }
            for (int i = 0; i < secondItemIdx; i++) {
                secondItem = secondItem->next;
            }

            Node* temp = firstItem->next;
            firstItem->next = secondItem->next;
            secondItem->next = temp;


            firstItem->next->prev = firstItem;
            secondItem->next->prev = secondItem;
            firstItem->prev->next = secondItem;
            secondItem->prev->next = firstItem;

            temp = firstItem->prev;
            firstItem->prev = secondItem->prev;
            secondItem->prev = temp;


            if (firstItemIdx == 0) {
                first = secondItem;
            }
            if (secondItemIdx == 0) {
                first = firstItem;
            }
            if (firstItemIdx == length - 1) {
                last = secondItem;
            }
            if (secondItemIdx == length - 1) {
                last = firstItem;
            }
        }
    }

    bool isEmpty() {
        return length == 0;
    }

    int linkedListSize() {
        return length;
    }

    void clear() {
        while (!isEmpty()) {
            removeAtHead();
        }
    }

    void print() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = first;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != first);
        cout << endl;
    }

    ~CircularDoublyLinkedList() {
        clear();
    }
};

int main() {
    CircularDoublyLinkedList<int> myList;

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

    myList.swap(1,8);
    myList.print();

    myList.removeAt(5);
    myList.print();

    myList.removeAtTail();
    myList.print();

    myList.removeAtHead();
    myList.print();

    cout << "Element at index 2: " << myList.retrieveAt(5) << endl;

    myList.replaceAt(4,4);
    myList.print();

    myList.isExist(0);
    myList.isExist(55);

    cout << "Size: " << myList.linkedListSize() << endl;

    myList.swap(5,0);
    myList.print();


    cout <<  "Is number 5 is at index 2? "<< boolalpha <<myList.isItemAtEqual(5,2) << endl; // 1  (true)
    cout << "Is number 7 is at index 3? " << boolalpha << myList.isItemAtEqual(7,3) << endl; // 0  (false)

    myList.clear();
    cout << "Size: " << myList.linkedListSize() << endl;

    myList.removeAtHead();
    myList.insertAtTail(4);
    myList.print();

    return 0;
}
