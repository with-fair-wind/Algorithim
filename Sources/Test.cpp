#include "Test.h"

using namespace std;

void Test_PrintIntBit()
{
    printInteger(-1);
    printInteger(INT_MIN);
}

void Test_SortArr()
{
    CreateArrDuiShuQi(TESTTIMES, MAXSIZE, MAXVAL, nullptr, nullptr, &QuickSort_v2, &ProcessSort);
    CreateArrDuiShuQi(TESTTIMES, MAXSIZE, MAXVAL, &InsertSort, &SelectionSort, nullptr, nullptr);
}

void Test_SmallerEqualBigger()
{
    SingleNode *head1 = new SingleNode(7);
    head1->next = new SingleNode(9);
    head1->next->next = new SingleNode(1);
    head1->next->next->next = new SingleNode(8);
    head1->next->next->next->next = new SingleNode(5);
    head1->next->next->next->next->next = new SingleNode(2);
    head1->next->next->next->next->next->next = new SingleNode(5);
    printSingleLinkedList(listPartition_v2(head1, 5));
}

void Test_CopyListWithRandom()
{
    cout << "=========================" << endl;
    RandomNode *head = nullptr;
    RandomNode *res1 = nullptr;
    RandomNode *res2 = nullptr;
    printRandLinkedList(head);
    res1 = copyListWithRand_v1(head);
    printRandLinkedList(res1);
    res2 = copyListWithRand_v2(head);
    printRandLinkedList(res2);
    printRandLinkedList(head);
    cout << "=========================" << endl;

    head = new RandomNode(1);
    head->next = new RandomNode(2);
    head->next->next = new RandomNode(3);
    head->next->next->next = new RandomNode(4);
    head->next->next->next->next = new RandomNode(5);
    head->next->next->next->next->next = new RandomNode(6);

    head->rand = head->next->next->next->next->next;                   // 1 -> 6
    head->next->rand = head->next->next->next->next->next;             // 2 -> 6
    head->next->next->rand = head->next->next->next->next;             // 3 -> 5
    head->next->next->next->rand = head->next->next;                   // 4 -> 3
    head->next->next->next->next->rand = nullptr;                      // 5 -> null
    head->next->next->next->next->next->rand = head->next->next->next; // 6 -> 4

    printRandLinkedList(head);
    res1 = copyListWithRand_v1(head);
    printRandLinkedList(res1);
    res2 = copyListWithRand_v2(head);
    printRandLinkedList(res2);
    printRandLinkedList(head);
    cout << "=========================" << endl;
}

void Test_FindFirstIntersectNode()
{
    cout << "=========================" << endl;
    // 1->2->3->4->5->6->7->null
    SingleNode *head1 = new SingleNode(1);
    head1->next = new SingleNode(2);
    head1->next->next = new SingleNode(3);
    head1->next->next->next = new SingleNode(4);
    head1->next->next->next->next = new SingleNode(5);
    head1->next->next->next->next->next = new SingleNode(6);
    head1->next->next->next->next->next->next = new SingleNode(7);

    // 0->9->8->6->7->null
    SingleNode *head2 = new SingleNode(0);
    head2->next = new SingleNode(9);
    head2->next->next = new SingleNode(8);
    head2->next->next->next = head1->next->next->next->next->next; // 8->6
    // 两个无环链表成Y字行相交得节点
    cout << getIntersectNode(head1, head2)->value << endl;

    // 1->2->3->4->5->6->7->4...
    head1 = new SingleNode(1);
    head1->next = new SingleNode(2);
    head1->next->next = new SingleNode(3);
    head1->next->next->next = new SingleNode(4);
    head1->next->next->next->next = new SingleNode(5);
    head1->next->next->next->next->next = new SingleNode(6);
    head1->next->next->next->next->next->next = new SingleNode(7);
    head1->next->next->next->next->next->next->next = head1->next->next->next; // 7->4

    // 0->9->8->2...
    head2 = new SingleNode(0);
    head2->next = new SingleNode(9);
    head2->next->next = new SingleNode(8);
    head2->next->next->next = head1->next; // 8->2
    // 两个有环链表成蜗牛状，Y下面是圆形,相交的节点
    cout << getIntersectNode(head1, head2)->value << endl;

    // 0->9->8->6->7->4->5->6..
    head2 = new SingleNode(0);
    head2->next = new SingleNode(9);
    head2->next->next = new SingleNode(8);
    head2->next->next->next = head1->next->next->next->next->next; // 8->6
    // 两个有环链表成蜗牛状，Y下面是圆形,相交的节点
    cout << getIntersectNode(head1, head2)->value << endl;
    cout << "=========================" << endl;
}

