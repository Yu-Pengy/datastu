#include <iostream>
using namespace std;
void cmove(int *arr, int size, int m)
{
    for (int j = 0; j < m; j++)
    {
        int temp = arr[size - 1];
        for (int i = size - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }
}
int main()
{
    int a[] = {1,2,3,4,5};
    cmove(a,5,5);
    for(int i = 0;i < 5;i++)cout << a[i] << " ";
    cout << endl;
}