//https://qoj.ac/contest/2609/problem/14723
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+5;

void solve(){
    int n,ca=0,cb=0;cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)cin>>a[i],ca+=a[i]&1;
    for(int i=0;i<n;++i)cin>>b[i],cb+=b[i]&1;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    bool fa=0,fb=0;
    if(a==b){cout<<"Yes\n";return;}
    for(int i=1;i<n;++i){
        if(a[i]-a[i-1]==1)fa=1;
        if(b[i]-b[i-1]==1)fb=1;
    }
    if(fa&&fb&&ca==cb)cout<<"Yes\n";
    else cout<<"No\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
/*
有无满足题目条件连续且相差1的两个点的情况，有就可以带动所有数都拉到0/1，最后看有几个0、几个1，
变换的时候奇偶性一直保持，看两个数组的奇偶数数量相等就成功。
没有两个点符合这个情况就看初始数组排序后是不是一样的
*/