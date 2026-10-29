//https://vjudge.net/problem/CSES-1723
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=105,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
int n,m,k;
struct M{//方阵
    ll a[N][N]={};
    M operator*(M B){
        M C;
        for(int i=1;i<=n;++i)
            for(int k=1;k<=n;++k)
                for(int j=1;j<=n;++j)
                    C.a[i][j]=(C.a[i][j]+a[i][k]*B.a[k][j])%mod;
        return C;
    }
};
M Mqpow(M A,ll b){
    M R;
    for(int i=1;i<=n;++i)R.a[i][i]=1;
    while(b){
        if(b&1)R=R*A;
        A=A*A;
        b>>=1;
    }
    return R;
}
void solve(){
    cin>>n>>m>>k;
    M A;
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        ++A.a[u][v];//邻接矩阵A[u][v]，存u->v的路径数，+1
    }
    M ans=Mqpow(A,k);//(A^k)[u][v]为u->v经过k条边的路径数
    cout<<ans.a[1][n];
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