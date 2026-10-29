//https://vjudge.net/problem/CSES-1724
//加了边权求最短路版本的I，改矩阵乘法的定义和初始化等
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=105,mod=1e9+7;
const ll INF=4e18;//足够大
const double eps=1e-9,pi=2*acos(0);
int n,m,k;
struct M{//方阵
    ll a[N][N]={};
    M(bool id=0){//id=1单位矩阵对角线元素0，其他全∞；id=0默认矩阵元素全∞
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(id&&i==j)a[i][j]=0;//单位矩阵，点自己到自己的距离是0
                else a[i][j]=INF;
    }
    M operator*(M B){//”最小加法“矩阵乘法
        M C;//默认矩阵
        for(int i=1;i<=n;++i)
            for(int k=1;k<=n;++k){
                if(a[i][k]==INF)continue;
                for(int j=1;j<=n;++j){
                    if(B.a[k][j]==INF)continue;
                    C.a[i][j]=min(C.a[i][j],a[i][k]+B.a[k][j]);
                }
            }
        return C;
    }
};
M Mqpow(M A,ll b){
    M R(1);//单位矩阵
    while(b){
        if(b&1)R=R*A;
        A=A*A;
        b>>=1;
    }
    return R;
}
void solve(){
    cin>>n>>m>>k;
    M A;//默认矩阵
    for(int i=0;i<m;++i){
        ll u,v,w;cin>>u>>v>>w;
        A.a[u][v]=min(A.a[u][v],w);//邻接矩阵A[u][v]，存u->v的路径数，+1
    }
    M ans=Mqpow(A,k);//(A^k)[u][v]为u->v经过k条边的路径数
    if(ans.a[1][n]!=INF)cout<<ans.a[1][n];
    else cout<<-1;
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