//https://qoj.ac/contest/4580/problem/20053
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const ll INF=1LL<<62;
const double eps=1e-6,pi=acos(-1.0);

void solve(){
    int n,m;ll x,y,z;cin>>n>>m>>x>>y>>z;
    vector<ll>a(n+1),b(m+1),dp(n+1),ndp(n+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=m;++i)cin>>b[i];
    for(int i=1;i<=n;++i)
        dp[i]=x+(i-1)*z+abs(a[i]-b[1])*y;//预处理一开始前面的
    for(int j=2;j<=m;++j){
        ll Pcost=INF;
        for(int k=1;k<=n;++k)
            Pcost=min(Pcost,dp[k]+(n-k)*z+x);//复制的dp状态
        ll cost=INF;
        for(int i=1;i<=n;++i){
            if(i>1)cost=min(cost,dp[i-1]-(i-1)*z);//不复制的dp状态，此i-1相当于k
            ndp[i]=min(Pcost,cost)+(i-1)*z+abs(a[i]-b[j])*y;//一起的
        }
        dp.swap(ndp);
    }
    ll ans=INF;
    for(int i=1;i<=n;++i)
        ans=min(ans,dp[i]+(n-i)*z);//剩下后面的
    cout<<ans<<'\n';
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
用滚动数组做 DP，dp[i] 表示已生成目标序列的前若干个元素，且最后一个使用当前这份 a[i] 时的最小费用。生成下一个 b[j] 时，
要么继续使用同一份中后面的位置，要么删除当前后缀后重新粘贴一份。前者把转移费用拆成 dp[k]-k*z+(i-1)*z，
从左到右维护 dp[k]-k*z 的前缀最小值；后者提前求出 min(dp[k]+(n-k)*z+x)。两者取最小，再加修改 a[i] 为 b[j] 的费用。
初始化时支付首次粘贴、删除前缀和修改费用，最后补上删除剩余后缀的费用，时间复杂度为 O(nm)。
*/