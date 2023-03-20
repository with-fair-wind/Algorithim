#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

uniform_real_distribution<double> u(0, 1);
default_random_engine e(time(NULL));

int xToXPower2();
int f1() { return (rand() % 5) + 1; }   //lib里的不能改(前提)   等概率随机返回[1,5]
int f2();
int f3();
int f4();
int g();    //最后实现从f1(黑盒不能改)范围(1~5)的等概率随机到新的范围(1~7)的等概率随机
            //推广:如果要实现从a~b的等概率随机到c~d的等概率随机也是同样思路
            //先将a~b的等概率随机变为0~1的等概率随机，再看c~d的在多少个二进制位范围内，转化为每一位上的随机，然后转换为0~d-c上随机
            //最后转化为c~d上随机
int x();
int y();

int main(int argc, char *argv[])
{
    srand(int(time(0)));    // srand()函数产生一个以当前时间开始的随机种子，且time的值每时每刻都不同。所以种子不同
    int testTimes = 10000000;
    
    ///////////////////////////
    int counts1[] = {0, 0 , 0, 0 , 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < testTimes; i++)
        counts1[rand() % 10]++;
    for (int i = 0; i < 10; i++)
        cout << i << "出现了" << counts1[i] << "次" << endl;

    ///////////////////////////
    int count = 0;
    for (int i = 0; i < testTimes; i++)
    {
        if (rand() % 10 < 5)
            count++;
    }
    cout << double(count) / double(testTimes) << endl;

    ///////////////////////////
    count = 0;
    for (int i = 0; i < testTimes; i++)
    {
        if (xToXPower2() < 5)   //因为是max所以每次rand() % 10都必须满足这个小于条件
            count++;
    }
    cout << double(count) / double(testTimes) << endl;

    ///////////////////////////
    count = 0;
    for (int i = 0; i < testTimes; i++)
    {
        if (f2() == 0)
            count++;
    }
    cout << double(count) / double(testTimes) << endl;

    ///////////////////////////
    int counts2[] = {0, 0 , 0, 0 , 0, 0, 0, 0};
    for (int i = 0; i < testTimes; i++)
        counts2[g()]++;
    for (int i = 0; i < 8; i++)
        cout << i << "出现了" << counts2[i] << "次" << endl;

    count = 0;
    for (int i = 0; i < testTimes; i++)
    {
        if (y() == 0)
            count++;
    }
    cout << double(count) / double(testTimes) << endl;
    
}

// [0，x)范围上出现的数的概率由原来的x变为x平方
int xToXPower2()
{
    return max(rand() % 10, rand() % 10);
}

//随机机制，只能用f1
//等概率返回0和1
int f2()
{
    int ans;
    do
    {
        ans = f1();
    } while (ans == 3);
    return ans < 3 ? 0 : 1;
}

/// 得到000~111做到等概率 即0~7等概率随机
int f3()
{
    return ((f2() << 2) + (f2() << 1) + f2());
}

/// 0~6等概率返回一个
int f4()
{
    int ans = 0;
    do
    {
        ans = f3();
    } while (ans == 7);
    return ans;
}

int g()
{
    return f4() + 1;
}

// 你只能知道，x会以固定概率返回0和1，但是这个固定概率p，你看不到！
int x()
{
    return u(e) < 0.84 ? 0 : 1;
}

//等概率返回0~1     p(1-p) == (1-p)p
int y()
{
    int ans = 0;
    do
    {
        ans = x();
    } while (ans == x());
    // ans 0 1
    // ans 1 0
    return ans;
}