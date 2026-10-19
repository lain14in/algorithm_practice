//https://vjudge.net/problem/OpenJ_Bailian-2069
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-7;
int n;
struct Point3{double x,y,z;}p[35];
double Distance(Point3 A,Point3 B){
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)+(A.z-B.z)*(A.z-B.z));
}
void solve(){
    double T=100,delta=0.98,r;
    Point3 c=p[0];
    int pos;
    while(T>eps){
        pos=0,r=0;
        for(int i=0;i<n;++i)
            if(Distance(c,p[i])>r){
                r=Distance(c,p[i]);
                pos=i;
            }
        c.x+=(p[pos].x-c.x)/r*T;
        c.y+=(p[pos].y-c.y)/r*T;
        c.z+=(p[pos].z-c.z)/r*T;
        T*=delta;
    }
    cout<<fixed<<setprecision(5)<<r<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(cin>>n&&n){
        for(int i=0;i<n;++i)cin>>p[i].x>>p[i].y>>p[i].z;
        solve();
    }
    return 0;
}