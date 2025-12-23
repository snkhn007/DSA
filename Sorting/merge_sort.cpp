#include <iostream>
using namespace std;

// Merges two sorted halves of arr[start..end]
void merge(int arr[], int strt, int end) {
    int mid = strt + (end - strt) / 2;

    int leftSize = mid - strt + 1;
    int rightSize = end - mid;

    // Dynamic arrays (standard C++)
    // Allocates memory on the heap
    // This memory does NOT get freed automatically
    // It stays allocated until you explicitly free it
    int* left = new int[leftSize];
    int* right = new int[rightSize];

    for (int i = 0; i < leftSize; i++)
        left[i] = arr[strt + i];

    for (int i = 0; i < rightSize; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = strt;

    // Stable merge
    while (i < leftSize && j < rightSize) {
        // Used <= for stability
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }

    while (i < leftSize){
         arr[k++] = left[i++];
    }

    while (j < rightSize){
        arr[k++] = right[j++];
    }

    // Free dynamically allocated memory to avoid memory leaks
    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int strt, int end) {
    if (strt >= end) return;

    int mid = strt + (end - strt) / 2;
    mergeSort(arr, strt, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, strt, end);
}

int main() {
    int arr[] = {2, 5, 1, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
