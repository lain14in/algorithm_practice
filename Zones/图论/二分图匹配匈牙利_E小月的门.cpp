//https://ac.nowcoder.com/acm/contest/140737/E
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e6+5,mod=1e9+7;
int n,a[10],b[10],mt[10],vis[10];
bool dfs(int u){
    for(int v=0;v<n;++v){
        if(vis[v]||__gcd(a[u],b[v])>1)continue;
        vis[v]=1;
        if(mt[v]==-1||dfs(mt[v])){
            mt[v]=u;
            return 1;
        }
    }
    return 0;
}
void solve(){
    int ans=0;cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];
    memset(mt,-1,sizeof(mt));
    for(int i=0;i<n;++i){
        memset(vis,0,sizeof(vis));
        if(dfs(i))++ans;
    }
    if(ans==n)cout<<"Bob";
    else cout<<"Alice";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}