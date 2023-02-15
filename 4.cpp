//
//  main.cpp
//  字符串最小操作
//
//  Created by Allen on 2019/4/18.
//  Copyright ? 2019 Allen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int count(){
    string stringA,stringB;
    cout<<"请输入第一个字符串：";
    cin>>stringA;
    cout<<"请输入第二个字符串：";
    cin>>stringB;
    int Alength = stringA.length()+1;
    int Blength = stringB.length()+1;
    int dp[Alength][Blength],i,j,temp;
    for (i=0; i<Alength; i++) {//对列初始化
        dp[i][0]=i;
    }
    for (i=0; i<Blength; i++) {//对行初始化
        dp[0][i]=i;
    }
    for (i=1; i<Alength; i++) {
        for (j=1; j<Blength; j++) {
            //核心代码部分
            temp = min(dp[i][j-1]+1, dp[i-1][j]+1);
            dp[i][j]=min(temp,dp[i-1][j-1]+(stringA[i-1]==stringB[j-1]?0:1));
        }
    }
    for (i=0; i<Alength; i++) {
        for (j=0; j<Blength; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"最少操作次数为："<<dp[Alength-1][Blength-1]<<endl;
    return 0;
}

int main() {
    int n ;
    while (cin>>n&&n!=0) {
        count();
    }
    return 0;
}
