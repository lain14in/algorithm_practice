//https://ac.nowcoder.com/acm/contest/21094/C
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=1e6+5,mod=1e7+9;
const double eps=1e-6,pi=2*acos(0);
vector<ll>prime;
bool vis[N];
void euler_sieve(){
    for(ll i=2;i<N;++i){
        if(!vis[i])prime.push_back(i);
        for(ll j=0;j<(ll)prime.size()&&i*prime[j]<N;++j){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
void seg_sieve(ll l,ll r){
    vector<bool>v(r-l+1);
    for(ll x:prime){
        if(x*x>r)break;
        ll s=max(x*x,(l+x-1)/x*x);
        for(ll j=s;j<=r;j+=x)v[j-l]=1;
    }
    if(l==1)v[0]=1;
    vector<ll>pri;
    ll dmin1,dmin2,dmax1,dmax2,dmin=1e18,dmax=0;
    for(ll x=l;x<=r;++x){
        if(v[x-l])continue;
        pri.push_back(x);
        ll id=pri.size()-1;
        if((int)pri.size()<2)continue;
        ll d=pri[id]-pri[id-1];
        if(d<dmin)dmin=d,dmin1=pri[id-1],dmin2=pri[id];
        if(d>dmax)dmax=d,dmax1=pri[id-1],dmax2=pri[id];
    }
    if((int)pri.size()<2){cout<<"There are no adjacent primes.\n";return;}
    cout<<dmin1<<','<<dmin2<<" are closest, "<<dmax1<<','<<dmax2<<" are most distant.\n";
}
void solve(){
    ll l,r;cin>>l>>r;
    seg_sieve(l,r);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    euler_sieve();
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}