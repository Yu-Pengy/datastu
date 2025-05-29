#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;
const int maxn = 200001;
int nums[maxn];

// 辅助函数：插入排序
void insertion_sort(int q[], int l, int r)
{
    for (int i = l + 1; i <= r; ++i)
    {
        int key = q[i];
        int j = i - 1;
        while (j >= l && q[j] > key)
        { // 注意这里是 q[j] > key，以保证稳定性或正确性
            q[j + 1] = q[j];
            j--;
        }
        q[j + 1] = key;
    }
}

// 修改 quick_sort 函数
void quick_sort(int q[], int l, int r)
{
    // 设置阈值：当子数组长度小于此值时，使用插入排序
    const int INSERTION_SORT_THRESHOLD = 16; // 常见值，可根据测试微调
    if (r - l + 1 < INSERTION_SORT_THRESHOLD)
    {
        insertion_sort(q, l, r);
        return;
    }

    // 随机选择轴点并交换到末尾
    // 确保在 main 函数中调用了 srand(time(0))
    int random_pivot_index = l + rand() % (r - l + 1);
    std::swap(q[random_pivot_index], q[r]); // 将随机轴点放到 q[r]

    int x = q[r]; // 现在轴点是 q[r]

    int i = l - 1;
    int j = r + 1;

    // Hoare 分区的主循环
    while (true)
    {
        do
        {
            i++;
        } while (q[i] < x); // 找到第一个大于等于轴点的元素

        do
        {
            j--;
        } while (q[j] > x); // 找到第一个小于等于轴点的元素

        if (i < j)
        { // 如果 i 和 j 没有交叉，则交换
            std::swap(q[i], q[j]);
        }
        else
        {
            break; // 交叉或相遇，分区完成
        }
    }

    // 递归调用左右分区
    // 确保 j 是正确的分割点
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main()
{
    srand(time(0));
    ifstream in("in.txt");
    ofstream out("out.txt");
    string line;
    getline(in, line);
    int i = 0;
    int x;
    stringstream ss(line);
    while (ss >> x)
    {
        nums[i] = x;
        i++;
    }
    quick_sort(nums, 0, i - 1);
    for (int j = 0; j < i; j++)
        out << nums[j] << " ";
    return 0;
}