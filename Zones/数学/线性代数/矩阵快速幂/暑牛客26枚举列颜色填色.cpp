#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=130,mod=998244353;
const double eps=1e-9,pi=2*acos(0);
int n,s;
vector<vector<int>>st;//列类型
vector<int>cur;//dfs构造列
ll qpow(ll a,ll b){
    ll r=1;
    while(b){
        if(b&1)r=r*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return r;
}
void dfs(int pos){//构造一列填颜色
    if(pos==n){st.push_back(cur);return;}
    for(int x=0;x<3;++x){
        if(x==cur.back())continue;
        cur.push_back(x);
        dfs(pos+1);
        cur.pop_back();
    }
}
struct matrix{
    ll a[N][N]={};
    matrix operator*(matrix B)const{
        matrix C;
        for(int i=0;i<s;++i)
            for(int k=0;k<s;++k)
                for(int j=0;j<s;++j)
                    C.a[i][j]=(C.a[i][j]+a[i][k]*B.a[k][j])%mod;
        return C;
    }
};
vector<ll>mul(vector<ll>a,matrix B){//定义数组乘转移矩阵
    vector<ll>c(s);
    for(int i=0;i<s;++i)
        for(int j=0;j<s;++j)
            c[j]=(c[j]+a[i]*B.a[i][j])%mod;
    return c;
}
void solve(){
    ll m;cin>>n>>m;
    if(n==1){cout<<3*qpow(2,m-1)%mod;return;}
    cur={0,1};//前两格编号为0、1
    dfs(2);//第三格开始构造这一列
    s=st.size();
    matrix A;//A.a[i][j]:i->j合法接法数
    for(int i=0;i<s;++i)
        for(int j=0;j<s;++j){
            int p[3]={0,1,2};//p[x]:x换为什么颜色
            do{
                bool ok=1;
                for(int k=0;k<n;++k)
                    if(st[i][k]==p[st[j][k]]){//左右颜色同色
                        ok=0;
                        break;
                    }
                A.a[i][j]+=ok;
            }while(next_permutation(p,p+3));
        }
    vector<ll>dp(s,6);//第一列每种类型有6种色
    --m;
    while(m){//矩阵快速幂
        if(m&1)dp=mul(dp,A);
        A=A*A;
        m>>=1;
    }
    ll ans=0;
    for(ll x:dp)ans=(ans+x)%mod;
    cout<<ans;
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
对转移矩阵快速幂：
matrix Mqpow(matrix A,ll b){
    matrix R;
    for(int i=0;i<s;++i)R.a[i][i]=1;
    while(b){
        if(b&1)R=R*A;
        A=A*A;
        b>>=1;
    }
    return R;
}
结尾：
matrix B=Mqpow(A,m-1);//B.a[i][j]:从首列类型i到末列类型j的接法数
    ll ans=0;
    for(int i=0;i<s;++i)
        for(int j=0;j<s;++j)
            ans=(ans+6*B.a[i][j])%mod;//第一列每种类型有6种配色
*/