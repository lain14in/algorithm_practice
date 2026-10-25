//https://ac.nowcoder.com/acm/contest/27249/B
//只用看他右侧水平线是否穿过
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=5e3+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
struct Point{
    ll x,y;
}p[N];
ll Cross(Point a,Point b,Point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
void solve(){
    int n,q;cin>>n;
    for(int i=0;i<n;++i)cin>>p[i].x>>p[i].y;
    p[n]=p[0];
    cin>>q;
    while(q--){
        int ans=0;
        bool edge=0;
        Point P;cin>>P.x>>P.y;
        for(int i=0;i<n;++i){
            ll c=Cross(P,p[i],p[i+1]);
            if(c==0&&min(p[i].x,p[i+1].x)<=P.x&&P.x<=max(p[i].x,p[i+1].x)){edge=1;break;}
            if(c>0&&P.y>=p[i].y&&P.y<p[i+1].y)++ans;
            if(c<0&&P.y>=p[i+1].y&&P.y<p[i].y)--ans;
        }
        if(edge)cout<<"EDGE\n";
        else cout<<ans<<'\n';
    }
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