#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define DATANUM 8
#define HASHTABLENUM 11

typedef struct HashTableNode{
    int data;
    int flag;
}HashTable;

int HashFunctionAlgorithm(int data){//哈希映射函数
    return (3*data)%11;
}

HashTable *CreateHashTableNode(int data, int flag){//新建哈希表节点
    HashTable *p;
    p = (HashTable*)malloc(sizeof(HashTable));
    p->data = data;
    p->flag = flag;
    return p;
}

void GetHashTable(HashTable *HT[], int dataList[]){//构建哈希表
    int position,flag;
    for(int i=0;i<8;i++){
        flag = 1;
        position = HashFunctionAlgorithm(dataList[i]);
        while(HT[position]!=NULL){
            position++;
            flag++;
        }
        HT[position] = CreateHashTableNode(dataList[i], flag);
    }
}

void PutOutAverageSearchLength(HashTable *HT[]){//计算ASL并输出
    int ASL=0;
    for(int i=0;i<11; i++){
        if(HT[i]!=NULL){
            ASL += HT[i]->flag;
            std::cout<<i<<" "<<HT[i]->flag<<std::endl;
        }
    }
    ASL = ASL/8;
    printf("%d\n",ASL);
}

int main(){
    int dataList[DATANUM] = {22,41,53,46,30,13,01,67};//数据列表储存了题中给出的未处理数据
    HashTable *HT[HASHTABLENUM] = {NULL};//由11个哈希节点构成的哈希表
    GetHashTable(HT,dataList);
    PutOutAverageSearchLength(HT);
}

