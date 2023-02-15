#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int > v(10);
    cout<<"size = "<<v.size()<<endl;
    cout<<"capacity = "<<v.capacity()<<endl;
    v.resize(20);
    v.push_back(1);
    cout<<"size = "<<v.size()<<endl;
    cout<<"capacity = "<<v.capacity()<<endl;
    
    cout<<v[0]<<endl;
    cout<<v[20]<<endl;
    return 0;
}