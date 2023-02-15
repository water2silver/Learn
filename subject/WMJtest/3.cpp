#include  <stdio.h>
#include  <string.h>

int sum_num(char *t);
int check_seven(int *t,int pos);
void test01(int *t,int pos);

int main(){
    char data[50];int num[50];
    scanf("%s",data);
    int sym[10]={0};
    int len=strlen(data);int temp=0;
    for(int i=0;i<=len-1;i++){
        num[i]=data[i]-'0';
    }

    //最后一位为2，则可以被2整除
    if(num[len-1]%2==0){
        sym[2]=1;
    }
    //3
    temp=sum_num(data);
    if(temp%3==0){
        sym[3]=1;
    }
    //4
    if(len>=2) temp=num[len-1]+num[len-2]*10;
    else{temp=num[len-1];}
    if(temp%4==0){
        sym[4]=1;
    }
    //5
    if((num[len-1])==0||(num[len-1])==5){
        sym[5]=1;
    }
    //6
    if(sym[2]&&sym[3]){
        sym[6]=1;
    }
    //7在最后


    //8
    //注意位数
    if(len>=3) temp=num[len-1]+num[len-2]*10+num[len-3]*100;
    else if(len==2) temp=num[len-1]+num[len-2]*10;
    else temp=num[len-1];
    if(temp%8==0) sym[8]=1;

    //9
    temp=sum_num(data);
    if(temp%9==0) sym[9]=1;
    //7放到最后吧
    
    temp=check_seven(num,len-1);

    if(temp==1){
        sym[7]=1;
    }
    int sum=0;
    for(int i=2;i<=9;i++){
        if(sym[i]==1) printf("%d ",i);
        sum=sum+sym[i];
    }
    if(sum==0) printf("none");
    return 0;
}

int sum_num(char *t){
    int i=0;int res=0;
    for(i=0;i<=strlen(t)-1;i++){
        res+=t[i]-'0';
    }
    return res;
}

int check_seven(int *t,int pos){//检查‘7’
    int not_zero=0;int i=0;
    for(i=0;i<=pos;i++){//计算首位非0数字的位置
        if(t[i]==0) not_zero++;
        else break;
    }
    int res=0;
    if((pos-not_zero)<=0){//pos，not_zero 均为下标，
        if(t[pos]%7==0) res=1;///注意到底是要判断哪个位置是否被7整除
        else res=0;
    }else if(pos-not_zero>=1){
        t[pos-1]=t[pos-1]-2*t[pos];
        for(i=pos-1;i>=not_zero;i--){
            if(t[i]<0&&i!=0){
                while(t[i]<0){
                    t[i]=t[i]+10;
                    t[i-1]--;
                }
                
            }
            if(t[0]<0&&i==0) {
                while(t[i]<0){
                    t[i]=t[i]+7;
                }
            }
        }
        //test
        
        res=check_seven(t,pos-1);
    }
    return res;
}

void test01(int *t,int pos){
    for(int u=0;u<=6;u++){
        if(u==0) {
            printf("pos=%d ",pos);
        }
        printf("%d ",t[u]);
        if(u==6) printf("\n");
    }
}