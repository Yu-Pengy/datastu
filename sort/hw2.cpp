#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;
const int maxn = 200001;
int nums[maxn];

void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int random_pivot_index = l + rand() % (r - l + 1);
    swap(q[random_pivot_index], q[r]);

    int x = q[r];
    int i = l - 1;
    int j = r + 1;
    while (i <= j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    quick_sort(q, l, j); // 用j定位，就要保证j是对的
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