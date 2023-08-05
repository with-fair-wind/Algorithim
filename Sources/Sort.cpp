#include "Sort.h"

using namespace std;

void SelectionSort(int arr[], int size)
{
    if (arr == nullptr || size < 2)
        return;
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
            minIndex = arr[minIndex] > arr[j] ? j : minIndex;
        swap_arr(arr, i, minIndex);
    }
}

void BubbleSort(int arr[], int size)
{
    if (arr == nullptr || size < 2)
        return;
    for (size_t end = size - 1; end > 0; end--)
    {
        for (size_t i = 0; i < end; i++)
        {
            if (arr[i] > arr[i + 1])
                swap_bit(arr, i, i + 1);
        }
    }
}

void InsertSort(int arr[], int size)
{
    if (arr == nullptr || size < 2)
        return;
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
            swap_bit(arr, j, j - 1);
    }
}

void ProcessSort(int *arr, int L, int R)
{
    if (arr == nullptr || L == R)
        return;
    int Mid = L + ((R - L) >> 1);
    ProcessSort(arr, L, Mid);
    ProcessSort(arr, Mid + 1, R);
    merge_sort(arr, L, Mid, R);
}

void merge_sort(int *arr, int L, int mid, int R)
{
    int p1 = L;
    int p2 = mid + 1;
    int *help = new int[R - L + 1];
    int i = 0;
    while (p1 <= mid && p2 <= R)
        help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    while (p1 <= mid)
        help[i++] = arr[p1++];
    while (p2 <= R)
        help[i++] = arr[p2++];
    for (int i = 0; i < R - L + 1; i++)
        arr[L + i] = help[i];
    delete[] help;
    help = nullptr;
}

int SmallAdd(int *arr, int L, int R)
{
    if (arr == nullptr || L == R)
        return 0;
    int mid = L + ((R - L) >> 1);
    return SmallAdd(arr, L, mid) + SmallAdd(arr, mid + 1, R) + merge_smalladd(arr, L, mid, R);
}

int merge_smalladd(int *arr, int L, int mid, int R)
{
    int p1 = L;
    int p2 = mid + 1;
    int *help = new int[R - L + 1];
    int i = 0, res = 0;
    while (p1 <= mid && p2 <= R)
    {
        res += arr[p1] < arr[p2] ? (R - p2 + 1) * arr[p1] : 0;
        // 就算arr[p1] == arr[p2], 拷贝右边的数，并后移p2, 为了知道右边有几个数比arr[p1]大
        help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    }
    while (p1 <= mid)
        help[i++] = arr[p1++];
    while (p2 <= R)
        help[i++] = arr[p2++];
    for (int i = 0; i < R - L + 1; i++)
        arr[L + i] = help[i];
    delete[] help;
    help = nullptr;
    return res;
}

int InverseLogarithm(int *arr, int L, int R)
{
    if (arr == nullptr || L == R)
        return 0;
    int mid = L + ((R - L) >> 1);
    return InverseLogarithm(arr, L, mid) + InverseLogarithm(arr, mid + 1, R) + merge_inverselogarithm(arr, L, mid, R);
}

int merge_inverselogarithm(int *arr, int L, int mid, int R)
{
    int p1 = L;
    int p2 = mid + 1;
    int *help = new int[R - L + 1];
    int i = 0, res = 0;
    while (p1 <= mid && p2 <= R)
    {
        res += arr[p1] > arr[p2] ? (R - p2 + 1) : 0;
        // 就算arr[p1] == arr[p2], 拷贝右边的数，并后移p2, 为了知道右边有几个数比arr[p1]大
        help[i++] = arr[p1] > arr[p2] ? arr[p1++] : arr[p2++];
    }
    while (p1 <= mid)
        help[i++] = arr[p1++];
    while (p2 <= R)
        help[i++] = arr[p2++];
    for (i = 0; i < R - L + 1; i++)
        arr[L + i] = help[i];
    delete[] help;
    help = nullptr;
    return res;
}

void QuickSort_v1(int *arr, int L, int R)
{
    if (arr == nullptr || L >= R)
        return;
    int index = patition_v1(arr, L, R);
    QuickSort_v1(arr, L, index - 1);
    QuickSort_v1(arr, index + 1, R);
}

