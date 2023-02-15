#include <iostream>
#include <stack>

using namespace std;
void print(stack<int> q);

int main(){
    stack<int> s;
    
    if(s.empty()){
        cout<<"s is empty"<<endl;
    }

    for(int i=0;i<=5;i++){
        s.push(i*i);
    }
    //先输出栈顶的元素，即刚加入的元素
    print(s);
    s.pop();
    print(s);
}
void print(stack<int> q){
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}