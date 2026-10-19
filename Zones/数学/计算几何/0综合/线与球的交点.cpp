//http://vjudge.net/problem/OpenJ_Bailian-2177
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-7;
int sgn(double x){
    if(fabs(x)<eps)return 0;
    return x>0?1:-1;
}
struct Point3{
    double x,y,z;
    Point3(){}
    Point3(double x,double y,double z):x(x),y(y),z(z){}
    Point3 operator+(Point3 B){return Point3(x+B.x,y+B.y,z+B.z);}
    Point3 operator-(Point3 B){return Point3(x-B.x,y-B.y,z-B.z);}
    Point3 operator*(double k){return Point3(x*k,y*k,z*k);}
    Point3 operator/(double k){return Point3(x/k,y/k,z/k);}
    Point3 adjust(double L){
        double len=sqrt(x*x+y*y+z*z);
        L/=len;
        return Point3(x*L,y*L,z*L);
    }
};
typedef Point3 Vector3;
double Dot(Vector3 A,Vector3 B){return A.x*B.x+A.y*B.y+A.z*B.z;}
Vector3 Cross(Vector3 A,Vector3 B){return Point3(A.y*B.z-A.z*B.y,A.z*B.x-A.x*B.z,A.x*B.y-A.y*B.x);}
double Len(Vector3 A){return sqrt(Dot(A,A));}
double Distance(Point3 A,Point3 B){return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)+(A.z-B.z)*(A.z-B.z));}
struct Line3{
    Point3 p1,p2;
    Line3(){}
    Line3(Point3 p1,Point3 p2):p1(p1),p2(p2){}
};
double Dis_point_line(Point3 p,Line3 v){return Len(Cross(v.p2-v.p1,p-v.p1))/Distance(v.p1,v.p2);}
vector<Point3>P;
void intersect(Point3 c1,double r1,Point3 c2,double r2){
    double d1=Len(c1),d2=Len(c2);
    c2=c2/d2*d1,r2=r2/d2*d1;
    double d=Len(c1-c2);
    if(sgn(d-r1-r2)==0){P.push_back(c1+(c2-c1)/d*r1);return;}
    if(sgn(d-r1-r2)>0)return;
    if(sgn(d-fabs(r1-r2))<=0)return;
    double b=(r1*r1+d*d-r2*r2)/(2*d);
    double h=sqrt(r1*r1-b*b);
    Point3 M=c1+(c2-c1)/d*b;
    Point3 v=Cross(c1,M);
    v=v.adjust(h)+M;
    P.push_back(v);
    P.push_back(M*2-v);
}
int check(Point3 p,Point3 c,double r){
    Line3 v(Point3(0,0,0),p);
    double x=Dis_point_line(c,v);
    return sgn(x-r)<=0;
}
Point3 c[N];
double r[N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;++i){
        cin>>c[i].x>>c[i].y>>c[i].z>>r[i];
        P.push_back(c[i]);
    }
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            intersect(c[i],r[i],c[j],r[j]);
    int ans=0,temp,w;
    for(int i=0;i<P.size();++i){
        temp=0;
        for(int j=1;j<=n;++j)temp+=check(P[i],c[j],r[j]);
        if(temp>ans)ans=temp,w=i;
    }
    cout<<ans<<'\n';
    for(int i=1;i<=n&&ans;++i){
        if(check(P[w],c[i],r[i])){
            --ans;
            if(ans)cout<<i<<' ';
            else cout<<i<<'\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}