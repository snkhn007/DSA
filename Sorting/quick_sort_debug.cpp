#include <iostream>
using namespace std;
int partition(int arr[], int strt, int end){
    int pivot = arr[strt];
    int index = 0;
    for (int i = strt; i <= end; i++)
    {
        if(arr[i]<pivot) index++;
    }
    swap(arr[index+strt], arr[strt]);
    cout<<"After putting pivot "<<pivot<<" at its correct posoition ie "<<index<<": ";
    for (int i = strt; i <= end; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int i=strt, j=end;
    while(i<strt+index && j>strt+index){
        if(arr[i]<pivot) i++;
        else if(arr[j]>=pivot) j--;
        else swap(arr[i++], arr[j--]);
    }
    cout<<"After swapping all at correct positions: ";
    for (int i = strt; i <= end; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return strt+index;    
}

void quickSort(int arr[], int strt,  int end){
    if(strt >= end) return;
    int p = partition(arr, strt, end);
    quickSort(arr, strt, p-1);
    quickSort(arr, p+1, end);
}
int main() {
    int arr[] = {2, 3, 0, 1, 4, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    cout<<endl;

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
