#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
 
typedef struct BinTreeNode
{
    char data;
    struct BinTreeNode *lchild;
    struct BinTreeNode *rchild;
}BinTree, *PBinTree;
 
char pre[50],mid[50];
PBinTree CreateBinTree(int pre_start,int pre_end,int mid_start,int mid_end)
{
    PBinTree root = (PBinTree)malloc(sizeof(BinTree));
    root->data=pre[pre_start];
    root->lchild=NULL;
    root->rchild=NULL;
    int i;
    i=mid_start;
    while(mid[i]!=root->data)
        i++;
 
    int LTreeLen=i-mid_start;
    int RTreeLen=mid_end-i;
    if(LTreeLen)
    {
        root->lchild=CreateBinTree(pre_start+1,pre_start+LTreeLen,mid_start,i-1);
    }
    if(RTreeLen)
    {
        root->rchild=CreateBinTree(pre_start+LTreeLen+1,pre_end,i+1,mid_end);
    }
    return root;
}
 
void PrintBinTree (PBinTree p)
{
    if(p->lchild)
    {
        PrintBinTree(p->lchild);
    }
    if(p->rchild)
    {
        PrintBinTree(p->rchild);
    }
    printf("%c",p->data);
}
 
PBinTree Algo()
{
    int len_pre,len_mid;
    PBinTree T;
    len_pre=strlen(pre);
    len_mid=strlen(mid);
    T=CreateBinTree(0,len_pre-1,0,len_mid-1);
    return T;
}
int main()
{
    gets(pre);
    gets(mid);
    PBinTree T;
    T = Algo();
    PrintBinTree(T);
    return 0;
}