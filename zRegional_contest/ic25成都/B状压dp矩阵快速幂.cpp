//https://codeforces.com/gym/106161/problem/B
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e6+5,mod=1e9+7;
const ll INF=4e18;
struct Mt{
    int n;
    vector<vector<ll>>a;
    Mt(int n=0):n(n),a(n,vector<ll>(n,-INF)){}
};
Mt operator*(const Mt&A,const Mt&B){
    int n=A.n;
    Mt C(n);
    for(int i=0;i<n;++i)
        for(int k=0;k<n;++k)if(A.a[i][k]>-1)
            for(int j=0;j<n;++j)if(B.a[k][j]>-1)
                C.a[i][j]=max(C.a[i][j],A.a[i][k]+B.a[k][j]);
    return C;
}
Mt Mqpow(Mt A,ll b){
    int n=A.n;
    Mt r(n);
    for(int i=0;i<n;++i)r.a[i][i]=0;
    while(b){
        if(b&1)r=r*A;
        A=A*A;
        b>>=1;
    }
    return r;
}
void solve(){
    ll n,m,k,R;cin>>n>>m>>k>>R;
    vector<ll>a(6),c(6);
    for(int i=0;i<n;++i)cin>>a[i]>>c[i];
    int S=1<<n;
    vector<ll>dmg(S),base(S);
    for(int s=1;s<S;++s){
        int b=__builtin_ctz(s),t=s^(1<<b);//s去掉最低位b得到t
        dmg[s]=dmg[t]+a[b];//上一个没有b的t加上b的伤害得到本轮s的伤害
        base[s]=base[t]+c[b];//同上，加上”蓝条“消耗（不考虑连续使用的基础消耗）
    }
    Mt M(S);
    for(int s=0;s<S;++s){
        for(int t=0;t<S;++t){
            ll cost=base[t]+1LL*k*__builtin_popcount(s&t);//考虑连续惩罚k
            if(cost<=m)M.a[s][t]=dmg[t];//可以这么选就赋值，否则是初值大负数
        }
    }
    Mt P=Mqpow(M,R);
    ll ans=0;
    for(int t=0;t<S;++t)ans=max(ans,P.a[0][t]);//初什么都不选->各种情况t 的最大值
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
/*
状态压缩dp+矩阵快速幂
__builtin_clz(x)：前导 0 个数
__builtin_ctz(x)：末尾 0 个数
__builtin_popcount(x)：1 的个数
__builtin_parity(x)：1 的个数奇偶性
*/