void Test_PreInPosTraversal()
{
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    inOrderUnRecur(head);
}

void Test_IsBST()
{
    TreeNode *head = new TreeNode(2);
    head->left = new TreeNode(2);
    head->right = new TreeNode(2);
    cout << (isBST_v2(head) ? "Right" : "Wrong") << endl;
}

void Test_SerializeAndReconstructTree()
{
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->right->left = new TreeNode(4);
    head->right->right = new TreeNode(5);
    string strSerial = serialByPre(head);
    cout << strSerial << endl;
    head = reconByPreString(strSerial);
    preOrderRecur(head);
}

void Test_PrintPaperFolding()
{
    PrintPaperFolding(3);
}

void Test_Morris()
{

    TreeNode *head = new TreeNode(4);
    head->left = new TreeNode(2);
    head->right = new TreeNode(6);
    head->left->left = new TreeNode(1);
    head->left->right = new TreeNode(3);
    head->right->left = new TreeNode(5);
    head->right->right = new TreeNode(7);

    morrisIn(head);
    morrisPre(head);
    morrisPos(head);
    cout << (isBST_v3(head) ? "today is a beautiful day^_^" : "Oops..what a fuck!") << endl;
}

void Test_LowestLexicography()
{
    vector<string> strs1{"b", "ba"};
    vector<string> strs2{"jibw", "ji", "jp", "bw", "jibw"};
    cout << lowestString(strs1) << endl;
    cout << lowestString(strs2) << endl;
}

void Test_LessMoneySplitGold()
{
    vector<int> vec{6, 7, 8, 9};
    cout << "lessMoney: " << lessMoney(vec) << endl;
}

void Test_GetMedianOfVector()
{
    CreateMedianDuiShuQi(TESTTIMES, MAXSIZE, MAXVAL, getMedian, getMedian_easy);
}

void Test_Hanoi()
{
    hanoi(3);
}

void Test_PrintAllSubsquences()
{
    printAllSubsequence_v2(string("abc"));
}

void Test_PrintAllPermutations()
{
    for (auto &cur : Permutation(string("abc")))
        cout << cur << endl;
}

#define NORMAL
void Test_NQueens()
{
    int n = 14;

    chrono::high_resolution_clock::time_point start_time = chrono::high_resolution_clock::now();

#ifdef NORMAL
    cout << "规模为" << n << "的棋盘有多少种放法(方法1) "
         << NQueens_v1(n) << endl;
#endif

#ifdef BIT
    cout << "规模为" << n << "的棋盘有多少种放法(方法2) "
         << NQueens_v2(n) << endl;
#endif

    chrono::high_resolution_clock::time_point end_time = chrono::high_resolution_clock::now();

    chrono::milliseconds elapsed_time = chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    cout << "Elapsed time: " << elapsed_time.count() << " milliseconds" << endl;
}

void Test_RandomPoolClass()
{
    RandomPool<string> myRandomPool;
    myRandomPool.insert_Key("kk");
    myRandomPool.insert_Key("bentong");
    myRandomPool.insert_Key("yan");
    int num[3] = {0, 0, 0};
    for (size_t i = 0; i < TESTTIMES; i++)
    {
        string res = myRandomPool.getRandom();
        if (res == "kk")
            num[0]++;
        else if (res == "bentong")
            num[1]++;
        else
            num[2]++;
    }
    cout << "kk appear how many times: " << num[0] << endl;
    cout << "bentong appear how many times: " << num[1] << endl;
    cout << "yan appear how many times: " << num[2] << endl;
    myRandomPool.delete_Key("kk");
    cout << "today is a beautiful day^_^" << endl;
}

void Test_KMP()
{
    string str = "abcabcababaccc";
    string match = "ababa";
    cout << "GetIndexOf: " << KMP(str, match);
}

void Test_Manacher()
{
    string str = "abc1234321ab";
    cout << "MaxLength: " << Manacher(str) << endl;
}

void Test_GetMaxWindow()
{
    vector<int> arr{4, 3, 5, 4, 3, 3, 6, 7};
    int WinSize = 3;
    vector<int> Result;
    getMaxWindow(Result, arr, WinSize);
    printArray(Result);
}

void Test_GetNearLess()
{
    CreateGetNearLessDuiShuQi(TESTTIMES, MAXSIZE, MAXVAL, getNearLess, getNearLess_easy);
}

void Test_MaxTargetA()
{
    CreateMaxTargetADuiShuQi(TESTTIMES, MAXSIZE, MAXVAL, MaxTargetA, MaxTargetA_easy);
}
