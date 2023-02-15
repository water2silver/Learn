#include <iostream>
#include <queue>

using namespace std;
void print(queue<int> q);

int main(){
    queue<int> q;
    if(q.empty()){
        cout<<"queue is empty"<<endl;
    }

    for(int i=0;i<=5;i++){
        q.push(i*i);
    }

    //输出队列，最先进入队列的元素最先输出
    print(q);
    cout<<"front "<<q.front()<<endl;
    cout<<"back " <<q.back()<<endl;
    q.pop();
    print(q);
    cout<<q.size()<<endl;

    return 0;
}
void print(queue<int> q){

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}