#include <iostream>
#include <algorithm>
#include <vector>
/*
奶酪？
*/
using namespace std;

int T;
int n,h,r;
class Point{
    public:
        int x;
        int y;
        int z;
};
//vector<Point> data;
Point data[1010];
bool compare(Point a,Point b);

int main(){

    for(int i=0;i<=6;i++){
        data[i].z=99-i*i;
    }

    sort(data,data+7,compare);
    
    for(int i=0;i<=6;i++){
        cout<<data[i].z<<" ";
    }cout<<endl;
    return 0;
}

bool compare(Point a,Point b){
    return a.z<b.z;
}
