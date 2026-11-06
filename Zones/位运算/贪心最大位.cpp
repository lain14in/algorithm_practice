//https://codeforces.com/contest/2283/problem/C
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);

void solve(){
    int n;cin>>n;
    vector<int>d(n+1);
    int x=0,p=1;
    for(int i=1;i<=n;++i)x^=i;
    while((p<<1)<=n)p<<=1;
    for(int i=p;i;i>>=1){
        if(!(x&(i<<1))){
            d[i]=1;
            x^=i^(i<<1);
        }
    }
    for(int i=1;i<=n;++i)cout<<d[i]<<' ';
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
考查**位运算＋高位贪心**。设不超过 `n` 的最大2的幂为 `p`，则原数组的按位或 `k=2*p-1`，其二进制全为1，
目标 `2*k` 则是这些1后面补一个0。翻倍一个2的幂 `i`，只会翻转整体异或值中代表 `i` 和 `2*i` 的相邻两位，
因此从大到小处理：若代表 `2*i` 的位为0，就翻倍 `i`，且不会破坏已经确定的高位。代码先求初始异或值，
再依次枚举 `p、p/2……1`，记录操作并更新异或值，最终得到 `2*k` 或 `2*k+1`，时间复杂度为 `O(n)`。
*/