#include <iostream>
#include<math.h>
using namespace std;
/*一个跟乒乓球规则计分的一个题目，重在理解题意，设置合理的输入输出*/
char data[62590];
void show(int n){
    int a=0;int b=0;
    int i=0;
    while(data[i]!='E'){
        if(data[i]=='W'){
            a++;
        }else if(data[i]=='L'){
            b++;
        }
        if((a>=n||b>=n)&&(abs(a-b)>=2)){
            cout<<a<<":"<<b<<endl;
            a=0;b=0;
        }
        i++;
    }
    cout<<a<<":"<<b<<endl;
    if(n==11){
        cout<<endl;
    }
}

int main(){
    int i=0;

    char ch;
    while(cin>>ch&&ch!='E'){
        if(ch=='W'||ch=='L')
            data[i++]=ch;
    }
    data[i]=ch;
    show(11);
    show(21);

    return 0;
}