#include <iostream>
using namespace std;
int partition(int arr[], int strt, int end){
    int ind = arr[strt];
    int count = 0;
    for (int i = strt+1; i <= end; i++){
        if(arr[i]<ind) count++;
    }
    swap(arr[strt], arr[strt+count]); 
    int i = strt, j = end;
    while(i<strt+count && j>strt+count){
        if(arr[i]<ind){
            i++;
        }
        else if(arr[j]>=ind) j--;
        else swap(arr[i++], arr[j--]);;
    }
    return strt+count;   
}
void quickSort(int arr[], int strt, int end){
    if(strt>=end) return;
    int p = partition(arr, strt, end);
    quickSort(arr, strt, p-1);
    quickSort(arr, p+1, end);
}
// first put on elelment at its correct position(by counting elements less than it), 
// make sure all less than it are before it
int main() {
    int arr[] = {2, 5, 1, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n-1);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    // for (int j = 0; j < n-1; j++){
    //     int ind = arr[j];
    //     int count = 0;
    //     for (int i = 0; i < n; i++){
    //         if(arr[i]<ind) count++;
    //     }
    //     swap(arr[j], arr[count]);
    // }
    // cout<<endl
    return 0;
}
