//https://ac.nowcoder.com/acm/contest/26077/1038
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
struct E{
    int u,v,w;
};
bool Bellman(int n,vector<E>&e){//1有负环，0无负环
    vector<ll>dis(n+1,0);
    for(int i=1;i<=n;++i){
        bool f=0;
        for(auto [u,v,w]:e){
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                f=1;
                if(i==n)return 1;
            }
        }
        if(!f)return 0;
    }
    return 0;
}
void solve(){
    int n,m,w;cin>>n>>m>>w;
    vector<E>e;
    for(int i=0;i<m;++i){
        int u,v,w;cin>>u>>v>>w;
        e.push_back({u,v,w});
        e.push_back({v,u,w});
    }
    for(int i=0;i<w;++i){
        int u,v,w;cin>>u>>v>>w;
        e.push_back({u,v,-w});
    }
    if(Bellman(n,e))cout<<"YES\n";
    else cout<<"NO\n";
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