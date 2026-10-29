//https://qoj.ac/contest/2562/problem/14692
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
void solve(){
    int n;cin>>n;
    vector<ll>a(n+1),s(n+1),ans(n+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
    for(int k=n,r=n;k>=3;--k){
        while(r>=k&&2*a[r]>=s[r]-s[r-k])--r;
        if(r>=k)ans[k]=s[r]-s[r-k];
    }
    for(int k=1;k<=n;++k)cout<<ans[k]<<' ';
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
1，面积是否>0，是否退化的角度（高代行列式那块的思想）来看：
   三角形用 "最大边长度<另外两小边之和" 判断是否构成 -> 多边形用"最大边长度<其余边之和" 判断是否构成；
2，某个右端点选 k 根都不合法，选更少的边时，其余边的和更小，也一定不合法；
3，所以被排除的右端点永远不用再考虑；
4，排序，求前缀和，然后右到左处理遍历一遍即可。
*/