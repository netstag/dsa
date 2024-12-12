#include <iostream>
using namespace std;

struct student {
    int rollno;
    string name;
    float sgpa;
};  

// Swap function for swapping student structs
void swapStudents(student &a, student &b) {
    student temp = a;
    a = b;
    b = temp;
}

void bubblesort(student arrStudent[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arrStudent[j].rollno > arrStudent[j + 1].rollno) {
                swapStudents(arrStudent[j], arrStudent[j + 1]);
            }
        }
    }
    cout << "Bubble Sort (by rollno):" << endl;
    for (int i = 0; i < n; i++) {
        cout << arrStudent[i].rollno << " " << arrStudent[i].name << " " << arrStudent[i].sgpa << endl;
    }
}

void insertionSort(student arrStudent[], int n) {
    for (int i = 1; i < n; i++) {
        student key = arrStudent[i];
        int j = i - 1;
        while (j >= 0 && arrStudent[j].name > key.name) {
            arrStudent[j + 1] = arrStudent[j];
            j--;
        }
        arrStudent[j + 1] = key;
    }
    cout << "Insertion Sort (by name):" << endl;
    for (int i = 0; i < n; i++) {
        cout << arrStudent[i].name << " " << arrStudent[i].rollno << " " << arrStudent[i].sgpa << endl;
    }
}

int Partition(student arrStudent[], int l, int h) {
    float pivot = arrStudent[l].sgpa;
    int i = l;
    int j = h;
    while (i < j) {
        while (i < h && arrStudent[i].sgpa <= pivot) {
            i++;
        }
        while (arrStudent[j].sgpa > pivot) {
            j--;
        }
        if (i < j) {
            swapStudents(arrStudent[i], arrStudent[j]);
        }
    }
    swapStudents(arrStudent[j], arrStudent[l]);
    return j;
}

void quickSort(student arrStudent[], int l, int h) {
    if (l < h) {
        int pivot = Partition(arrStudent, l, h);
        quickSort(arrStudent, l, pivot - 1);
        quickSort(arrStudent, pivot + 1, h);
    }
}

int main() {
    student arrStudent[15] = {
        {3, "Prajwal", 9.41},
        {1, "Ram", 9.0},
        {2, "Shyam", 9.11},
        {4, "Shrikant", 9.44},
        {5, "Damodar", 9.22},
        {6, "Mangesh", 9.43},
        {7, "DJ", 9.47},
        {9, "Pranesh", 9.77},
        {8, "Raj", 10},
        {11, "Tushar", 9.09},
        {10, "Vivek", 9.8},
        {12, "Harsh", 9.2},
        {14, "Sarvesh", 9.3},
        {13, "Sachin", 9.76},
        {15, "Karan", 9.92},
    };
    
    // Sort by rollno
    bubblesort(arrStudent, 15);
    
    // Restore original order for next sort
    student originalArr[15] = {
        {3, "Prajwal", 9.41},
        {1, "Ram", 9.0},
        {2, "Shyam", 9.11},
        {4, "Shrikant", 9.44},
        {5, "Damodar", 9.22},
        {6, "Mangesh", 9.43},
        {7, "DJ", 9.47},
        {9, "Pranesh", 9.77},
        {8, "Raj", 10},
        {11, "Tushar", 9.09},
        {10, "Vivek", 9.8},
        {12, "Harsh", 9.2},
        {14, "Sarvesh", 9.3},
        {13, "Sachin", 9.76},
        {15, "Karan", 9.92},
    };
    for (int i = 0; i < 15; i++) {
        arrStudent[i] = originalArr[i];
    }

    // Sort by name
    insertionSort(arrStudent, 15);
    
    // Restore original order for next sort
    for (int i = 0; i < 15; i++) {
        arrStudent[i] = originalArr[i];
    }

    // Sort by sgpa
    quickSort(arrStudent, 0, 14);
    
    cout << "Quick Sort (by sgpa):" << endl;
    for (int i = 0; i < 15; i++) {
        cout << arrStudent[i].sgpa << " " << arrStudent[i].name << " " << arrStudent[i].rollno << endl;
    }

    return 0;
}
