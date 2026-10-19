//https://ac.nowcoder.com/acm/contest/21289/A
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-6;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){x=1,y=0;return a;}
    ll d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
void solve(){
    ll a,b,x,y;cin>>a>>b;
    ll d=exgcd(a,b,x,y);//y吸收掉-1，因为我的exgcd没有处理b负数的情况
    if(d>1)cout<<"-1\n";//a、b不一定互质
    else cout<<(x%b+b)%b<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}