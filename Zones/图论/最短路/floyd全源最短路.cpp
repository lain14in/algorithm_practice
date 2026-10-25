//https://ac.nowcoder.com/acm/contest/26077/1018
//floyd算法模板题：按照指定顺序经过所有要求的岛屿，允许绕路和重复经过，求总危险值最小的路线。
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=105,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);

void solve(){
    int n,m;cin>>n>>m;
    vector<int>a(m+1);
    for(int i=1;i<=m;++i)cin>>a[i];
    vector<vector<ll>>dis(n+1,vector<ll>(n+1));//邻接矩阵
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>dis[i][j];
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    ll ans=0;
    for(int i=1;i<m;++i)ans+=dis[a[i]][a[i+1]];
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
思路：Floyd + 最短路累加。 题目要求按顺序经过指定的 \(m\) 个岛屿，但允许绕路和重复经过。
先用 Floyd 算法求出任意两座岛屿之间的最短距离 dis[i][j]，再按指定顺序累加相邻岛屿之间的最短距离，
即 \(ans=\sum_{i=1}^{m-1}dis[a_i][a_{i+1}]\)。时间复杂度为 \(O(n^3+m)\)。
*/