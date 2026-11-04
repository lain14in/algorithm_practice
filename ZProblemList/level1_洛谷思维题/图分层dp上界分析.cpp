#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
void solve(){
    int n,m,c;cin>>n>>m>>c;
    vector<int>a(n+1);
    vector<pii>e(m);
    int mx=0;
    for(int i=1;i<=n;++i)cin>>a[i],mx=max(mx,a[i]);
    for(auto &[u,v]:e)cin>>u>>v;
    int lim=mx/c;
    vector<vector<int>>dp(lim+1,vector<int>(n+1,-1));
    dp[0][1]=0;
    ll ans=0;
    for(int t=1;t<=lim;++t){
        for(auto [u,v]:e){
            if(dp[t-1][u]==-1)continue;
            dp[t][v]=max(dp[t][v],dp[t-1][u]+a[v]);
        }
        if(dp[t][1]!=-1)ans=max(ans,dp[t][1]-(ll)c*t*t);
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
考查**时间分层 DP＋上界分析**。关键是先固定旅行天数，此时费用固定，问题就变成“恰好走这些天并回到起点，最多能赚多少”；
原图虽然有环，但加入时间后，每一步只从前一天转移到后一天，可以顺序递推。收入至多线性增长，费用却平方增长，所以只需考虑不超过 `mx/C` 天。
代码用 `dp[t][u]` 维护走 `t` 天到城市 `u` 的最大收入，沿有向边转移，再对所有回到城市1的状态扣除费用取最大值。
*/