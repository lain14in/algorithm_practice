//https://vjudge.net/problem/CSES-1096
//6个点，想到模6余数相关，f(i)=f(i-1)+f(i-2)+f(i-3)+f(i-4)+f(i-5)+f(i-6)
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
struct matrix{//一般矩阵也成立
    int n,m;
    vector<vector<ll>>M;
    matrix(){}
    matrix(int n,int m):n(n),m(m),M(n,vector<ll>(m)){}
    matrix(int n):n(n),m(n),M(n,vector<ll>(n)){for(int i=0;i<n;++i)M[i][i]=1;}
};
matrix operator*(matrix a,matrix b){//或者const &，不能单出&因为后面n-1是临时变量
    matrix c(a.n,b.m);
    for(int i=0;i<a.n;++i)
        for(int j=0;j<b.m;++j)
            for(int k=0;k<a.m;++k)
                c.M[i][j]=(c.M[i][j]+a.M[i][k]*b.M[k][j])%mod;
    return c;
}
matrix Mqpow(matrix a,ll b){//方阵
    matrix r(a.n);
    while(b){
        if(b&1)r=r*a;
        a=a*a;
        b>>=1;
    }
    return r;
}
void solve(){
    ll n;cin>>n;
    if(n==0){cout<<0;return;}
    matrix t(6,6),f(1,6);
    for(int i=0;i<6;++i)t.M[i][0]=1;
    for(int i=0;i<5;++i)t.M[i][i+1]=1;
    f.M[0][0]=1;//从[f(0),f(-1),f(-2),f(-3),f(-4),f(-5)]=[1,0,0,0,0,0]开始
    matrix ans=f*Mqpow(t,n);//f[0]->f[n]需要转换n次（乘n次矩阵t）       
    cout<<ans.M[0][0];
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