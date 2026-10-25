//https://ac.nowcoder.com/acm/contest/26077/1001
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-6,pi=acos(-1.0);
struct E{
    int to;
    ll w;
};
void solve(){
    int n,m;cin>>n>>m;
    vector<ll>c(n+1),f(n+1);
    vector<int>in(n+1),out(n+1);
    vector<vector<E>>adj(n+1);
    for(int i=1;i<=n;++i)cin>>c[i]>>f[i];
    for(int i=1;i<=m;++i){
        int u,v;ll w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        ++in[v],++out[u];
    }
    queue<int>q;
    for(int i=1;i<=n;++i){
        if(!in[i])q.push(i);
        else c[i]-=f[i];
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto [v,w]:adj[u]){//用E e:adj[u]，后面用e.to和e.w对于低于C++17的可行
            if(c[u]>0)c[v]+=c[u]*w;
            --in[v];
            if(!in[v])q.push(v);
        }
    }
    bool ok=0;
    for(int i=1;i<=n;++i){
        if(!out[i]&&c[i]>0){
            cout<<i<<' '<<c[i]<<'\n';
            ok=1;
        }
    }
    if(!ok)cout<<"NULL";
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