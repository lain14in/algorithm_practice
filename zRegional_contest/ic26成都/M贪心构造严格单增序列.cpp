//https://qoj.ac/contest/4600/problem/23604
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);

void solve(){
    ll n;cin>>n;
    ll ans=0,mx=-1e11;
    ll l,r,h=-1e11;
    for(int i=0;i<n;++i){
        cin>>l>>r;
        mx=max(mx,r);
        if(l>h)h=mx,++ans;
    }
    cout<<ans<<'\n';
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
/*
够不着l了再更新mx
cin>>
1
7
1 100
100 200
101 105
102 106
103 107
103 300
1 1000
cout<<
2
*/