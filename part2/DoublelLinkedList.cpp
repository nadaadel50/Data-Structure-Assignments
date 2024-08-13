#include <bits/stdc++.h>
#define ll long long
#define Maya() ios_base::sync_with_stdio(false),cin.tie(NULL);
#define el "\n"
#define testcase int t; cin>>t; while(t--)
using namespace std;

template <class T>
class Node {
    public:
        T value;
        Node<T>* left;
        Node<T>* right;

        Node(T value){
            this->value = value;
            left = NULL;
            right = NULL;
        }
};

template <class T>
class DoubleLinkedList{
    Node<T>*head;
    Node<T>*tail;
    ll size;
    public:

    DoubleLinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    void insertAtHead(T element){
        size++;
        Node<T>* node = new Node(element);
        if(head == NULL && tail == NULL){
            tail = node;
        }
        else{
            head->left = node;
            node->right = head;
        }
        head = node;
    }

    void insertAtTail(T element){
        size++;
        Node<T>* node = new Node(element);
        if(head == NULL && tail == NULL){
            head = node;
        }
        else{
            tail->right = node;
            node->left = tail;
        }
        tail = node;
    }

    void insertAt (T element, int index){
        if(head == NULL || index <  0 || index > size){
            cout << "NOT VALID POSITION" << el;
            return;
        }
        if(index == 0){
            insertAtHead(element);
            return;
        }
        if(index == size){
            insertAtTail(element);
            return;
        }
        Node<T>* node = new Node(element);
        Node<T>* point = head;
        int counter = 0;
        while (counter < index - 1) {
        point = point->right;
        counter++;
        }
        size++;
        node->right = point->right;
        node->left = point;
        point->right->left = node;
        point->right = node;
            
        
    }

    void removeAtHead(){
        if(head == NULL) return;
        size--;
        if(head == tail){
            Node<T>* node = head;
            head = NULL;
            tail = NULL;
            delete node;
            return;
        }
        Node<T>* node = head;
        head = head->right;
        head->left = NULL;
        delete node;
    }

    void removeAtTail(){
        if(head == NULL) return;
        size--;
        if(head == tail){
            Node<T>* node = head;
            head = NULL;
            tail = NULL;
            delete node;
            return;
        }
        Node<T>* node = tail;
        tail = tail->left;
        tail->right = NULL;
        delete node;
    }

    void removeAt(int index){
        if(head == NULL || index < 0 || index >= size){
            cout << "NOT VALID POSITION" << el;
            return;
        }
        if(index == 0){
            removeAtHead();
            return;
        }
        if(index == size-1){
            removeAtTail();
            return;
        }
        Node<T>* point = head;
        int counter = 0;
        while(counter < index ){
        point = point->right;
        counter++;
        }
        point->left->right = point->right;
        point->right->left = point->left;
        delete point;
        size--;
                    
    }

    T retrieveAt(int index){
        if(head == NULL || index < 0 || index >= size){
            cout << "NOT VALID POSITION" << el;
            return T();
        }
        Node<T>* point = head;
        int counter = 0;
        while(counter < index){
            point = point->right;
            counter++;
        }
        return point->value ;

    }

    void replaceAt (T newElement, int index){
        if(head == NULL || index < 0 || index >= size){
            cout << "NOT VALID POSITION" << el;
            return;
        }
        Node<T>* point = head;
        int counter = 0;
        while(counter < index){
            point = point->right;
            counter++;
        }
        point->value = newElement;
    }

    bool isExist (T element){
        if(head == NULL ){
            cout << "Linked List Is Empty" << el;
            return false;
        }
        bool f = false;
        Node<T>* point = head;
        while(point->right != NULL){
            if(point->value == element){
                f = true;
                break;
            } 
            point = point->right;
        }
        return f;
    }

    bool isItemAtEqual (T element, int index){
        if(head == NULL ){
            cout << "Linked List Is Empty" << el;
            return false;
        }
        Node<T>* point = head;
        int counter = 0;
        while(point->right != NULL && counter < index){
            point = point->right;
            counter++;
        }
        if(counter == index){
            if(point->value == element) return true;
            else return false;
        }
        return false;
    }

