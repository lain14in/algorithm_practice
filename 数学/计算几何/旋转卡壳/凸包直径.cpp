//https://www.luogu.com.cn/problem/P1452
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using db=double;
const int N=1e6+5,mod=1e9+7;
const double eps=1e-6;

int sgn(db x){
    if(fabs(x)<eps)return 0;
    return x<0?-1:1;
}
struct Point{
    db x,y;
    Point(){}
    Point(db x,db y):x(x),y(y){}
    Point operator + (Point B){return Point(x+B.x,y+B.y);}
    Point operator - (Point B){return Point(x-B.x,y-B.y);}
    bool operator == (Point B){return sgn(x-B.x)==0&&sgn(y-B.y)==0;}
    bool operator < (Point B){return sgn(x-B.x)<0||(sgn(x-B.x)==0&&sgn(y-B.y)<0);}
}p[N],ch[N];
typedef Point Vector;
db Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
ll Distance2(Point A,Point B){//距离的平方
    ll x=A.x-B.x,y=A.y-B.y;
    return x*x+y*y;
}
int Convex_hull(Point *p,int n,Point *ch){//顺时针求凸包的点
    sort(p,p+n);
    n=unique(p,p+n)-p;
    int v=0;
    for(int i=0;i<n;++i){
        while(v>1&&sgn(Cross(ch[v-1]-ch[v-2],p[i]-ch[v-1]))<=0)--v;
        ch[v++]=p[i];
    }
    for(int i=n-2,j=v;i>=0;--i){
        while(v>j&&sgn(Cross(ch[v-1]-ch[v-2],p[i]-ch[v-1]))<=0)--v;
        ch[v++]=p[i];
    }
    if(n>1)--v;
    return v;
}
ll Rotating_calipers(Point *ch,int n){//旋转卡壳求最大距离平方
    if(n<=1)return 0;
    if(n==2)return Distance2(ch[0],ch[1]);
    ll ans=0;
    for(int i=0,j=1;i<n;++i){//固定底边,面积大小反应距离大小,下一个面积增大就继续枚举下一个
        while(sgn(Cross(ch[(i+1)%n]-ch[i],ch[(j+1)%n]-ch[i])-Cross(ch[(i+1)%n]-ch[i],ch[j]-ch[i]))>0)j=(j+1)%n;
        ans=max(ans,Distance2(ch[i],ch[j]));
        ans=max(ans,Distance2(ch[(i+1)%n],ch[j]));
        if(sgn(Cross(ch[(i+1)%n]-ch[i],ch[(j+1)%n]-ch[i])-Cross(ch[(i+1)%n]-ch[i],ch[j]-ch[i]))==0){
            ans=max(ans,Distance2(ch[i],ch[(j+1)%n]));
            ans=max(ans,Distance2(ch[(i+1)%n],ch[(j+1)%n]));
        }//两个面积相等的时候还要看看另一个点。凸包性质，只会有一个面积相等的
    }
    return ans;
}
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>p[i].x>>p[i].y;
    int v=Convex_hull(p,n,ch);
    cout<<Rotating_calipers(ch,v)<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}