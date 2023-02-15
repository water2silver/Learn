class People{
public:
    int age;
    double height;
    int money;
    //基础构造，析构函数
    People();
    ~People();
    //构造函数重载
    People(int t_age,int t_height);
    //类内加法重载
    //People operator+(const People &temp);
protected:
    long long phone_number;
private:
    bool Have_lover;
};