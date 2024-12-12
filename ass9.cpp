#include <iostream>
using namespace std;

void heapify(int arr[], int size, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int maxIdx = i;

    if (left < size && arr[left] > arr[maxIdx]) {//for min heap change > to < ;
        maxIdx = left;
    }
    if (right < size && arr[right] > arr[maxIdx]) {//for min heap change > to < ;
        maxIdx = right;
    }

    if (maxIdx != i) {
        swap(arr[i], arr[maxIdx]);
        heapify(arr, size, maxIdx);
    }
}

void heapsort(int arr[], int size) {
    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    // Extract elements from heap
    for (int i = size - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {2, 9, 1, 8, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
