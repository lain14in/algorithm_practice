//https://qoj.ac/contest/2562/problem/14687
//矩阵可以直接算出任意两点的LCA编号，用两条根路径的异或抵消公共部分，再与两点间的路径异或，只留下分叉点。
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
    for(int i=1;i<=n;++i)s[i]=a[1][i];//保存根到各点的路径异或和
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            a[i][j]^=s[i]^s[j];//现在a[i][j]表示最近公共祖先的编号LCA(i,j)
            if(i!=j&&a[i][j]==j)++dep[i];//j是i的严格祖先，祖先数量就是深度
        }
    }
    for(int u=2;u<=n;++u){
        int fa=1;//根1一定是u的祖先，先作为候选父亲
        for(int v=2;v<=n;++v){
            if(v!=u&&a[u][v]==v&&dep[v]>dep[fa])fa=v;//找最深的严格祖先
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
/*
读取矩阵，保存第一行 s。
将矩阵变成“最近公共祖先编号矩阵”。
统计每个点的严格祖先数量，得到深度。
对每个非根节点，找到最深的严格祖先，输出父子边。
*/