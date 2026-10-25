//https://codeforces.com/contest/2277/problem/C
//树的性质、连通块分析和 BFS/DFS 求距离
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9;

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>>g(n+1);
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>dis(n+1,-1);
    queue<int>q;
    dis[n]=0;
    q.push(n);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v:g[u]){
            if(v==1||dis[v]!=-1)continue;//跳过经过1且更新过（已更新路径）的点
            dis[v]=dis[u]+1;
            q.push(v);
        }
    }
    int ans=0;
    for(int v:g[1]){//原树1~n距离
        if(dis[v]!=-1){//1在n那个连通块当中的邻居
            ans=dis[v]+1;
            break;
        }
    }
    for(int i=1;i<=m;++i){
        int v;cin>>v;
        if(dis[v]!=-1)ans=max(ans,dis[v]+1);//1与距离n尽可能越远的点相连
    }
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
关键是所有新增边都连接点 1，因此最终从 1 到 n 的路径，除第一条边外都来自原树。删去点 1 后，
只有包含 n 的连通块中的操作端点才有用。从 n 出发、不经过 1 做一次 BFS，求出块内各点到 n 的距离，
再枚举操作端点 v，用 dis[v]+1 更新答案，同时保留原始距离，时间复杂度为 O(n+m)。
*/