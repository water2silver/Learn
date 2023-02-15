#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(){
    int i,j,k;
    char str[10000];
    char date[10000];
    fgets(str,5002,stdin);
    strncpy(date,str,5002);
    int num=strlen(str);
    for(i=0;i<=num-1;i++){//统一大小写
        if(date[i]<='Z'&&date[i]>='A'){
            date[i]=date[i]+32;
        }
    }
    int start=0,end=0;//最后输出的始末
    int s0=0,e0=0;int s1=0,e1=0;
    int sum0=0,sum1=0,sum=0;
    int R0=0,L0=0,L1=0,R1=0;int r0=0,l0=0,r1=0,l1=0;
    for(i=1;i<=num-2;i++){
        if(date[i]==date[i+1]&&date[i]<='z'&&date[i]>='a'){//偶排列出现的前提条件
            for(L0=0,R0=0;;){
                if(i-R0>=0&&i+1+L0<=num-1&&date[i-R0]==date[i+1+L0]&&date[i-R0]<='z'&&date[i-R0]>='a'){
                    s0=i-R0;e0=i+1+L0;//记录这个数据链的开始与结束位置
                    R0++;L0++;
                    r0++;l0++;
                    continue;
                }
                else if(date[i-R0]<'a'||date[i-R0]>'z'&&date[i+1+L0]<'a'||date[i+1+L0]>'z'){//都是标点符号
                    R0++;L0++;
                    continue;
                }
                else if(date[i-R0]<'a'||date[i-R0]>'z'&&date[i+1+L0]<='z'&&date[i+1+L0]>='a'){//左为标点
                    R0++;
                    continue;
                }
                else if(date[i+1+L0]<'a'||date[i+1+L0]>'z'&&date[i-R0]<='z'&&date[i-R0]>='a'){
                    L0++;//右为标点
                    continue;
                }
                else break;
            }
            sum0=r0+l0;//这个字符串的长度
        }
        
        if(date[i-1]==date[i+1]&&date[i-1]<='z'&&date[i-1]>='a'){
            for(L1=0,R1=0;;){
                    if(i-1-R1>=0&&i+1+L1<=num-1&&date[i-1-R1]==date[i+1+L1]&&date[i-1-R1]<='z'&&date[i-1-R1]>='a'){
                        s1=i-1-R1;e1=i+1+L1;
                        R1++;L1++;
                        r1++;l1++;
                        continue;
                    }
                    else if(date[i-1-R1]<'a'||date[i-R1-1]>'z'&&date[i+1+L1]<'a'||date[i+1+L1]>'z'){
                        R1++;L1++;
                        continue;
                    }
                    else if(date[i-R1-1]<'a'||date[i-R1-1]>'z'&&date[i+1+L1]<='z'&&date[i+1+L1]>='a'){
                        R1++;
                        continue;
                    }
                    else if(date[i+1+L1]<'a'||date[i+1+L1]>'z'&&date[i-1-R1]<='z'&&date[i-R1-1]>='a'){
                        L1++;
                        continue;
                    }
                    else break;
                }
            sum1=r1+l1+1;
        }
                
        if(sum0>sum1?sum0:sum1>sum){
                sum=sum0>sum1?sum0:sum1;
                if(sum0>sum1){
                    start=s0;end=e0;
                }
                else{
                    start=s1;end=e1;
                }
            sum0=0;sum1=0;
            r0=0;r1=0;l0=0;l1=0;
            s1=0;e1=0;
            s0=0;e0=0;
        }
    }
    for(i=start;i<=end;i++){
        printf("%c",str[i]);
    }
    return 0;
}











/*
int main(){
    int flag=0;
    int i,j,k,sum=0,w0=0,w1=0;
    char str[10000];
    char date[10000];
    fgets(str,5001,stdin);
    strncpy(date,str,5001);
    int num=strlen(str);
    for(i=0;i<=num-1;i++){//统一大小写
        if(date[i]<='Z'&&date[i]>='A'){
            date[i]=date[i]+32;
        }
    }
    int X;
    //w2 是偶的一侧
    for(i=1;i<=num-1;i++){//从第二字符开始判断
        if(date[i]==date[i+1]&&date[i]>='a'&&date[i]<='z'){//判断偶回文
            for(j=0;;j++){
                if(i-j>=0&&i+1+j<=num-1&&date[i-j]==date[i+1+j]&&date[i]>='a'&&date[i]<='z'){
                    w0=j+1;
                }
                else if (i-j>=0&&i+1+j<=num-1&&(date[i-j]<'a'||date[i-j]>'z')&&(date[i+1+j]<'a'||date[i+1+j]>'z')){
                    continue;
                }
                else {
                    break;
                }
            }
        }//存放一点无用的东西||(date[i-1-j]<'a'||date[i-1-j]>'z'&&(date[i+1+j]<'a'||date[i+1+j]>'z'))
         //||(date[i-j]<'a'||date[i-j]>'z'&&(date[i+j]<'a'||date[i+j]>'z'))
        if(date[i-1]==date[i+1]&&date[i-1]>='a'&&date[i-1]<='z'){
            for(j=0;;j++){
                if(i-1-j>=0&&i+1+j<=num-1&&date[i-1-j]==date[i+1+j]&&date[i-1-j]<='z'&&date[i-1-j]>='a'){
                    w1=j+1;
                }
                else if (i-1-j>=0&&i+1+j<=num-1&&date[i-1-j]<'a'||date[i-1-j]>'z'&&(date[i+1+j]<'a'||date[i+1+j]>'z')){
                    continue;
                }
                else break;

            }

        }
        if(2*w0>2*w1+1?2*w0:2*w1+1>sum){
            sum=2*w0>2*w1+1?w0:w1;
            X=i;
            if(2*w0>2*w1+1) {//0 偶回文，1 奇回文
                flag=0;
            }
            else {
                flag=1;
            }
        }   
        w0=0;w1=0;
    }
    if(flag==0){
        for(i=X-sum+1;i<=X+sum;i++){
            printf("%c",str[i]);
        }
    }else{
        for(i=X-sum;i<=X+sum;i++){
            printf("%c",str[i]);
        }
    }
    return 0;
}*/