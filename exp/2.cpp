#include<iostream>
#include<fstream>
#include<algorithm>
#define maxn 50
using namespace std;
struct TumElem{
    int r; //行号
    int c; //列号
    int d; //元素值
    TumElem(){}
    TumElem(int r1,int c1,int d1):r(r1),c(c1),d(d1){}
}narr[maxn];
bool compare(TumElem &s1,TumElem &s2){
    return s1.r < s2.r;
}
int main(){
    fstream in("in.txt");
    ofstream out("abc.out");
    int r,c,n;
    in >> r >> c >> n;
    int ri,ci,di;
    for(int i = 0;i < n;i++){
        in >> ri >> ci >> di;
        narr[i] = TumElem(ri,ci,di);
    }
    for(int i = 0;i < n;i++){
        swap(narr[i].r,narr[i].c);
    }
    sort(narr,narr + n,compare);
    out << c << " " << r << " " << n << endl;
    for(int i = 0;i < n;i++){
        out << narr[i].r << " " << narr[i].c << " " << narr[i].d << endl;
    }
    return 0;
}