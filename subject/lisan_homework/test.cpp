#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
 
//输出空行
void OutPutAnEmptyLine()
{
    cout<<"\n";
}
 
//读取方式: 逐词读取, 词之间用空格区分
//read data from the file, Word By Word
//when used in this manner, we'll get space-delimited bits of text from the file
//but all of the whitespace that separated words (including newlines) was lost. 
void ReadDataFromFileWBW()
{
    ifstream fin("test.txt");  
    string s1,s2;  
    while( fin >> s1>>s2 ) 
    {    
        cout << "Read from file: " << s1<<" "<<s2 << endl;  
    }
}

int main(){
    cout<<"���"<<endl;
    return 0;

}