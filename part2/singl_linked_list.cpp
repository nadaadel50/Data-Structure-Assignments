#include <iostream>

template<typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

template<typename T>
class SingleLinkedList {
private:
    Node<T>* head;
    int size;

public:
    SingleLinkedList() : head(nullptr), size(0) {}

    void insertAtHead(const T& element) {
        Node<T>* new_node = new Node<T>(element);
        new_node->next = head;
        head = new_node;
        size++;
    }

    void insertAtTail(const T& element) {
        Node<T>* new_node = new Node<T>(element);
        if (!head) {
            head = new_node;
        } else {
            Node<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_node;
        }
        size++;
    }

    void insertAt(const T& element, int index) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            insertAtHead(element);
        } else if (index == size) {
            insertAtTail(element);
        } else {
            Node<T>* new_node = new Node<T>(element);
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
            size++;
        }
    }

    void removeAtHead() {
        if (!head) {
            throw std::out_of_range("List is empty");
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void removeAtTail() {
        if (!head) {
            throw std::out_of_range("List is empty");
        }
        if (!head->next) {
            delete head;
            head = nullptr;
        } else {
            Node<T>* current = head;
            while (current->next->next) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
        size--;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            removeAtHead();
        } else if (index == size - 1) {
            removeAtTail();
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
            size--;
        }
    }

    T retrieveAt(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    void replaceAt(const T& new_element, int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = new_element;
    }

    bool isExist(const T& element) {
        Node<T>* current = head;
        while (current) {
            if (current->data == element) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool isItemAtEqual(const T& element, int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data == element;
    }

    void swap(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx == secondItemIdx) {
            return;
        }
        if (firstItemIdx > secondItemIdx) {
            std::swap(firstItemIdx, secondItemIdx);
        }

        Node<T>* prev1 = nullptr;
        Node<T>* current1 = head;
        for (int i = 0; i < firstItemIdx; i++) {
            prev1 = current1;
            current1 = current1->next;
        }

        Node<T>* prev2 = nullptr;
        Node<T>* current2 = head;
        for (int i = 0; i < secondItemIdx; i++) {
            prev2 = current2;
            current2 = current2->next;
        }

        if (prev1) {
            prev1->next = current2;
        } else {
            head = current2;
        }

        if (prev2) {
            prev2->next = current1;
        } else {
            head = current1;
        }

        std::swap(current1->next, current2->next);
    }

    bool isEmpty() {
        return size == 0;
    }

    int linkedListSize() {
        return size;
    }

    void clear() {
        while (head) {
            removeAtHead();
        }
    }

    void print() {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "None" << std::endl;
    }

    ~SingleLinkedList() {
        clear();
    }
};
int main() {
    SingleLinkedList<std::string> sll;
    sll.insertAtHead("Noha");
    sll.insertAtHead("Mona");
    sll.insertAtHead("Mohammed");
    sll.insertAtTail("Ahmed");
    sll.insertAt("Noha", 1);
    sll.print();  // Output: Ahmed -> Mohammed -> Mona -> Noha -> Noha -> None
    std::cout << "Size: " << sll.linkedListSize() << std::endl;  // Output: Size: 5
    std::cout << "Is Mona in the list? " << std::boolalpha << sll.isExist("Mona") << std::endl;  // Output: Is Mona in the list? true
    sll.removeAtTail();
    sll.print();  // Output: Ahmed -> Mohammed -> Mona -> Noha -> None
    sll.swap(1, 3);
    sll.print();  // Output: Ahmed -> Noha -> Mona -> Mohammed -> None
    sll.clear();
    std::cout << "Is the list empty? " << std::boolalpha << sll.isEmpty() << std::endl;  // Output: Is the list empty? true
    return 0;
}


