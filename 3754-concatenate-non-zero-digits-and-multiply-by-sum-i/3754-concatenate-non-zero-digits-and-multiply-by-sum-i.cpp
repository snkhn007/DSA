class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        int sum = 0;
        string res = "";
        while(  n> 0){
            int dig = n % 10;
            if(dig != 0){
                sum+= dig;
                res+=to_string(dig);
            }
            n = n / 10;
        }
        reverse(res.begin(), res.end());
        long long ans = 1LL * stoi(res) * sum;
        return ans;
    }
};