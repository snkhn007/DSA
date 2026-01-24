// Note: An array A rotated by x positions results in an array B of the same length 
// such that B[i] == A[(i+x) % A.length] for every valid index i.

#include <iostream>
#include <vector>
using namespace std;

void rotate(int arr[], int n, int k){
    vector<int> temp(n);
    if(n == 0) return;
    k = k%n;
    for (int i = 0; i < n; i++)
    {
        temp[(k+i)%n] = arr[i];                
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];                
    }
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int k = 3;
    int n = sizeof(arr)/sizeof(int);

    rotate(arr, n, k);
    for(auto e: arr) cout<<e<<" ";
    
}