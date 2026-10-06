//https://codeforces.com/gym/105588/problem/H
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
const int N=1e6+5,mod=1e9+7;
const ld PI=2*acos(0);
struct Point{
    ll x,y;
    Point(ll x=0,ll y=0):x(x),y(y){}
}OX(1,0);
typedef Point Vector;
ld Dot(Vector A,Vector B){return A.x*B.x+A.y*B.y;}
ld Len(Vector A){return sqrt(Dot(A,A));}
ld Angle(Vector A,Vector B){return acos(Dot(A,B)/Len(A)/Len(B));}
void solve(){
    int n,k;cin>>n>>k;
    vector<Point>p(n);
    for(int i=0;i<n;++i)cin>>p[i].x>>p[i].y;
    vector<ld>a(n);
    for(int i=0;i<n;++i){
        a[i]=Angle(p[i],OX);
        if(p[i].y<0)a[i]=2*PI-a[i];
    }
    sort(a.begin(),a.end());
    ld ans=0;
    for(int i=0;i<n;++i){
        if(i+k<n)ans=max(ans,a[i+k]-a[i]);
        else ans=max(ans,2*PI+a[(i+k)%n]-a[i]);
    }
    cout<<fixed<<setprecision(10)<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}