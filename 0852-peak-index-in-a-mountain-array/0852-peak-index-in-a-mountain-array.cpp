class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int strt = 0, end = arr.size()-1;
        while(strt < end){
            int mid = strt + (end - strt)/2;
            if(arr[mid]<arr[mid+1]) strt = mid+1;
            else end = mid;
        }
        return end;
    }
};