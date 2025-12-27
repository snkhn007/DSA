#include <iostream>
using namespace std;
// first put on elelment at its correct position(by counting elements less than it), 
// make sure all less than it are before it
int partition(int arr[], int strt, int end){
    int pivot = arr[strt];
    int index = 0;

    // Starting from strt+1
    // Pivot not compared with itself → clean logic.
    for (int i = strt + 1; i <= end; i++) {
        if(arr[i] < pivot) index++;
    }

    int pivotIndex = strt + index;
    swap(arr[pivotIndex], arr[strt]);

    int i = strt, j = end;
    while(i < pivotIndex && j > pivotIndex){
        if(arr[i] < pivot) i++;
        else if(arr[j] >= pivot) j--;
        else swap(arr[i++], arr[j--]);
    }
    
    return pivotIndex;
}

void quickSort(int arr[], int strt, int end){
    if(strt>=end) return;
    int p = partition(arr, strt, end);
    quickSort(arr, strt, p-1);
    quickSort(arr, p+1, end);
}
int main() {
    int arr[] = {2, 5, 1, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n-1);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