int patition_v1(int *arr, int L, int R)
{
    int lowerBoundary = L - 1;
    int comp_num = arr[R], index = L;
    // for (int i = L; i < R; i++)(很明显的错误:一次循环i会加两次)
    while (index < R)
    {
        if (arr[index] <= comp_num)
            swap_arr(arr, ++lowerBoundary, index++);
        else
            index++;
    }
    // 将比较值移动至小于等于区的下一个位置，即这个数就在数组中排好了
    swap_arr(arr, lowerBoundary + 1, R);
    return lowerBoundary + 1;
}

void QuickSort_v2(int *arr, int L, int R)
{
    if (arr == nullptr || L >= R)
        return;
    pair<int, int> index = patition_v2(arr, L, R);
    QuickSort_v2(arr, L, index.first);
    QuickSort_v2(arr, index.second, R);
}

pair<int, int> patition_v2(int *arr, int L, int R)
{
    srand(time(nullptr));
    pair<int, int> index(L - 1, R + 1);
    swap_arr(arr, L + rand() % (R - L + 1), R);
    int i = L, comp_num = arr[R];
    while (i != index.second)
    {
        if (arr[i] < comp_num)
            swap_arr(arr, ++index.first, i++);
        else if (arr[i] == comp_num)
            i++;
        else
            swap_arr(arr, --index.second, i);
    }
    return make_pair(index.first, index.second);
}

void heapSort(int *arr, int heapsize)
{
    if (arr == nullptr || heapsize < 2)
        return;
    // 整个数组弄成大根堆
    // for (int i = 0; i < heapsize; i++) // O(N)
    //     heapinsert(arr, i);        // O(logN)
    for (int i = heapsize - 1; i >= 0; i--)
        heapify(arr, i, heapsize); // O(N)

    while (heapsize > 0)
    {
        swap_arr(arr, 0, --heapsize);
        heapify(arr, 0, heapsize);
    }
}

void heapinsert(int *arr, int index)
{
    if (arr == nullptr)
        return;
    while (arr[index] > arr[(index - 1) >> 1])
    {
        swap_arr(arr, index, (index - 1) >> 1);
        index = ((index - 1) >> 1);
    }
}

void heapify(int *arr, int index, int heapsize)
{
    if (arr == nullptr)
        return;
    int left = index * 2 + 1;
    // heapsize即限制了堆的规模，不一定整个数组都是堆结构
    while (left < heapsize)
    {
        int largest = left + 1 < heapsize && arr[left + 1] > arr[left] ? left + 1 : left;
        largest = arr[largest] > arr[index] ? largest : index;
        if (largest == index)
            return;
        swap_arr(arr, index, largest);
        index = largest;
        left = index * 2 + 1;
    }
}

void sortedArrDistanceLessK(int *arr, int size, int k)
{
    if (arr == nullptr || size < 2 || k == 0)
        return;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int index = 0;
    for (; index <= k; index++)
        minHeap.push(arr[index]);
    int i = 0;
    for (; index < size; index++, i++)
    {
        arr[i] = minHeap.top();
        minHeap.pop();
        minHeap.push(arr[index]);
    }
    for (; i < size; i++)
    {
        arr[i] = minHeap.top();
        minHeap.pop();
    }
}

void raidoSort(int *arr, int L, int R)
{
    int radio = 10;
    if (arr == nullptr || R - L < 1)
        return;
    int digits = maxbits(arr, L, R);
    int *help = new int[R - L + 1];
    int *count = new int[radio];
    int j = L;
    int k = 0;
    for (j = 0; j < radio; j++)
        count[j] = 0;
    for (int i = 0; i < digits; i++)
    {
        for (j = L; j <= R; j++)
            count[getdigit(arr[j], i)]++;
        for (j = 1; j < radio; j++)
            count[j] += count[j - 1];
        for (j = R; j >= L; j--)
            help[--count[getdigit(arr[j], i)]] = arr[j];
        for (j = L, k = 0; j <= R; j++, k++)
            arr[j] = help[k];
        for (j = 0; j < radio; j++)
            count[j] = 0;
    }
    delete[] count;
    delete[] help;
    count = nullptr;
    help = nullptr;
}

int maxbits(int *arr, int L, int R)
{
    int maxNum = MaxInArr(arr, L, R), maxBits = 0;
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