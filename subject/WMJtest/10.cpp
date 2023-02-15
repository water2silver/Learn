#include <stdio.h>
#include <string.h>
int main(){
    int writer[27][1010]={0};
    int rank[27]={0};int max=0;
    int m,i,j;
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        int n;char s[27];int len;
        scanf("%d %s",&n,s);
        len=strlen(s);
        for(j=0;j<=len-1;j++){
            writer[s[j]-'A'][rank[s[j]-'A']]=n;
            rank[s[j]-'A']++;
            //没有注意到字典序的问题
            if(rank[s[j]-'A']>rank[max]){
                max=s[j]-'A';
            }else if(rank[s[j]-'A']==rank[max]){
                if(s[j]-'A'<max){
                    max=s[j]-'A';
                }
            }
        }
    }
    printf("%c\n",'A'+max);
    printf("%d\n",rank[max]);
    for(i=0;i<=rank[max]-1;i++){
        printf("%d\n",writer[max][i]);
    }
    return 0;

}