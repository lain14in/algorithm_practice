//https://qoj.ac/contest/2534/problem/14547
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e6+5,mod=1e9+7;
vector<vector<ll>>d;
void add(int x1,int y1,int x2,int y2){
    ++d[x1][y1];
    ++d[x2+1][y2+1];
    --d[x1][y2+1];
    --d[x2+1][y1];
}
void solve(){
    int n,m;cin>>n>>m;
    d.assign(n+2,vector<ll>(m+2));
    int k=min(n,m);
    for(int x=1;x<=k;++x){
        for(int y=0;x+y<=k;++y){
            add(y,0,n-x,m-x-y);
            add(x+y,y,n,m-x);
            add(0,x,n-x-y,m-y);
            add(x,x+y,n-y,m);
        }
    }
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            if(i)d[i][j]+=d[i-1][j];
            if(j)d[i][j]+=d[i][j-1];
            if(i&&j)d[i][j]-=d[i-1][j-1];
        }
    }
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j)
            cout<<d[i][j]<<' ';
        cout<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}
/*
枚举正方形的一条边向量 \((x,y)\)，与它垂直等长的另一条边就是 \((-y,x)\)，这样一种正方形的形状就确定了；
固定这种形状后，所有能放进画布的第一个顶点位置会构成一个矩形，
而其余三个顶点只是这个矩形分别平移得到的另外三个矩形，所以对这四个矩形各做一次二维差分 \(+1\)；
枚举完所有满足 \(x+y\le\min(n,m)\) 的 \((x,y)\) 后，
再对差分数组做二维前缀和，就能得到每个整点作为正方形顶点的总次数。
*/