class Solution {
public:
    int search(vector<string>& nums, string target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if(it != nums.end() && *it == target) {
            return it - nums.begin();
        }
        return -1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), lvl = 1;
        sort(wordList.begin(), wordList.end());
        if(search(wordList, endWord) == -1) return 0;

        vector<bool> vis(n+1, false);
        
        int beginIndex = search(wordList, beginWord);
        if(beginIndex != -1) {
            vis[beginIndex + 1] = true;
        }

        queue<string> q;
        q.push(beginWord);
        vis[0] = true;

        while(!q.empty()){
            int sz = q.size();
            while(sz>0){
                string curr = q.front();
                q.pop();

                for(int i=0; i<curr.size(); i++){
                    string temp = curr;

                    for(char j= 'a'; j<='z'; j++){
                        temp[i] = j;
                        if(temp == endWord) return lvl+1;

                        int index = search(wordList, temp);
                        if(index == -1) continue;
                        if(!vis[index+1]){
                            q.push(temp);
                            vis[index+1] = true;
                        }
                    }
                }
                sz--;
            }
            lvl++;
        }

        return 0;
    }
};