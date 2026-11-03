class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int lvl = 1;
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        if(st.find(beginWord) != st.end()){
            // ie beginWord is in st -> erasing it
            st.erase(beginWord);
        }

        while(!q.empty()){
            int sz = q.size();
            while(sz>0){
                string currWord = q.front();
                q.pop();
                if(currWord == endWord) return lvl;
                string temp = currWord;
                for(int i=0; i<currWord.size(); i++){
                    for(char j='a'; j<='z'; j++){
                        int og = temp[i];
                        temp[i] = j;
                        if(st.find(temp) != st.end()){
                            q.push(temp);
                            st.erase(temp);
                        }
                        temp[i] = og;
                    }                    
                }
                sz--;
            }
            lvl++;
        }
        return 0;
    }
};