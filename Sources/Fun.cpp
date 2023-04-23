#include "Fun.h"

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void printArray(const vector<int> &arr)
{
    for (const auto &tmp : arr)
        cout << tmp << " ";
    cout << endl;
}

void swap_bit(int arr[], int i, int j)
{ // 如果i == j, 自己异或自己直接置零了
    if (i != j)
    {
        arr[i] ^= arr[j];
        arr[j] ^= arr[i];
        arr[i] ^= arr[j];
    }
}

void swap_arr(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

bool isSorted(int *arr, int size)
{
    if (arr == nullptr || size <= 0)
        return false;
    int Max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < Max)
            return false;
        Max = arr[i];
    }
    return true;
}

void printInteger(int num)
{
    for (int i = 31; i >= 0; i--)
        cout << (((num & (1 << i)) == 0) ? "0" : "1");
    cout << endl;
}

int MaxInArr(int *arr, int L, int R)
{
    if (L == R)
        return arr[L];
    int mid = L + ((R - L) >> 1);
    int leftMax = MaxInArr(arr, L, mid);
    int rightMax = MaxInArr(arr, mid + 1, R);
    return leftMax < rightMax ? rightMax : leftMax;
}

int Extract1OddNum(int *arr, int size)
{
    int res = 0;
    for (int i = 0; i < size; i++)
        res ^= arr[i];
    return res;
}

pair<int, int> Extract2OddNum(int *arr, int size)
{
    int res1 = 0, res2 = 0;
    for (int i = 0; i < size; i++)
        res1 ^= arr[i];
    int rightOne = res1 & (~res1 + 1);
    for (int i = 0; i < size; i++)
    {
        if ((arr[i] & rightOne) == 0)
            res2 ^= arr[i];
    }
    res1 ^= res2;
    return make_pair(res1, res2);
}

bool findNumInSortedArr(int *arr, int num, int L, int R)
{
    if (arr == nullptr || L > R)
        return false;
    while (L <= R)
    {
        int mid = L + ((R - L) >> 1);
        if (arr[mid] == num)
            return true;
        else if (arr[mid] < num)
            L = mid + 1;
        else
            R = mid - 1;
    }
    return false;
}

int mostLeftNoMoreNumIndex(int *arr, int num, int L, int R)
{
    if (arr == nullptr || L > R)
        return false;
    int res = -1;
    while (L <= R)
    {
        int mid = L + ((R - L) >> 1);
        if (arr[mid] >= num)
        {
            // 把mid抓出来，砍掉右边，但是左边半区还可能存在>=num的数
            R = mid - 1;
            res = mid;
        }
        else
            L = mid + 1;
    }
    return res;
}

int oneMinIndex(int *arr, int size)
{
    if (arr == nullptr || size == 0)
        return -1;
    if (size == 1)
        return 0;

    if (arr[0] < arr[1])
        return 0;
    if (arr[size - 1] < arr[size - 2])
        return size - 1;

    int L = 0, R = size - 1;
    // 保证三个数之间比较(mid - 1, mid, mid + 1不越出[L,R])
    while (L < R - 1)
    {
        int mid = L + ((R - L) >> 1);
        if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1])
            return mid;
        else
        {
            if (arr[mid] > arr[mid - 1])
                R = mid - 1;
            else
                L = mid + 1;
        }
    }
    // L与R相邻时
    return arr[L] < arr[R] ? L : R;
}

void CreateArrDuiShuQi(int testTimes, int maxSize, int maxValue, void (*pt1)(int *arr, int size), void (*pt2)(int *arr, int size), void (*pt3)(int *arr, int L, int R), void (*pt4)(int *arr, int L, int R))
{
    srand(time(nullptr));
    bool success = true;
    for (int i = 0; i < testTimes; i++)
    {
        int size = rand() % maxSize + 1;
        int *arr_v1 = new int[size];
        int *arr_v2 = new int[size];
        for (int j = 0; j < size; j++)
            arr_v1[j] = rand() % (maxValue + 1) - rand() % (maxValue + 1);
        // 桶排序的实现针对非负数
        // arr_v1[j] = rand() % (maxValue + 1);
        for (int j = 0; j < size; j++)
            arr_v2[j] = arr_v1[j];
        if (pt1 != nullptr && pt2 != nullptr)
        {
            pt1(arr_v1, size);
            pt2(arr_v2, size);
        }
        if (pt3 != nullptr && pt4 != nullptr)
        {
            pt3(arr_v1, 0, size - 1);
            pt4(arr_v2, 0, size - 1);
        }
        printArray(arr_v1, size);
        printArray(arr_v2, size);
        for (int j = 0; j < size; j++)
        {
            if (arr_v1[j] != arr_v2[j])
            {
                success = false;
                delete[] arr_v1;
                delete[] arr_v2;
                arr_v1 = nullptr;
                arr_v2 = nullptr;
                break;
            }
        }
        delete[] arr_v1;
        delete[] arr_v2;
        arr_v1 = nullptr;
        arr_v2 = nullptr;
    }
    cout << (success ? "Right" : "Wrong") << endl;
}

