//https://www.luogu.com.cn/problem/P2742
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e6+5,mod=1e9+7;
const double eps=1e-6;
int sgn(double x){
    if(fabs(x)<eps)return 0;
    else return x<0?-1:1;
}
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator + (Point B){return Point(x+B.x,y+B.y);}
    Point operator - (Point B){return Point(x-B.x,y-B.y);}
    bool operator == (Point B){return sgn(x-B.x)==0&&sgn(y-B.y)==0;}
    bool operator < (Point B){
        return sgn(x-B.x)<0||(sgn(x-B.x)==0&&sgn(y-B.y)<0);
    }
}p[N],ch[N];
typedef Point Vector;
double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
double Distance(Point A,Point B){return hypot(A.x-B.x,A.y-B.y);}
int Convex_hull(Point *p,int n,Point *ch){
    sort(p,p+n);
    n=unique(p,p+n)-p;
    int v=0;
    for(int i=0;i<n;++i){
        while(v>1&&sgn(Cross(ch[v-1]-ch[v-2],p[i]-ch[v-1]))<=0)--v;
        ch[v++]=p[i];
    }
    int j=v;
    for(int i=n-2;i>=0;--i){
        while(v>j&&sgn(Cross(ch[v-1]-ch[v-2],p[i]-ch[v-1]))<=0)--v;
        ch[v++]=p[i];
    }
    if(n>1)--v;
    return v;
}
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>p[i].x>>p[i].y;
    int v=Convex_hull(p,n,ch);
    double ans=0;
    for(int i=0;i<v;++i)ans+=Distance(ch[i],ch[(i+1)%v]);
    cout<<fixed<<setprecision(2)<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}