#include <iostream>
#include <string>
#include <climits>

using namespace std;

struct MyException
{
    MyException(string s) :msg(s) {}
    string msg;
};

double divisionMethod(int a, int b) /*throw(MyException, int)*/ noexcept
{
    if (b == 0)
    {
        //throw MyException("division by zero!!!");
        //throw 100;
        cout << "division by zero!!!" << endl;
        return -1;
    }
    return a / b;
}

void TestCatch()
{

        double v = divisionMethod(100, 0);
        cout << "value: " << v << endl;
    
    // catch (int e)
    // {
    //     cout << "catch except: "  << e << endl;
    // }
    // catch (MyException e)
    // {
    //     cout << "catch except: " << e.msg << endl;
    // }
}

int main(void)
{
    string str1 = R"hello(D:\Hello\World\test.cpp)hello";
    cout << str1 << endl;

    string str2 = R"(<html>
                    <head>
                    <title>
                    kk
                    /body)";
    cout << str2 << endl;

    string str3 = "<html>\
                    <head>\
                    <title>\
                    kk\
                    /body";
    cout << str3 << endl;

    long long llmax = LLONG_MAX;
    long long llmin = LLONG_MIN;
    unsigned long long ullmax = ULLONG_MAX;

    cout << "long long max: " << llmax << ", long long min: " << llmin << ", unsigned long long max: " << ullmax << endl;

    string st1 = "45";
    string st2 = "3.14159";
    string st3 = "9527 with words";
    string st4 = "words and 2";

    int myint1 = std::stoi(st1);
    float myint2 = std::stof(st2);
    int myint3 = std::stoi(st3);
    // 错误： 'std::invalid_argument'
    // int myint4 = std::stoi(str4);

    cout << "std::stoi(\"" << st1 << "\") is " << myint1 << endl;
    cout << "std::stof(\"" << st2 << "\") is " << myint2 << endl;
    cout << "std::stoi(\"" << st3 << "\") is " << myint3 << endl;
    // cout << "std::stoi(\"" << str4 << "\") is " << myint4 << endl;

    TestCatch();
    
    return 0;
}
