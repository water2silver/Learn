#include <iostream>

/*没有上司的舞会
思路:每个节点的值为他本身的值和他子节点最大值的和   X  是直接上司，不能这么考虑


*/
using namespace std;
int n;
int happy[6010];


int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>happy[i];
    }


    return 0;
}