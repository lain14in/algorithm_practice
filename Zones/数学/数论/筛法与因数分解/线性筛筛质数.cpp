//https://ac.nowcoder.com/acm/contest/21094/B
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=4e7+5,mod=1e9+7;
int p[N+3],cnt;//素数
bool c[N+3];//合数
void euler_sieve(){
    for(int i=2;i<=N;++i){
        if(!c[i])p[cnt++]=i;
        for(int j=0;j<cnt;++j){
            if(i*p[j]>N)break;
            c[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}
void solve(){
    int n,ans=0;cin>>n;
    ll sum=0;
    for(int l=0,r=0;r<cnt&&p[r]<=n;++r){
        sum+=p[r];
        while(sum>n)sum-=p[l++];
        if(sum==n)++ans;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    euler_sieve();
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}