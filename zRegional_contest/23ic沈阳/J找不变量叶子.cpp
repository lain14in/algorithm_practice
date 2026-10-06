//https://codeforces.com/gym/104869/problem/J
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128_t;
const int N=1e6+5,mod=1e9+7;

void solve(){
    int n,c=0;cin>>n;
    if(n==2){cout<<"Bob";return;}
    vector<int>edge(n+1);
    for(int i=0;i<n-1;++i){
        int u,v;cin>>u>>v;
        ++edge[u],++edge[v];
    }
    for(int i=1;i<=n;++i){
        if(edge[i]==1)++c;
    }
    if((c&1)!=((n-1)&1))cout<<"Alice";
    else cout<<"Bob";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}