#include <iostream>
#include <vector>
#include "student.h"
#include "functions.h"
#include <chrono>
#include <cmath>
using namespace std;



template<typename T, typename Compare>
vector<T> selectionSort(vector<T>&arr, Compare comp){
    for(int i=0; i<arr.size()-1; i++){
        T max = arr[i];
        int indx = i;
        for(int j=i+1; j<arr.size(); j++){
            if( comp(arr[j], max) ){
                max = arr[j];
                indx = j;
            }
        }
        swap(arr[i],arr[indx]);
    }
    return arr;
}
template<typename T, typename Compare>
vector<T> insertionSort(vector<T>&arr,Compare comp){
    for (int i = 1; i < arr.size(); ++i) {
        T temp=arr[i];
        int j;
        for ( j = i; j >0&&comp(temp,arr[j-1]); --j) {
            arr[j]=arr[j-1];
        } arr[j]=temp;
    } return arr;
}


template <typename T>
void merge(vector<T> &myV, int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    vector<T> leftV, rightV;

    for (int i = 0; i < leftSize; i++)
        leftV.push_back(myV[left + i]);

    for (int i = 0; i < rightSize; i++)
        rightV.push_back(myV[middle + 1 + i]);

    int l = 0, r = 0, i = left;


    while (l < leftSize && r < rightSize) {
        if (leftV[l] < rightV[r]) {
            myV[i] = leftV[l];
            l++;
            i++;
        } else {
            myV[i] = rightV[r];
            r++;
            i++;
        }
    }

    while (l < leftSize){
        myV[i] = leftV[l];
        l++;
        i++;
    }

    while (r < rightSize) {
        myV[i] = rightV[r];
        r++;
        i++;
    }
}

template <typename T>
void mergeSort(vector<T> &myV, int left, int right) {
    if (left >= right)
        return;
    int middle = left + (right - left) / 2;
    mergeSort(myV, left, middle);
    mergeSort(myV, middle + 1, right);
    merge(myV, left, middle, right);
}




template<typename T, typename Compare>
vector<T> BubbleSort(vector<T>&arr, Compare comp){
    bool flag =true;
    int n=arr.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(comp( arr[j+1] ,arr[j]   )){
                swap(arr[j], arr[j+1]);
                flag= false;
            }
        }
        if(flag==true)
            break;
    }
    return arr;
}


template<typename T, typename Compare>
int partition(vector<T>& v, int low, int high, Compare comp) {
    T pivot = v[low];       // First element as pivot
    int i = low;
    for (int j = low + 1; j <= high; j++) {
        if (comp(v[j], pivot)) {
            i++;         //To make the i in the correct place of the pivot
            swap(v[i],v[j]);
        }
    }
    swap(v[i],v[low]);
    return i;
}


