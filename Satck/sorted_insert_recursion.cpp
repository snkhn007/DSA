#include <iostream>
#include <stack>
using namespace std;

// Time complexity: O(n²)
// Space complexity: O(n) (recursion stack)
// This is optimal given the constraints of using only a stack and recursion.

void sortedInsert(stack<int> &st, int k){
	if(st.empty() || st.top() < k){
		st.push(k);
		return;
	}

	int temp = st.top();
    st.pop();
    sortedInsert(st, k);

    st.push(temp);
    return;		

}
void getEl(stack<int> &st){
	if(st.empty()){
		return;
	}
	int temp = st.top();
	st.pop();
	getEl(st);
	sortedInsert(st, temp);
	return;
}
int main(){
    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(6);
    st.push(5);

    getEl(st);   //sort the stack

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}
