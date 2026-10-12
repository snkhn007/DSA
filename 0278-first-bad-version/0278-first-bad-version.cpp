// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int strt = 0, end = n; 
        while(strt <= end){
            // int mid = strt + (strt - end) / 2;
            int mid = strt + (end - strt) / 2;
            if(isBadVersion(mid)) end = mid - 1;
            else strt = mid+1;
        }
        return strt;
    }
};