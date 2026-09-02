#include <iostream>
#include <vector>
using namespace std;
class Stack{
    public:
    // int *arr;
    vector <int> arr;
    int top;
    // int size;
    Stack(int size){
        // this->size = size;
        // arr = new int[size];
        arr.resize(size);
        top = -1;
    }
    // ~Stack() {
    //     delete[] arr;
    // }
    void push(int val){
        if(top == (int)arr.size()-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        arr[++top] = val;
    }
    void pop(){
        if(top == -1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
    }
    bool empty ()const{
        return top == -1;
    }
    void peek()const{
        if(top > -1 ){
            cout<<arr[top]<<endl;
            return;
        }
        cout<<"Empty Stack"<<endl;
    }
    void display () const{
        if(top == -1){
            cout<<"Empty Stack";
            return;
        }
        int temp = top;
        while ( temp != -1){
            cout<<arr[temp--]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Stack st(5);
    st.push(20);
    st.push(22);
    st.push(24);
    st.push(26);
    st.push(28);

    st.peek();

    st.display();
    
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    
    st.display();

}