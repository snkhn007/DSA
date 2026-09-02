#include <iostream>
#include <vector>
using namespace std;
vector<int> rotate(vector <int>arr, int k){
    int n = arr.size();
    vector <int> temp(n);
    k = k%n;

    for(int i=0; i<n; i++){
        temp[(i - k + n) % n] = arr[i];
    }
    return temp;
}
int main(){
    vector<int>nums = {1,-2,3,-4};
    vector <int> vals;
    vector <int> indx;
    int k = 3;

    for(int i=0; i<nums.size(); i++){
        if(nums[i]>=0){
            vals.push_back(nums[i]);
            indx.push_back(i);
        }
    }
    // for(int i=0; i<vals.size(); i++){
    //     cout<<vals[i]<<" "<<endl;
    // }
    // for(int i=0; i<vals.size(); i++){
    //     cout<<indx[i]<<" "<<endl;
    // }
    vals = rotate(vals, k);
    for(int i=0; i<vals.size(); i++){
        int index = indx[i];
        nums[index] = vals[i];
    }  
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }                 
}