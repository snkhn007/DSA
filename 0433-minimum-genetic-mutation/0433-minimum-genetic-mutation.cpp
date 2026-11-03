class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        if(st.find(startGene) != st.end()) st.erase(startGene);
        if(st.find(endGene) == st.end()) return -1;

        char dx[] = {'A', 'C', 'G', 'T'};

        queue<string> q;
        q.push(startGene);

        int lvl = 0;

        while(!q.empty()){
            int sz = q.size();
            while(sz>0){
                string node = q.front();
                q.pop();
                if(node == endGene) return lvl;
                string temp = node;
                for(int i=0; i<node.size(); i++){
                    for(auto j: dx){
                        char og = temp[i];
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
        return -1;
    }
};