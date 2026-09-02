// [6,5,4,3,2,1,7]
#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;
int main(){
    stack <int> st;
    vector <int> arr = {6,5,4,3,2,1,7};
    map <int,int> mp;
    int n = arr.size();
    // ans.resize(n);

    for(int i=n-1; i>=0; i--){
        if(st.empty()){
            mp[i] = -1;
            st.push(arr[i]);
        }
        else if( st.top() > arr[i]){
            mp[i] = st.top();
            st.push(arr[i]);
        }
        else if(st.top() < arr[i]){
            while(!st.empty() && st.top()<arr[i]){
                st.pop();
            }
            mp[i] = st.top();
            st.push(arr[i]);
        }
    }

    for(auto i: mp){
        cout<<i.first<<"->"<<i.second<<endl;
    }

    cout<<mp[2];
}