class Solution {
public:
    int Gcd(int sumEven, int sumOdd){
        int mn = min(sumEven, sumOdd);
        int mx = max(sumEven, sumOdd);
        for(int i=mn; i>0; i--){
            if(mn%i == 0 && mx%i==0) return i;
        }
        return 1;
    }
    int gcdOfOddEvenSums(int n) {        
        // return Gcd(n*(n+1), n*n);
        return n;
        
    }
};