//https://vjudge.net/problem/CSES-3154
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505,mod=1e9+7;
int n,m,pos[N];
ll a[N][N],ans[N];
ll qpow(ll a,ll b){
    ll r=1;
    while(b){
        if(b&1)r=r*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return r;
}
bool gauss(){
    int r=1;
    for(int j=1;j<=m&&r<=n;++j){
        int t=r;
        while(t<=n&&!a[t][j])++t;//寻找主元（找当前列非零元素）
        if(t>n)continue;
        for(int k=j;k<=m+1;++k)
            swap(a[t][k],a[r][k]);//主元换到r行
        ll inv=qpow(a[r][j],mod-2);
        for(int k=j;k<=m+1;++k)
            a[r][k]=a[r][k]*inv%mod;//主元归一化
        for(int i=r+1;i<=n;++i){
            ll x=a[i][j];
            if(!x)continue;
            for(int k=j;k<=m+1;++k)
                a[i][k]=(a[i][k]-x*a[r][k]%mod+mod)%mod;//向下消元
        }
        pos[j]=r++;
    }
    for(int i=r;i<=n;++i)
        if(a[i][m+1])return 0;//判断无解
    for(int j=m;j>=1;--j){//回代求未知数
        if(!pos[j])continue;
        ans[j]=a[pos[j]][m+1];
        for(int k=j+1;k<=m;++k)
            ans[j]=(ans[j]-a[pos[j]][k]*ans[k]%mod+mod)%mod;
    }
    return true;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m+1;++j)
            cin>>a[i][j];
    if(!gauss()){cout<<-1<<'\n';return;}
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<' ';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}