#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main(){
    string s = "sanasan";
    unordered_map <char, bool> mp;
       for(int i=0; i<s.length(); i++){
        mp[s[i]] = false;
       }

    for(auto i: mp){
        cout<<i.first<<" -> "<<i.second<<endl;
    }
}