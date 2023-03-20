// @before-stub-for-debug-begin

// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

#include <ctime>
#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    void swap_arr(vector<int> &nums, size_t i, size_t j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    vector<int> sortArray(vector<int> &nums)
    {
        size_t L = 0, R = nums.size() - 1;
        // SelectionSort(nums);
        raidoSort(nums, L, R);
        // heapSort(nums, nums.size());
        return nums;
    }

    void SelectionSort(vector<int> &nums)
    {
        decltype(nums.size()) size = nums.size();
        if (size < 2)
            return;
        for (decltype(size) i = 0; i < size - 1; i++)
        {
            decltype(size) minIndex = i;
            for (decltype(size) j = i + 1; j < size; j++)
                minIndex = nums[minIndex] > nums[j] ? j : minIndex;
            swap_arr(nums, i, minIndex);
        }
    }

    void BubbleSort(vector<int> &nums)
    {
        decltype(nums.size()) size = nums.size();
        if (size < 2)
            return;
        for (size_t end = size - 1; end > 0; end--)
        {
            for (size_t i = 0; i < end; i++)
            {
                if (nums[i] > nums[i + 1])
                    swap_arr(nums, i, i + 1);
            }
        }
    }

    void InsertSort(vector<int> &nums)
    {
        decltype(nums.size()) size = nums.size();
        if (size < 2)
            return;
        for (size_t i = 1; i < size; i++)
        {
            for (size_t j = i; j > 0 && nums[j - 1] > nums[j]; j--)
                swap_arr(nums, j, j - 1);
        }
    }

    void ProcessSort(vector<int> &nums, size_t L, size_t R)
    {
        if (L == R)
            return;
        size_t Mid = L + ((R - L) >> 1);
        ProcessSort(nums, L, Mid);
        ProcessSort(nums, Mid + 1, R);
        merge_sort(nums, L, Mid, R);
    }

    void merge_sort(vector<int> &nums, size_t L, size_t mid, size_t R)
    {
        size_t p1 = L;
        size_t p2 = mid + 1;
        size_t *help = new size_t[R - L + 1];
        size_t i = 0;
        while (p1 <= mid && p2 <= R)
            help[i++] = nums[p1] < nums[p2] ? nums[p1++] : nums[p2++];
        while (p1 <= mid)
            help[i++] = nums[p1++];
        while (p2 <= R)
            help[i++] = nums[p2++];
        for (i = 0; i < R - L + 1; i++)
            nums[L + i] = help[i];
        delete[] help;
        // help = nullptr;
    }

    void QuickSort_v1(vector<int> &nums, int L, int R)
    {
        if (L < R)
        {
            int index = patition_v1(nums, L, R);
            QuickSort_v1(nums, L, index - 1);
            QuickSort_v1(nums, index + 1, R);
        }
    }

    int patition_v1(vector<int> &nums, int L, int R)
    {
        int lowerBoundary = L - 1;
        int comp_num = nums[R], index = L;
        while (index < R)
        {
            if (nums[index] <= comp_num)
                swap_arr(nums, ++lowerBoundary, index++);
            else
                index++;
        }
        // 将比较值移动至小于等于区的下一个位置，即这个数就在数组中排好了
        swap_arr(nums, lowerBoundary + 1, R);
        return (lowerBoundary + 1);
    }

    void QuickSort_v2(vector<int> &nums, int L, int R)
    {
        if (L >= R)
            return;
        pair<int, int> index = patition_v2(nums, L, R);
        QuickSort_v2(nums, L, index.first - 1);
        QuickSort_v2(nums, index.second + 1, R);
    }

    pair<int, int> patition_v2(vector<int> &nums, int L, int R)
    {
        srand(time(nullptr));
        pair<int, int> index{L - 1, R + 1};
        swap_arr(nums, L + rand() % (R - L + 1), R);
        int i = L, comp_num = nums[R];
        while (i != index.second)
        {
            if (nums[i] < comp_num)
                swap_arr(nums, ++index.first, i++);
            else if (nums[i] == comp_num)
                i++;
            else
                swap_arr(nums, --index.second, i);
        }
        return make_pair(index.first + 1, index.second - 1);
    }

    void heapSort(vector<int> &nums, int heapsize)
    {
        if (heapsize < 2)
            return;
        // 整个数组弄成大根堆
        // for (int i = 0; i < size; i++) // O(N)
        //     heapinsert(arr, i);        // O(logN)
        for (int i = heapsize - 1; i >= 0; i--)
            heapify(nums, i, heapsize); // O(N)
        // swap_arr(nums, 0, --heapsize);
        while (heapsize > 0)
        {
            swap_arr(nums, 0, --heapsize);
            heapify(nums, 0, heapsize);
        }
    }

    void heapinsert(vector<int> &nums, int index)
    {
        if (nums.empty())
            return;
        while (nums[index] > nums[(index - 1) >> 1])
        {
            swap_arr(nums, index, (index - 1) >> 1);
            index = ((index - 1) >> 1);
        }
    }

    void heapify(vector<int> &nums, int index, int heapsize)
    {
        if (nums.empty())
            return;
        int left = index * 2 + 1;
        // heapsize即限制了堆的规模，不一定整个数组都是堆结构
        while (left < heapsize)
        {
            int largest = left + 1 < heapsize && nums[left + 1] > nums[left] ? left + 1 : left;
            largest = nums[largest] > nums[index] ? largest : index;
            if (largest == index)
                return;
            swap_arr(nums, index, largest);
            index = largest;
            left = index * 2 + 1;
        }
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

    int MaxInArr(vector<int> &nums, int L, int R)
    {
        if (L == R)
            return nums[L];
        int mid = L + ((R - L) >> 1);
        int leftMax = MaxInArr(nums, L, mid);
        int rightMax = MaxInArr(nums, mid + 1, R);
        return leftMax < rightMax ? rightMax : leftMax;
    }
};

// @lc code=end
