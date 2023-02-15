#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//7/13;
int main(){
    int i,j,k;
    char str[101];
    int mean[101]={0};
    fgets(str,101,stdin);
    int num=strlen(str);
    for(i=0;i<=num-1;i++){
        if(str[i]==')'){
            for(j=i-1;j>=0;j--){
                if(str[j]=='('&&mean[j]==0){
                    mean[i]=1;
                    mean[j]=1;
                    break;
                }
                else if(str[j]=='['&&mean[j]==0) break;
            }
        }
        if(str[i]==']'){
            for(j=i-1;j>=0;j--){
                if(str[j]=='['&&mean[j]==0){
                    mean[i]=1;
                    mean[j]=1;
                    break;
                }
                else if(str[j]=='('&&mean[j]==0) break;
            }
        }
    }
    for(i=0;i<=num-1;i++){
        if(mean[i]==1){
            printf("%c",str[i]);
        }
        else{
            if(str[i]=='(') printf("()");
            if(str[i]==')') printf("()");
            if(str[i]=='[') printf("[]");
            if(str[i]==']') printf("[]");
        }
    }
return 0;}