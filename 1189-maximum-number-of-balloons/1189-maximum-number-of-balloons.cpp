class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> mp;
        string str = "balloon";
        for(auto i : str) mp[i] = 0;

        for(auto i: text){
            if(mp.find(i) != mp.end()){
                mp[i]++;
            }
        }
        return min({
            mp['b'], mp['a'], mp['l']/2, mp['o']/2, mp['n']
        });
    }
};