    void swap(int firstItemIdx, int secondItemIdx) {
    if (size < 2 || firstItemIdx < 0 || firstItemIdx > size-1 || secondItemIdx < 0 || secondItemIdx > size-1 || firstItemIdx == secondItemIdx) {
        cout << "Invalid Operation";
        return;
    }


    Node<T>* firstNode = head;
    Node<T>* secondNode = head;
    for (int i = 0; i < firstItemIdx; ++i) {
        firstNode = firstNode->right;
    }
    for (int i = 0; i < secondItemIdx; ++i) {
        secondNode = secondNode->right;
    }

    if (abs(firstItemIdx-secondItemIdx) == 1) {
        Node<T>* temp = secondNode->right;
        secondNode->right = firstNode;
        firstNode->left = secondNode;
        firstNode->right = temp;
        if(temp != NULL) {
            temp->left = firstNode;
        }
        if(firstNode != head) {
            secondNode->left = firstNode->left;
            firstNode->left->right = secondNode;
        } else {
            head = secondNode;
        }
    } 
  
    else {
        Node<T>* temp = secondNode->right;
        secondNode->right = firstNode->right;
        if(firstNode->right != NULL) {
            firstNode->right->left = secondNode;
        }
        firstNode->right = temp;
        if(temp != NULL) {
            temp->left = firstNode;
        }

        temp = secondNode->left;
        secondNode->left = firstNode->left;
        if(firstNode->left != NULL) {
            firstNode->left->right = secondNode;
        }
        firstNode->left = temp;
        if(temp != NULL) {
            temp->right = firstNode;
        }


        if(head == firstNode) {
            head = secondNode;
        } else if(head == secondNode) {
            head = firstNode;
        }
        if(tail == firstNode) {
            tail = secondNode;
        } else if(tail == secondNode) {
            tail = firstNode;
        }
    }
}


    bool isEmpty(){
        return (size == 0);
    }

    int linkedListSize(){
        return size;
    }

    void clear(){
        if (head == NULL) {
        return; 
        }
        Node<T>* point = head;
        while(point->right != NULL){
            Node<T>* current = point;
            point = point->right;
            delete current;
        }
        head = NULL;
        tail = NULL;
        delete point;
        size = 0; 
    }
    
    void print(){
        Node<T>* point = head;
        while(point->right != NULL){
            cout << point->value <<" ";
            point = point->right;
        }
        cout << point->value << el;
    }

    ~DoubleLinkedList(){
        clear();
    }
};


int main() {
    
    DoubleLinkedList<int> dll;
    dll.retrieveAt(0);
    // Inserting elements at various positions
    dll.insertAtHead(1);  // 1
    dll.insertAtTail(3);  // 1 3
    dll.insertAt(2, 1);   // 1 2 3

    dll.print(); // 1 2 3

    dll.insertAtHead(0);  // 0 1 2 3
    dll.insertAtTail(4);  // 0 1 2 3 4
    
    dll.print();  // Output: 01234
    
    // Removing elements at various positions
    dll.removeAt(2);  // 0 1 3 4
    dll.removeAtHead();  // 1 3 4
    dll.removeAtTail();  // 1 3
    
    dll.print();  // Output: 1 3
    
    // Swapping elements at different indices
    dll.swap(0, 1);  // 3 1
    dll.print();  // Output: 3 1
    cout << dll.retrieveAt(0) << el;
    cout << dll.retrieveAt(1) << el;
    cout << dll.retrieveAt(2) << el;

    // Checking existence of elements
    cout << dll.isExist(3) << endl;  // Output: 1 (true)
    cout << dll.isExist(5) << endl;  // Output: 0 (false)
    
    // Checking if items are equal at given index
    cout << dll.isItemAtEqual(3, 0) << endl;  // Output: 1 (true)
    cout << dll.isItemAtEqual(5, 1) << endl;  // Output: 0 (false)
    
    // Replacing an item at a given index
    dll.replaceAt(2, 1);  // 3 2
    dll.print();  // Output: 3 2
    
    // Getting the size of the linked list
    cout << dll.linkedListSize() << endl;  // Output: 2
    
    // Clearing the linked list
    dll.clear();
    cout << dll.isEmpty() << endl;  // Output: 1 (true)

}

