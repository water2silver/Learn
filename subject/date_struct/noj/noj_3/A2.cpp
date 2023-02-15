#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;
/*高精度计算PI
思路：
1.从内部开始循环(如何将循环与链表实现的高精度结合起来呢)，
2.根据公式去寻找思路
完成步骤：
1.双线链表的基本操作
2.找到计算的次数，这很重要
3.大数计算,我要用怎么样的链表来完成怎么样的大数计算

暂时性的思考：
1.好像不用管小数点
2.链表按照数字的顺序存储即可，因为我随时可以在头结点处进行修改，与数组形式的大数算法不同
3.乘法从尾巴处开始，向前进行,注意数位
4.最恶心的大数除法,似乎题目所用的除法不是真正的大数除法，而是高精度除法
5.乘法是真正的大数乘法(舍入方面可能偏麻烦),实在不行再开个大链表来个爽的

细节：
1.N为保留位，即我要取n位，但是我计算n+N位 完成
2.根据公式，找到我要计算的k              完成
3.利用高精度除法（指针存储）解决 k/(2k+1) 的问题 完成
4.解决高精度 大数乘法
5.输出

*/
//保留位
#define N 6

typedef int DataType;

struct DNo_de {
    DataType data;
    struct DNo_de* last;
    struct DNo_de* next;
};
typedef struct DNo_de DNode;
typedef struct DNo_de* PDNode;


struct DLinkList {
    PDNode head;
    PDNode tail;
    int length;
};
typedef DLinkList* PDLinkList;

void Prin(PDLinkList p);
//void Prin_next(PDLinkList p);
PDLinkList Init();
int math_k(int n);
void buildspace(PDLinkList p, int k);//空间分配
void div_PI(PDLinkList psmall, int k);
void mul_array(int a[],int b[],int n);
void mul_PI(PDLinkList p1,PDLinkList p2,int n );

