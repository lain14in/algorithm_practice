//https://qoj.ac/contest/1516/problem/8237
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=5e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
ll fac[N],invfac[N];
ll qpow(ll a,ll b){
    ll r=1;
    while(b){
        if(b&1)r=r*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return r;
}
void init(){
    fac[0]=1;
    for(int i=1;i<N;++i)fac[i]=fac[i-1]*i%mod;
    invfac[N-1]=qpow(fac[N-1],mod-2);
    for(int i=N-1;i>=1;--i)invfac[i-1]=invfac[i]*i%mod;
}
void solve(){
    int n;cin>>n;
    vector<ll>a(n+1),w(n+1);
    vector<int>b(n+1),d(n+1);
    vector<vector<int>>g(n+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>b[i];
    for(int i=1;i<=n;++i)cin>>w[i];
    queue<int>q;
    for(int i=1;i<=n;++i){
        int j=b[i];
        if(a[i]<a[j]){//分类建图
            d[i]=1;
            q.push(i);
        }else if(a[i]<a[j]+w[j]){
            g[j].push_back(i);//反向建边
        }
    }
    while(!q.empty()){//bfs每一类
        int u=q.front();q.pop();
        for(int v:g[u]){//遍历这一类的链
            if(d[v])continue;
            d[v]=d[u]+1;
            q.push(v);
        }
    }
    for(int i=1;i<=n;++i){
        ll ans=a[i];
        if(d[i])ans=(ans+w[i]*invfac[d[i]]%mod)%mod;//算期望
        cout<<ans<<' ';
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    init();
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
i_1->i_2->i_3
其中 i_3 属于情况 1，一定能获得糖。
那么：
- i_3：必定成功，概率 1。
- i_2：必须在 i_3 之后操作，概率 1/2。
- i_1：必须满足 i_3,i_2,i_1 依次操作，概率 1/(3!)。（插在1->2的1前面、1～2中间、2后面三种，所以上一个基础上分母*3）
*/