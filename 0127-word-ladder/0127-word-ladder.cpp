class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), lvl = 1;

        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;

        if(st.find(endWord) == st.end()) return 0; // not in vector
        st.erase(beginWord); //removing beginword so that this brach is not explored
        q.push(beginWord);

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
                        if(st.find(temp) == st.end()) continue; //not found in set
                        else{
                            q.push(temp);
                            st.erase(temp);
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