/*自测函数
void test();
void  test02();
void test_mul_PI();*/
int main() {
    //
    clock_t start,end;//定义clock_t变量
    start = clock();//开始时间

    //数据读入与初步简单处理
    int n;
    cin>>n;int k;
    k=math_k(n+N);//超过几位，是结果更加精确
    
    //链表存储div_PI得到的小数
    PDLinkList psmall=Init();//每个个psmall都是小于1/2的
    PDLinkList presult=Init();
    buildspace(psmall,n+N);
    buildspace(presult,n+N);
    for(int i=k;i>=1;i--){
        if(i==k){
            div_PI(presult,i);
            presult->head->data+=2;
        }else{
            div_PI(psmall,i);
            mul_PI(presult,psmall,n+N);
            presult->head->data+=2;            
        }
    }
    PDNode Ptemp=presult->head;
    for(int i=0;i<=n;i++){
        cout<<Ptemp->data;
        Ptemp=Ptemp->next;
        if(i==0) cout<<".";
    }
    //test();
    //test02();
    //test_mul_PU();
    end=clock();
    cout<<"\ntime = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}

PDLinkList Init() {//初始化
    PDLinkList Ptemp = (PDLinkList)malloc(sizeof(DLinkList));//
    Ptemp->head = NULL;
    Ptemp->tail = NULL;
    return Ptemp;
}

void buildspace(PDLinkList p, int k) {
    int i = 1;
    PDNode Ptemp = p->head;
    for (i = 1; i <= k; i++) {//我没有实现连续的存储
        if (i == 1) Ptemp = (PDNode)malloc(sizeof(DNode));
        if (i == 1) {
            p->head = Ptemp;
            Ptemp->last=NULL;
        }

        if (i != k) {
            Ptemp->next = (PDNode)malloc(sizeof(DNode));//这里实现了Ptemp的下一个元素的指定
            Ptemp->next->last=Ptemp;
            Ptemp->next->next = NULL;
        }else {
            Ptemp->next = NULL;
            p->tail=Ptemp;
        }
        Ptemp = Ptemp->next;
    }
}



int math_k(int n) {//根据当前的n，求出k
    double sum = 0; int i = 0;
    while (sum < n + 1) {
        i++;
        sum = sum + log10(2 * i + 1) - log10(i);
    }
    return i;
}


void div_PI(PDLinkList psmall, int k) {//k是相关的内容
    //初始化
    PDNode Ptemp = psmall->head;
    int fenzi = k, fenmu = 2 * k + 1;
    while (Ptemp) {//Ptemp每个位置都是数字，
        //由于k/(2k+1)的特殊性，psmall的第一位是0，也是个位，往后都是小数
        Ptemp->data = fenzi / fenmu;
        fenzi = 10 * (fenzi % fenmu);
        Ptemp = Ptemp->next;
    }
}
void Prin(PDLinkList p) {
    PDNode Ptemp = p->head;
    while (Ptemp) {
        cout << Ptemp->data<<" ";
        Ptemp = Ptemp->next;
    }
    cout << endl;
}
void Prin_next(PDLinkList p){//用来检验双向链表的逆向是否有效
    PDNode Ptemp=p->tail;
    while(Ptemp){
        cout<<Ptemp->data<<" ";
        Ptemp=Ptemp->last;
    }
    cout<<endl;
}

void mul_PI(PDLinkList p1,PDLinkList p2,int n ) {//可能是最难实现的
    //p1*p2，结果放入p1,n是2两个数字有几位
    int temp1[510],temp2[510];
    PDNode Ptemp1=p1->tail;
    PDNode Ptemp2=p2->tail;
    int i=0;
    while(Ptemp1){//读入数组来处理会简单很多
        temp1[i]=Ptemp1->data;
        temp2[i]=Ptemp2->data;
        i++;
        Ptemp1=Ptemp1->last;
        Ptemp2=Ptemp2->last;
    }
    Ptemp1=p1->head;
    mul_array(temp1,temp2,n);
    for(i=n-1;i>=0;i--){
        Ptemp1->data=temp1[i];
        Ptemp1=Ptemp1->next;
    }
}

void mul_array(int a[],int b[],int n){//n表示数组内容的数目
    int i,j,k;
    int temp[1020]={0};
    int bitup=0;
    int height=0;
    for(i=0;i<=n-1;i++){//乘数遍历
        for(j=0;j<=n-1;j++){//被乘数的每次遍历
            temp[j+i]=temp[j+i]+a[j]*b[i]+bitup;//放相乘结果的地方
            bitup=0;
            if(temp[j+i]>=10){
                bitup=temp[j+i]/10;
                temp[j+i]=temp[j+i]%10;
            }
            if(j==n-1){//判断到最后进位情况
                if(i==n-1){
                    height=i+j;
                }
                if(bitup!=0){
                    temp[j+i+1]=bitup;
                    bitup=0;
                    if(i==n-1) height++;
                }
            }            
        }
    }
    while(temp[height]==0) {height--;}
    for(i=n-1;i>=0;i--){
        a[i]=temp[height];
        height--;
    }
}
/*测试函数
void test() {
    int n = 10;
    PDLinkList Ptemp = Init();
    buildspace(Ptemp, n + N);
    int k = 1;
    div_PI(Ptemp, 1);
    Prin(Ptemp);
    Prin_next(Ptemp);
}
void  test02(){
    int t1[]={1,2,3,4};
    int t2[]={5,6,7,8};

    mul_array(t1,t2,4);
    int i;
    for(i=3;i>=0;i--){
        cout<<t1[i];
    }
}
void test_mul_PI(){//貌似能用了
    int n=6;
    int k=math_k(n+N);//超过几位，是结果更加精确

    //链表存储div_PI得到的小数
    PDLinkList psmall=Init();//每个个psmall都是小于1/2的
    PDLinkList presult=Init();
    buildspace(presult,n+N);
    buildspace(psmall,n+N);

    presult->head->data+=2;
    //检测，创建没有问题
    Prin(presult);
    Prin(psmall);


    mul_PI(presult,psmall,n+N);


    PDNode Ptemp=presult->head;
    for(int i=0;i<=n;i++){
        cout<<Ptemp->data;
        if(i==0) cout<<".";
        Ptemp=Ptemp->next;
    }
}

*/