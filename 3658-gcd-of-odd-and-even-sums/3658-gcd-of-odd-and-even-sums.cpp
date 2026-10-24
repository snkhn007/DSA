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
        int cnt = 0, sumEven = 0, sumOdd = 0, i =0;
        while(cnt < n){
            if(i%2 ==0){
                cnt++;
                sumEven += i;
            }
            i++;
        }
        cnt = 0, i = 0;
        while(cnt < n){
            if(i%2 !=0){
                cnt++;
                sumOdd += i;
            }
            i++;
        }
        return Gcd(sumEven, sumOdd);
        
    }
};