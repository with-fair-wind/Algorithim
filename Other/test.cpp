#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int> &nums, int L, int mid, int R)
{
    int p1 = L;
    int p2 = mid + 1;
    int *help = new int[R - L + 1];
    int i = 0;
    while (p1 <= mid && p2 <= R)
        help[i++] = nums[p1] < nums[p2] ? nums[p1++] : nums[p2++];
    while (p1 <= mid)
        help[i++] = nums[p1++];
    while (p2 <= R)
        help[i++] = nums[p2++];
    for (int i = 0; i < R - L + 1; i++)
        nums[L + i] = help[i];
    delete[] help;
    // help = nullptr;
}

vector<int> ProcessSort(vector<int> &nums, size_t L, size_t R)
{
    decltype(nums.size()) size = nums.size();
    if (size < 2)
        return nums;
    size_t Mid = L + ((R - L) >> 1);
    ProcessSort(nums, L, Mid);
    ProcessSort(nums, Mid + 1, R);
    merge_sort(nums, L, Mid, R);
    return nums;
}

int MaxInArr(vector<int> &nums, int L, int R)
{
    if (L == R)
        return nums[L];
    int mid = L + ((R - L) >> 1);
    int leftMax = MaxInArr(nums, L, mid);
    int rightMax = MaxInArr(nums, mid + 1, R);
    return leftMax < rightMax ? rightMax : leftMax;
}

int maxbits(vector<int> &nums, int L, int R)
{
    int maxNum = MaxInArr(nums, L, R), maxBits = 0;
    while (maxNum != 0)
    {
        maxBits++;
        maxNum /= 10;
    }
    return maxBits;
}

int getdigit(int arr_num, int digit)
{
    return ((arr_num / (int)pow(10, digit)) % 10);
}

void raidoSort(vector<int> &nums, int L, int R)
{
    int radio = 10;
    if (nums.empty() || L >= R)
        return;
    int digits = maxbits(nums, L, R);
    int *help = new int[R - L + 1];
    int *count = new int[radio];
    int j = L;
    int k = 0;
    for (j = 0; j < radio; j++)
        count[j] = 0;
    for (int i = 0; i < digits; i++)
    {
        for (j = L; j <= R; j++)
            count[getdigit(nums[j], i)]++;
        for (j = 1; j < radio; j++)
            count[j] += count[j - 1];
        for (j = R; j >= L; j--)
            help[--count[getdigit(nums[j], i)]] = nums[j];
        for (j = L, k = 0; j <= R; j++, k++)
            nums[j] = help[k];
        for (j = 0; j < radio; j++)
            count[j] = 0;
    }
    delete[] count;
    count = nullptr;
    delete[] help;
    help = nullptr;
}

int *Test(int *a)
{
    *a = 6;
    cout << "&a: " << &a << endl;
    cout << "a: " << a << endl;
    return a;
}

int main(void)
{
    int *b = new int;
    *b = 5;
    cout << "&b: " << &b << endl;
    cout << "b: " << b << endl;
    cout << "*b = " << *b << endl;
    int *c = Test(b); // 参数和返回值都是按值传递（拷贝），而不是按引用或者指针传递
    cout << "*c: " << *c << endl;
    cout << "&c: " << &c << endl;
    cout << "Now *b = " << *b << endl;

    cout << -1 / 2 << endl;
    int d = 7;
    d >>= 1;
    cout << d << endl;

    cout << (1 + ((5 - 1) >> 1)) << endl;
    cout << "-----------------" << endl;

    vector<int> test{3, 2, 4, 7, 1, 14, 23, 146, 45};
    raidoSort(test, 0, test.size() - 1);
    for (int num : test)
        cout << num << " ";
    cout << endl;

    int aa, bb;
    aa = bb = 0;
    cout << aa << " " << bb << endl;

    return 0;
}
