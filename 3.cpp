#include<iostream>
using namespace std;
/*
大物实验计算

*/
//小球所走的距离
double L=0.2;
//重力加速度
double g=9.8;
//筒径
double D=0.02;
//p1 p2
double p1=7.8*1e3;
double p2=0.95*1e3;

int main()
{
    //直径
    double d;
    cout<<"please cin d"<<endl;
    cin>>d;
    d=d/1000;
    for(int i=25;i<=55;i=i+5)
    {
        cout<<"Tem = "<<i<<" **********"<<endl;
        double temp_sum=0;
        for(int j=0;j<=4;j++)
        {
            double a;
            cin>>a;
            temp_sum+=a;
        }
        temp_sum/=5;
        cout<<"temp_sum_average = "<<temp_sum<<endl;
        double v=0.2/temp_sum;
        cout<<"v = "<<v<<endl;
        
        //计算结果
        double res=(p1-p2)*g*d*d/(18*v*(1+2.4*d/D));
        //修正
        double R=v*d*p2/res;
        if(R<0.1)
        {
            //nothing
        }else{
            res=res-3.0/16*v*d*p2;
        }
        
        cout<<"Tem = "<<i<<" res = "<<res<<endl;
        if(i==30)
        {   
            cout<<"***Tem = 30***"<<endl;
            cout<<"compare = "<<(1-res/0.451)*100<<endl;
        }
        if(i==40)
        {   
            cout<<"***Tem = 40***"<<endl;
            cout<<"compare = "<<(1-res/0.231)*100<<endl;
        }
    }

    return 0;
}
/*
19.46 19.49 19.41 19.42 19.48
13.28 13.33 13.29 13.28 13.28
9.08 9.22 9.27 9.25 9.23
6.51 6.50 6.49 6.48 6.52
4.75 4.78 4.77 4.79 4.81
3.64 3.66 3.54 3.55 3.62
2.82 2.81 2.78 2.78 2.86
*/