template<typename T, typename Compare>
void QuickSort(vector<T>& v, int low, int high, Compare comp) {
    if (low < high) {
        int pivot = partition(v, low, high, comp);
        QuickSort(v, low, pivot - 1, comp); // Before pivot
        QuickSort(v, pivot + 1, high, comp); // After pivot
    }
}
template<typename T, typename Compare>
vector<T>  shellSort(vector<T>&arr,Compare comp)
{
    for (int gap = arr.size()/2; gap > 0; gap /= 2)
    {
        for (int i = gap,j; i < arr.size(); i++)
        {
            T temp = arr[i];
            for (j = i; j >= gap &&comp( temp,arr[j - gap]  ); j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return arr;
}
template<typename T>
vector<T> countingSortByGPA(vector<T>& arr) {
    float maxGPA = arr[0].getGpa();
    for (const auto& student : arr) {
        if (student.getGpa() > maxGPA) {
            maxGPA = student.getGpa();
        }
    }

    vector<int> count(static_cast<int>(maxGPA) + 1, 0);

    for (const auto& student : arr) {
        count[static_cast<int>(student.getGpa())]++;
    }

    for (size_t i = 1; i < count.size(); ++i) {
        count[i] += count[i - 1];
    }

    vector<T> sortedArr;

    sortedArr.reserve(arr.size());

    for (size_t i = 0; i < arr.size(); ++i) {
        sortedArr.push_back(T("", "", 0.0)); // إضافة كائن Student بقيم افتراضية
    }

    for (int i = arr.size() - 1; i >= 0; --i) {
        sortedArr[count[static_cast<int>(arr[i].getGpa())] - 1] = arr[i];
        count[static_cast<int>(arr[i].getGpa())]--;
    }

    return sortedArr;
}



int main() {

    vector<Student> students;
    students = readStudentsFromFile("students.txt");
    int size = students.size();
// **************************************SELECTION SORT************************************************

    auto start = chrono::steady_clock::now();
    selectionSort(students, CompareByName());
    auto endoftime = chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(endoftime - start);
    writeResult("SortedByName.txt", students, "Selection Sort", to_string(size*size) ,time);

    start = chrono::steady_clock::now();
    selectionSort(students, CompareByGPA());
    endoftime = chrono::steady_clock::now();
    time = chrono::duration_cast<std::chrono::nanoseconds>(endoftime - start);
    writeResult("SortedByGPA.txt", students, "Selection Sort", to_string(size*size) ,time);

// **************************************INSERTION SORT************************************************
    start = chrono::steady_clock::now();
    insertionSort(students, CompareByName());
    endoftime = chrono::steady_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds>(endoftime - start);
    writeResult("SortedByName.txt", students, "insertion Sort", "" ,time);


    start = chrono::steady_clock::now();
    insertionSort(students, CompareByGPA());
    endoftime = chrono::steady_clock::now();
    time = chrono::duration_cast<std::chrono::nanoseconds>(endoftime - start);
    writeResult("SortedByGPA.txt", students, "insertion sort","" ,time);

// **************************************MERGE SORT************************************************

    vector<Student>sortedByName;
    start = chrono::steady_clock::now();
    mergeSort(Names, 0, Names.size()-1);
    endoftime = chrono::steady_clock::now();
    time = chrono::duration_cast<std::chrono::nanoseconds>(endoftime - start);
    for(int i = 0; i < Names.size(); i++){
        for (const auto& student : students) {
            if(student.getName() == Names[i]){
                sortedByName.push_back(student);
                break;
            }
        }
    }
    writeResult("SortedByName.txt", sortedByName, "Merge Sort", to_string(int(size*log2(size))) ,time);


    vector<Student> sortedByGpa;
    start = chrono::steady_clock::now();
    mergeSort(Gpas, 0, Gpas.size()-1);
    endoftime = chrono::steady_clock::now();
    time = chrono::duration_cast<std::chrono::nanoseconds>(endoftime - start);
    for(int i = Gpas.size() - 1; i >= 0; i--){
        // Search for the student with GPA equal to Gpas[i]
        for (const auto& student : students) {
            if(student.getGpa() == Gpas[i]){
                sortedByGpa.push_back(student);
                break;
            }
        }
    }
    writeResult("SortedByGPA.txt", sortedByGpa, "Merge Sort" , to_string(int(size*log2(size))) ,time);


    //************************************BUBBLE SORT********************************************************

    auto start = chrono::steady_clock::now();
    BubbleSort(students,CompareByName());
    auto endoftime = chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(endoftime - start);
    writeResult("SortedByName.txt",students, "Bubble Sort", to_string(int(size*(size-1))/4) ,time);

    auto start2 = chrono::steady_clock::now();
    BubbleSort(students,CompareByGPA());
    auto endoftime2 = chrono::steady_clock::now();
    auto time2 = chrono::duration_cast<std::chrono::nanoseconds>(endoftime2 - start2);
    writeResult("SortedByGPA.txt",students, "Bubble sort",to_string(int(size*(size-1))/4) ,time2);

//************************************QUICK SORT********************************************************
    auto startQuickByName = chrono::steady_clock::now();
    QuickSort(students, 0, students.size() - 1, CompareByName());
    auto endQuickByName = chrono::steady_clock::now();
    auto timeQuickByName = chrono::duration_cast<chrono::nanoseconds>(endQuickByName - startQuickByName);

    writeResult("SortedByName.txt", students, "Quicksort",to_string(int(size*size) ),timeQuickByName);

    auto startQuickByGPA = chrono::steady_clock::now();
    QuickSort(students, 0, students.size() - 1, CompareByGPA());
    auto endQuickByGPA = chrono::steady_clock::now();
    auto timeQuickByGPA = chrono::duration_cast<chrono::nanoseconds>(endQuickByGPA - startQuickByGPA);

    writeResult("SortedByGPA.txt", students, "Quicksort ",to_string(int(size*size) ) , timeQuickByGPA);


    //************************************shell sort ********************************************************
    start = chrono::steady_clock::now();
    shellSort(students,CompareByName());
    endoftime = chrono::steady_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds>(endoftime - start);
    writeResult("SortedByName.txt",students, "shell Sort", "" ,time);

    start = chrono::steady_clock::now();
    shellSort(students,CompareByGPA());
    endoftime = chrono::steady_clock::now();
    time = chrono::duration_cast<std::chrono::nanoseconds>(endoftime - start);
    writeResult("SortedByGPA.txt",students, "shell sort", "" ,time);

    //************************************count sort ********************************************************
    start = chrono::steady_clock::now();
    countingSortByGPA(students);
    endoftime = chrono::steady_clock::now();
    time = chrono::duration_cast<std::chrono::nanoseconds>(endoftime - start);
    writeResult("SortedByGPA.txt",students, "count sort ","" ,time);



    return 0;
}
