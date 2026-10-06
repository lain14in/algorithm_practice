//https://ac.nowcoder.com/acm/contest/21094/A
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e6+5,mod=1e9+7;
ll e_gcd(ll a,ll b,ll &x,ll &y){
    if(b==0){x=1,y=0;return a;}
    ll d=e_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
void solve(){
    ll x,y,m,n,l;cin>>x>>y>>m>>n>>l;
    ll a=n-m,b=l,c=x-y;
    if(a<0)a=-a,c=-c;
    ll d=e_gcd(a,b,x,y);
    if(c%d)cout<<"impossible";
    else cout<<(x*(c/d)%(b/d)+(b/d))%(b/d);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}