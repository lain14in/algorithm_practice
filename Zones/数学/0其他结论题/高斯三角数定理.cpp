//https://vjudge.net/problem/CSES-3406
//高斯三角数定理说明：每个正整数都能表示成至多三个三角数之和(不唯一)，所以答案只有 1、2、3
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
ll S(ll x){
    return x*(x+1)/2;
}
void solve(){
    ll n;cin>>n;
    ll L=1,R=2e6;
    while(L<=R){//找前驱：R：最大的满足S(R)<=n的下标。L=R+1：第一个满足S(L)>n的下标。
        ll mid=(L+R)/2;
        if(S(mid)<=n)L=mid+1;
        else R=mid-1;
    }
    if(S(R)==n){cout<<"1\n";return;}
    ll l=1,r=R;
    while(l<=r){
        ll s=S(l)+S(r);
        if(s==n){cout<<"2\n";return;}
        else if(s<n)++l;
        else --r;
    }
    cout<<"3\n";
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