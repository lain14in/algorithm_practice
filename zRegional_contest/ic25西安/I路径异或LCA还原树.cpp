//https://qoj.ac/contest/2562/problem/14687
//矩阵可以直接算出任意两点的LCA编号,用两条根路径的异或抵消公共部分，再与两点间的路径异或，只留下分叉点。
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);

void solve(){
    int n;cin>>n;
    vector<vector<int>>a(n+1,vector<int>(n+1));
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            cin>>a[i][j];
            a[j][i]=a[i][j];
        }
    }
    vector<int>s(n+1),dep(n+1);
    for(int i=1;i<=n;++i)s[i]=a[1][i];
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            int w=a[i][j]^s[i]^s[j];//LCA(u,v)
            a[i][j]=a[j][i]=w;
            if(i==j)continue;
            if(w==i)++dep[j];
            else if(w==j)++dep[i];
        }
    }
    for(int u=2;u<=n;++u){
        int fa=1;
        for(int v=2;v<=n;++v){
            if(v!=u&&a[u][v]==v&&dep[v]>dep[fa])fa=v;
        }
        cout<<fa<<' '<<u<<'\n';
    }
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