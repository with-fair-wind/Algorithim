#include <iostream>

using namespace std;

class BitMap
{
private:
    long long * bits;

public:
    BitMap(int max);
    ~BitMap() { if (bits) delete[] bits;}
    void addNum(int num) { bits[num >> 6] |= (1LL << (num & 63)); } // num % 64 == num & 63(仅限于2的倍数取余)
    void deleteNum (int num) { bits[num >> 6] &= ~(1LL << (num & 63)); }
    bool containNum(int num) { return (bits[num >> 6] & (1LL << (num & 63))) != 0; }
};

BitMap::BitMap(int max)
{
    bits = new long long[(max + 64) >> 6]; 
}

int my_sum(int a, int b);
int negNum(int n);
int my_minus(int a, int b);
int my_multi(int a, int b);
void printInteger(int num); //打印整数32位
bool isNeg(int num);
int my_div(int a, int b);
int my_divide(int a, int b);

int main(void)
{
    cout << my_sum(-7, 5) << endl;
    cout << my_multi(-2, -5) << endl;
    printInteger(((unsigned int)(-5)) >> 1);
    cout << my_divide(20, 7) << endl;
    
    return 0;
}

//打印整数32位
void printInteger(int num)  
{
    for (int  i = 31; i >= 0; i--)
    {
        cout << (((num & (1 << i)) == 0) ? "0" : "1");
    }
    cout << endl;
}

// 位运算实现加法(a+b)
int my_sum(int a, int b)
{
    int sum = a;            
    while (b != 0)
    {
        sum = a ^ b;        //无进位相加信息->sum
        b = (a & b) << 1;   //进位信息-> b->b'
        a = sum;            //更新a->a'无进位相加信息，这一步不能写到上一步之前
    }
    return sum;
    
    //return b == 0 ? a : Sum(a ^ b, (a & b) << 1);
    
}

// 位运算实现减法运算(a-b)==(a+(-b))
int negNum(int n)
{
    return my_sum(~n, 1);
}

int my_minus(int a, int b)
{
    return my_sum(a, negNum(b));
}

// 位运算实现乘法运算
int my_multi(int a, int b)
{
    int res = 0;
    unsigned int cur = (unsigned int)b;
    while (cur ^ 0)         // != 可以用异或 ^ 代替
    {
        if (cur & 1)
            res = my_sum(a, res);
        a = a << 1;
        cur = cur >> 1;        //不带符号右移
    }
    return res;
}

// 位运算实现除法(a/b)
bool isNeg(int num)
{
    return num < 0;
}

int my_div(int a, int b)
{
    int x = isNeg(a) ? negNum(a) : a;
    int y = isNeg(b) ? negNum(b) : b;
    int res = 0;
    for (int i = 30; i >= 0; i--)
    {
        if ((x >> i) >= y)
        {
            res |= (1 << i);
            x = my_minus(x, (y << i));
        }
    }
    return isNeg(a) ^ isNeg(b) ? negNum(res) : res;
}

int my_divide(int a, int b)
{
    if(a == INT_MIN && b == INT_MIN)
        return 1;
    else if(b == INT_MIN)
        return 0;
    else if(a == INT_MIN)
    {
        if(b == -1)
            return INT_MAX;
        else
        {
            int ans = my_div(my_sum(a, 1), b);
            return my_sum(ans, my_div(my_minus(a, my_multi(ans, b)), b));
        }            
    }
    else
        return my_div(a, b);
}