class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int cnt = 0;
        for(auto i : jewels){
            for(auto j:stones){
                if(j == i) cnt++;
            }
        }
        return cnt;
    }
};