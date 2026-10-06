//https://acm.hdu.edu.cn/showproblem.php?pid=2297
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=2e5+5,mod=1e9+7;
const double INF=1e12,pi=acos(-1.0),eps=1e-8;
int sgn(double x){
    if(fabs(x)<eps)return 0;
    return x<0?-1:1;
}
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator + (Point B){return Point(x+B.x,y+B.y);}
    Point operator - (Point B){return Point(x-B.x,y-B.y);}
    Point operator * (double k){return Point(x*k,y*k);}
};
typedef Point Vector;
double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
struct Line{
    Point p;
    Vector v;
    double ang;
    Line(){}
    Line(Point p,Vector v):p(p),v(v){ang=atan2(v.y,v.x);}
    bool operator < (Line &L){return ang<L.ang;}
};
bool OnLeft(Line L,Point p){return sgn(Cross(L.v,p-L.p))>0;}
Point Cross_point(Line a,Line b){
    Vector u=a.p-b.p;
    double t=Cross(b.v,u)/Cross(a.v,b.v);
    return a.p+a.v*t;
}
vector<Point>HPI(vector<Line>L){
    int n=L.size();
    sort(L.begin(),L.end());
    int first=0,last=0;
    vector<Point>p(n),ans;
    vector<Line>q(n);
    q[0]=L[0];
    for(int i=1;i<n;++i){
        while(first<last&&!OnLeft(L[i],p[last-1]))--last;
        while(first<last&&!OnLeft(L[i],p[first]))++first;
        q[++last]=L[i];
        if(fabs(Cross(q[last].v,q[last-1].v))<eps){
            --last;
            if(OnLeft(q[last],L[i].p))q[last]=L[i];
        }
        if(first<last)p[last-1]=Cross_point(q[last-1],q[last]);
    }
    while(first<last&&!OnLeft(q[first],p[last-1]))--last;
    if(last-first<=1)return ans;
    p[last]=Cross_point(q[last],q[first]);
    for(int i=first;i<=last;++i)ans.push_back(p[i]);
    return ans;
}
void solve(){
    int n;cin>>n;
    vector<Line>L;
    L.push_back(Line(Point(0,0),Vector(0,-1)));
    L.push_back(Line(Point(0,INF),Vector(-1,0)));
    while(n--){
        double a,b;cin>>a>>b;
        L.push_back(Line(Point(0,a),Vector(1,b)));
    }
    vector<Point>ans=HPI(L);
    cout<<ans.size()-2<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}