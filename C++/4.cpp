#include <iostream>

using namespace std;
#define MKSTR( x ) #x
int main(){
    cout << MKSTR(HELLO C++) << endl;
    cout << MKSTR( (a) )<<endl;
    cout<<__DATE__<<endl;
    return 0;
}