//https://ac.nowcoder.com/acm/contest/26077/1008
//Prim：从一个点开始，不断选最小的边，把新点加入生成树。堆，邻接表
//Kruskal：把所有边从小到大排序，只要不会形成环，就加入生成树。并查集，边集数组
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=5e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
int f[N];
int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}
bool merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return 0;
    f[x]=y;
    return 1;
}
struct E{
    int u,v;
    ll w;
    bool operator<(E x){return w<x.w;}
};
void solve(){
    int n,m;cin>>n>>m;
    ll ans=0,cnt=0;
    vector<E>e(m+1);
    for(int i=1;i<=n;++i)f[i]=i;
    for(int i=1;i<=m;++i)cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e.begin(),e.end());
    for(int i=1;i<=m;++i){
        if(merge(e[i].u,e[i].v)){
            ans+=e[i].w;
            ++cnt;
            if(cnt==n-1)break;
        }
    }
    if(cnt==n-1)cout<<ans;
    else cout<<"impossible";
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