#include<iostream>
#include<algorithm>
using namespace std;
struct task{
    int arrival;
    int execution;
}tasks[51];
bool compare(const task& a, const task& b) {
    if (a.arrival == b.arrival) {
        return false;  // If arrival times are the same, maintain original order
    }
    return a.arrival < b.arrival;  // Otherwise, sort by arrival time
}
int main(){
    int N;
    cin >> N;
    int arr,exe;
    for(int i = 0;i < N;i++){
        cin >> arr >> exe;
        tasks[i].arrival = arr;
        tasks[i].execution = exe;
    }
    sort(tasks,tasks + N,compare);
    int totaltime = 0;
    int endtime = tasks[0].arrival + tasks[0].execution;
    for(int i = 1;i < N;i++){
        if(tasks[i].arrival < endtime){
            totaltime += endtime - tasks[i].arrival;
            endtime += tasks[i].execution;
        }
        else endtime = tasks[i].execution + tasks[i].arrival;
    }
    cout << totaltime << endl;
}