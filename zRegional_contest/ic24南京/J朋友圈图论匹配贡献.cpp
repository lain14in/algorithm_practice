//https://codeforces.com/gym/105484/problem/J
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e6+5,mod=1e9+7;

void solve(){
    int n,m,k;cin>>n>>m>>k;
    vector<int>f(k+1),gain(k+1);
    for(int i=0;i<n;++i){
        int t;cin>>t;
        f[t]=1;
    }
    int base=0;
    vector<pair<int,int>>e;
    for(int i=0;i<m;++i){
        int a,b;cin>>a>>b;
        if(a==b){
            if(f[a])++base;
            else ++gain[a];
        }else if(f[a]&&f[b]){
            ++base;
        }else if(f[a]){
            ++gain[b];
        }else if(f[b]){
            ++gain[a];
        }else{
            if(a>b)swap(a,b);
            e.push_back({a,b});
        }
    }
    int mx1=0,mx2=0;
    for(int i=1;i<=k;++i){
        if(f[i])continue;
        if(gain[i]>=mx1){
            mx2=mx1;
            mx1=gain[i];
        }else if(gain[i]>mx2){
            mx2=gain[i];
        }
    }
    int best=mx1+mx2;
    sort(e.begin(),e.end());
    for(int i=0,j;i<(int)e.size();i=j){
        j=i;
        while(j<(int)e.size()&&e[j]==e[i])++j;
        auto [u,v]=e[i];
        best=max(best,gain[u]+gain[v]+j-i);
    }
    cout<<base+best<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}