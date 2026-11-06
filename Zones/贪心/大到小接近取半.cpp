//https://codeforces.com/contest/2284/problem/A2
//a+b=sum,ab尽可能大，即a接近b，贪心从大到小塞，尽量塞到接近sum/2
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);

void solve(){
    int n;cin>>n;
    int cnt[25]={};
    ll sum=0;
    for(int i=0;i<n;++i){
        int x;cin>>x;
        ++cnt[x];
        sum+=1LL<<x;
    }
    ll lim=sum/2,s=0;
    for(int i=24;i>=0;--i){//大到小贪心
        ll w=1LL<<i;
        ll k=min((ll)cnt[i],(lim-s)/w);//能取多少取多少，尽量塞满sum/2，这样s接近于sum-s，他们乘积更大
        s+=k*w;
    }
    cout<<s*(sum-s)<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}