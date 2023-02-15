#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main(){
    char s[1010];
    cin>>s;
    int len=strlen(s);
    int i=0;int res=0;int final=0;
    for(i=0;i<=len-1;i++){
        
        if(s[i]=='('){
            res++;
        }
        if(s[i]==')'){
            res--;
        }
        if(res>final){
            final=res;
        }
    }
    cout<<final<<endl;
    cout<<final<<endl;
    return 0;
}
//((a,b,(c,(d,e),f)),g)