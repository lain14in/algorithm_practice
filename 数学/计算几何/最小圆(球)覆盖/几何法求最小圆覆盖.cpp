//https://www.luogu.com.cn/problem/P1742
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e5+5,mod=1e9+7;
const double eps=1e-8;
int sgn(double x){
    if(fabs(x)<eps)return 0;
    return x>0?1:-1;
}
struct Point{double x,y;}p[N];
double Distance(Point A,Point B){return hypot(A.x-B.x,A.y-B.y);}
Point circle_center(Point a,Point b,Point c){
    Point C;
    double a1=b.x-a.x,b1=b.y-a.y,c1=(a1*a1+b1*b1)/2;
    double a2=c.x-a.x,b2=c.y-a.y,c2=(a2*a2+b2*b2)/2;
    double d=a1*b2-a2*b1;
    C.x=a.x+(c1*b2-c2*b1)/d;
    C.y=a.y+(a1*c2-a2*c1)/d;
    return C;
}
void min_cover_circle(Point *p,int n,Point &c,double &r){
    random_shuffle(p,p+n);
    c=p[0],r=0;
    for(int i=1;i<n;++i)
        if(sgn(Distance(p[i],c)-r)>0){
            c=p[i],r=0;
            for(int j=0;j<i;++j)
                if(sgn(Distance(p[j],c)-r)>0){
                    c.x=(p[i].x+p[j].x)/2;
                    c.y=(p[i].y+p[j].y)/2;
                    r=Distance(p[j],c);
                    for(int k=0;k<j;++k)
                        if(sgn(Distance(p[k],c)-r)>0){
                            c=circle_center(p[i],p[j],p[k]);
                            r=Distance(p[i],c);
                        }
                }
        }
}
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>p[i].x>>p[i].y;
    Point c;double r;
    min_cover_circle(p,n,c,r);
    cout<<fixed<<setprecision(10)<<r<<'\n'<<c.x<<' '<<c.y;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}