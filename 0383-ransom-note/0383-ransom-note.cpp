class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(auto i: magazine){
            mp[i]++;
        }
        for(auto i:ransomNote){
            if (mp.find(i) != mp.end() && mp[i] >= 1) {
                mp[i]--;
            }else{
                return false;
            }
        }
        return true;
    }
};