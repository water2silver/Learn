//
//  main.cpp
//  �ַ�����С����
//
//  Created by Allen on 2019/4/18.
//  Copyright ? 2019 Allen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int count(){
    string stringA,stringB;
    cout<<"�������һ���ַ�����";
    cin>>stringA;
    cout<<"������ڶ����ַ�����";
    cin>>stringB;
    int Alength = stringA.length()+1;
    int Blength = stringB.length()+1;
    int dp[Alength][Blength],i,j,temp;
    for (i=0; i<Alength; i++) {//���г�ʼ��
        dp[i][0]=i;
    }
    for (i=0; i<Blength; i++) {//���г�ʼ��
        dp[0][i]=i;
    }
    for (i=1; i<Alength; i++) {
        for (j=1; j<Blength; j++) {
            //���Ĵ��벿��
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
    cout<<"���ٲ�������Ϊ��"<<dp[Alength-1][Blength-1]<<endl;
    return 0;
}

int main() {
    int n ;
    while (cin>>n&&n!=0) {
        count();
    }
    return 0;
}