int ZorOneGetEqualProbability(int L, int R)
{
    srand(time(nullptr));
    int range = R - L + 1;
    bool isOdd = range % 2 != 0 ? true : false;
    int res = -1, tmp = L + ((R - L) >> 1);
    do
        res = rand() % (R - L + 1) + L;
    while (isOdd && res == tmp);
    return isOdd ? (res < tmp ? 0 : 1) : (res <= tmp ? 0 : 1);
}

int Range2RangeEqualProbability(int a, int b, int c, int d)
{
    //[c, d]->[0, d-c],判断d-c有几个二进制位
    int ConvertNum = d - c, maxBit = 0;
    while (ConvertNum)
    {
        maxBit++;
        ConvertNum >>= 1;
    }
    int res = 0;
    do
    {
        // 实现[0, 2^maxbit - 1]上等概率，二进制每一位都等概率随机
        for (int i = 0; i < maxBit; i++)
            res += ZorOneGetEqualProbability(a, b) << i;
    } while (res <= d - c); // 实现[0, d-c]上等概率随机
    return res + c;         // 实现[c, d]上等概率随机
}

int NoEqual2EqualReturnZorOne()
{
    uniform_real_distribution<double> u(0, 1);
    default_random_engine e(time(nullptr));
    int res = 0;
    // p(1-p) == (1-p)p
    do
        res = u(e) < FIXED_PROBABILITY ? 0 : 1;
    while (res == (u(e) < FIXED_PROBABILITY ? 0 : 1));
    return res;
}

double xToPower2()
{
    uniform_real_distribution<double> u(0, 1);
    default_random_engine e(time(nullptr));
    return max(u(e), u(e)); // 两个u(e)都<x时，max后才<x所以<x的概率变成x^2了
}

void CreateMedianDuiShuQi(int testTimes, int maxSize, int maxValue, double (*pt1)(std::vector<int> &vec), double (*pt2)(std::vector<int> &vec))
{
    srand(time(nullptr));
    bool success = true;
    for (int i = 0; i < testTimes; i++)
    {
        int size = rand() % maxSize + 1;
        vector<int> vec1, vec2;
        for (int j = 0; j < size; j++)
            vec1.push_back((rand() % maxValue + 1) - (rand() % maxValue + 1));
        for (const auto &num : vec1)
            vec2.push_back(num);
        double m1 = pt1(vec1);
        double m2 = pt2(vec2);
        success = m1 == m2 ? true : false;
        if (!success)
        {
            cout << "m1: " << m1 << " m2: " << m2 << endl;
            break;
        }
    }
    cout << (success ? "today is a beautiful day^_^" : "Oops..what a fuck!") << endl;
}

void CreateGetNearLessDuiShuQi(int testTimes, int maxSize, int maxValue, void (*pt1)(vector<pair<int, int>> &res, const vector<int> &arr), void (*pt2)(vector<pair<int, int>> &res, const vector<int> &arr))
{
    srand(time(nullptr));
    bool success = true;
    for (int i = 0; i < testTimes; i++)
    {
        int size = rand() % maxSize + 1;
        vector<pair<int, int>> res1(size);
        vector<pair<int, int>> res2(size);
        vector<int> arr;
        for (int j = 0; j < size; j++)
            arr.push_back(rand() % (maxValue + 1) - rand() % (maxValue + 1));
        pt1(res1, arr);
        pt2(res2, arr);
        if (res1 != res2)
        {
            success = false;
            printArray(arr);
            break;
        }
    }
    cout << (success ? "today is a beautiful day^_^" : "Oops..what a fuck!") << endl;
}

void CreateMaxTargetADuiShuQi(int testTimes, int maxSize, int maxValue, int (*pt1)(const std::vector<int> &arr), int (*pt2)(const std::vector<int> &arr))
{
    srand(time(nullptr));
    bool success = true;
    for (int i = 0; i < testTimes; i++)
    {
        int size = rand() % maxSize + 1;
        vector<int> arr;
        for (int j = 0; j < size; j++)
            arr.push_back(rand() % (maxValue + 1));
        if (pt1(arr) != pt2(arr))
        {
            success = false;
            printArray(arr);
            break;
        }
    }
    cout << (success ? "today is a beautiful day^_^" : "Oops..what a fuck!") << endl;
}