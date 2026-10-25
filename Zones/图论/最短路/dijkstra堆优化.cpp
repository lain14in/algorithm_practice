//https://ac.nowcoder.com/acm/contest/26077/1007
//朴素 Dijkstra：每次遍历所有顶点，找到当前距离最小的未访问顶点。
//堆优化 Dijkstra：利用小根堆快速找到当前距离最小的顶点。
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<ll,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
const ll INF=1LL<<62;
struct E{
    int to;
    ll w;
};
//堆优化dijkstra，适用于稀疏图，堆开销小 O((n+m)logn)
vector<ll>dijkstra(int s,vector<vector<E>>&g){
    int n=g.size()-1;
    vector<ll>dis(n+1,INF);
    priority_queue<pii,vector<pii>,greater<pii>>q;
    dis[s]=0;
    q.push({0,s});
    while(!q.empty()){
        auto [d,u]=q.top();q.pop();
        if(d!=dis[u])continue;//跳过堆中的旧信息（d不是dis里面的最短路）
        for(auto [v,w]:g[u]){
            if(d+w<dis[v]){
                dis[v]=d+w;
                q.push({dis[v],v});
            }
        }
    }
    return dis;
}
void solve(){
    int n,m,s,t;cin>>n>>m>>s>>t;
    vector<vector<E>>g(n+1);
    for(int i=1;i<=m;++i){
        int u,v;ll w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vector<ll>dis=dijkstra(s,g);
    if(dis[t]!=INF)cout<<dis[t]<<'\n';
    else cout<<"-1\n";
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
朴素dijkstra，适用于稠密图 O(n^2+m)
vector<ll>dijkstra(int s,vector<vector<E>>&g){
    int n=g.size()-1;
    vector<ll>dis(n+1,INF);
    vector<bool>vis(n+1);
    dis[s]=0;
    for(int i=1;i<=n;++i){
        int u=-1;
        for(int j=1;j<=n;++j){//找距离最小的未访问顶点
            if(!vis[j]&&(u==-1||dis[j]<dis[u]))
                u=j;
        }
        if(u==-1||dis[u]==INF)break;
        vis[u]=1;//起点s到u的最短距离已经确定
        for(auto [v,w]:g[u]){
            if(dis[v]>dis[u]+w)
                dis[v]=dis[u]+w;
        }
    }
    return dis;
}
*/