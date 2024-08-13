#ifndef MAXHEAPE_H_INCLUDED
#define MAXHEAPE_H_INCLUDED
#include "Item.h"
#include <bits/stdc++.h>
#define ll long long
#define Maya() ios_base::sync_with_stdio(false),cin.tie(NULL);
#define el "\n"
#define testcase int t; cin>>t; while(t--)
using namespace std;

template<typename T, typename Compare>
class MaxHeap
{
private:
    vector<T> data;
    int size;
    Compare comp;
    void heapifyDown(int i) {
        while (i < size) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && comp(data[left], data[largest])) {
                largest = left;
            }
            if (right < size && comp(data[right] , data[largest]) ){
                largest = right;
            }
            if (largest != i) {
                swap(data[i], data[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

    void heapifyUp(int i) {
        while (i > 0 && comp(data[i], data[(i - 1) / 2])) {
            swap(data[i], data[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

public:
    MaxHeap(vector<T> data, Compare comp) {
        this->data = data;
        size = data.size();
        for (int i = size - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    void Insert(T value) {
        data.push_back(value);
        size++;
        heapifyUp(size - 1);
    }

    void Delete() {
        if (size == 0) return;
        data[0] = data[size - 1];
        data.pop_back();
        size--;
        heapifyDown(0);
    }

    void sort() {
        int originalSize = size;
        for (int i = size - 1; i > 0; i--) {
            swap(data[0], data[i]);
            size--;
            heapifyDown(0);
        }
        size = originalSize;
    }

    void print() {
        for (auto i : data){
           i.print();
        }
        cout << el;
    }
};

#endif // MAXHEAPE_H_INCLUDED
