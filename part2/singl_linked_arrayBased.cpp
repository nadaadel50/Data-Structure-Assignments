#include <iostream>
#include <stdexcept>

template<typename T>
class SingleLinkedList {
private:
    T* array;
    int capacity;
    int size;

public:
    SingleLinkedList(int initialCapacity = 10) : capacity(initialCapacity), size(0) {
        array = new T[capacity];
    }

    void insertAtHead(const T& element) {
        if (size >= capacity) {
            expandCapacity();
        }
        for (int i = size; i > 0; --i) {
            array[i] = array[i - 1];
        }
        array[0] = element;
        size++;
    }

    void insertAtTail(const T& element) {
        if (size >= capacity) {
            expandCapacity();
        }
        array[size++] = element;
    }

    void insertAt(const T& element, int index) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (size >= capacity) {
            expandCapacity();
        }
        for (int i = size; i > index; --i) {
            array[i] = array[i - 1];
        }
        array[index] = element;
        size++;
    }

    void removeAtHead() {
        if (size == 0) {
            throw std::out_of_range("List is empty");
        }
        for (int i = 0; i < size - 1; ++i) {
            array[i] = array[i + 1];
        }
        size--;
    }

    void removeAtTail() {
        if (size == 0) {
            throw std::out_of_range("List is empty");
        }
        size--;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (int i = index; i < size - 1; ++i) {
            array[i] = array[i + 1];
        }
        size--;
    }

    T retrieveAt(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    void replaceAt(const T& new_element, int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        array[index] = new_element;
    }

    bool isExist(const T& element) {
        for (int i = 0; i < size; ++i) {
            if (array[i] == element) {
                return true;
            }
        }
        return false;
    }

    bool isItemAtEqual(const T& element, int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index] == element;
    }

    void swap(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx == secondItemIdx) {
            return;
        }
        std::swap(array[firstItemIdx], array[secondItemIdx]);
    }

    bool isEmpty() {
        return size == 0;
    }

    int linkedListSize() {
        return size;
    }

    void clear() {
        size = 0;
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            std::cout << array[i] << " -> ";
        }
        std::cout << "None" << std::endl;
    }

    ~SingleLinkedList() {
        delete[] array;
    }

private:
    void expandCapacity() {
        capacity *= 2;
        T* new_array = new T[capacity];
        for (int i = 0; i < size; ++i) {
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
    }
};

// Example usage:
int main() {
    SingleLinkedList<std::string> sll;
    sll.insertAtHead("Noha");
    sll.insertAtHead("Mona");
    sll.insertAtHead("Mohammed");
    sll.insertAtTail("Ahmed");
    sll.insertAt("Noha", 1);
    sll.print();  // Output: Mohammed -> Mona -> Noha -> Noha -> Ahmed -> None
    std::cout << "Size: " << sll.linkedListSize() << std::endl;  // Output: Size: 5
    std::cout << "Is Mona in the list? " << std::boolalpha << sll.isExist("Mona") << std::endl;  // Output: Is Mona in the list? true
    sll.removeAtTail();
    sll.print();  // Output: Mohammed -> Mona -> Noha -> Noha -> None
    sll.swap(1, 3);
    sll.print();  // Output: Mohammed -> Noha -> Noha -> Mona -> None
    sll.clear();
    std::cout << "Is the list empty? " << std::boolalpha << sll.isEmpty() << std::endl;  // Output: Is the list empty? true
    return 0;
}
