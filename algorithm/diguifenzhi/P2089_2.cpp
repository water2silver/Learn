#include <iostream>

using namespace std;
#define FOR(x) for(int x=1;x<=3;x++)
/*
我一直在寻找很高级的思路，最后确实最简单的做法就能解决
还有题解的思路是从第一个位置开始for循环，dfs(cnt,left),分别表示还有还有几个位置以及当前剩下的n值，也是也简单的思路
*/

int n;
int cent;
int main(){
    cin>>n;
    int a,b,c,d,e,f,g,h,i,j;
    FOR(a){
        FOR(b){
            FOR(c){
                FOR(d){
                    FOR(e){
                        FOR(f){
                            FOR(g){
                                FOR(h){
                                    FOR(i){
                                        FOR(j){
                                            if(a+b+c+d+e+f+g+h+i+j==n){
                                                cent++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<cent<<endl;
    FOR(a){
        FOR(b){
            FOR(c){
                FOR(d){
                    FOR(e){
                        FOR(f){
                            FOR(g){
                                FOR(h){
                                    FOR(i){
                                        FOR(j){
                                            if(a+b+c+d+e+f+g+h+i+j==n){
                                                cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<" "<<i<<" "<<j<<" "<<endl;;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

