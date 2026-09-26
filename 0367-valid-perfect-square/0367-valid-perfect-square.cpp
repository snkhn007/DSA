class Solution {
public:
    bool isPerfectSquare(int num) {
        int strt = 0, end = num;
        while(strt <= end){
            int mid = (strt+end)/2;
            //  long long int sq = mid* mid;
            long long sq = 1LL * mid * mid;
            if(sq == num) return true;
            else if( sq> num) end = mid-1;
            else strt = mid+1;
        }
        return false;
    }
};