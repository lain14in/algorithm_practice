//https://qoj.ac/contest/1885/problem/9919
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=2505,mod=1e9+7;
struct Point{
    ll x,y;
    int id;
    Point(ll x=0,ll y=0,int id=-1):x(x),y(y),id(id){}
    Point operator +(Point B)const{return Point(x+B.x,y+B.y);}
    Point operator -(Point B)const{return Point(x-B.x,y-B.y);}
    bool operator <(Point B)const{
        return y==B.y?x<B.x:y<B.y;
    }
    ll len2()const{return x*x+y*y;}
    int quad()const{return y>0||(y==0&&x>0);}
};
typedef Point Vector;
ll Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
int n,ans;
bool on[N];
vector<Point>p;
bool Left(Point A,Point B){
    return Cross(B,A)>0;
}
int Area(vector<Point>a){
    ll s=0;
    int m=a.size();
    for(int i=0;i<m;++i)
        s=(s+Cross(a[i],a[(i+1)%m]))%mod;
    return (s+mod)%mod;
}
void calc(vector<Point>b){
    sort(b.begin(),b.end(),[&](Point a,Point c){
        if(a.quad()!=c.quad())return a.quad()>c.quad();
        return Left(c,a);
    });
    for(int i=0;i<(int)b.size();++i){
        if(on[b[i].id]){
            rotate(b.begin(),b.begin()+i,b.end());
            break;
        }
    }
    b.push_back(b[0]);
    int cnt=0;
    ll now=0;
    vector<Point>st;
    for(auto &q:b){
        while(st.size()>1&&Left(st.back()-st[st.size()-2],q-st[st.size()-2])){
            now=(now-Cross(st[st.size()-2],st.back()))%mod;
            st.pop_back();
        }
        if(st.size())
            now=(now+Cross(st.back(),q))%mod;
        st.push_back(q);
        ++cnt;
        if(on[q.id]){
            if(st.size()>1)
                ans=(ans+1LL*cnt*
                    (Cross(st[st.size()-2],st.back())%mod))%mod;
            cnt=0;
            now=0;
        }
        ans=(ans-now)%mod;
    }
    reverse(b.begin(),b.end());
    now=0;
    for(auto &q:b){
        while(st.size()>1&&Left(q-st[st.size()-2],st.back()-st[st.size()-2])){
            now=(now-Cross(st.back(),st[st.size()-2]))%mod;
            st.pop_back();
        }
        if(st.size())
            now=(now+Cross(q,st.back()))%mod;
        st.push_back(q);
        if(on[q.id])now=0;
        ans=(ans-now)%mod;
    }
}
void solve(){
    cin>>n;
    p.resize(n);
    for(int i=0;i<n;++i){
        cin>>p[i].x>>p[i].y;
        p[i].id=i;
    }
    Point O=*min_element(p.begin(),p.end());
    sort(p.begin(),p.end(),[&](Point a,Point b){
        a=a-O;
        b=b-O;
        if(Cross(a,b)==0)return a.len2()<b.len2();
        return Left(b,a);
    });
    vector<Point>st;
    for(auto &q:p){
        while(st.size()>1&&Left(st.back()-st[st.size()-2],q-st[st.size()-2]))
            st.pop_back();
        st.push_back(q);
    }
    for(auto &q:st)on[q.id]=1;
    for(auto &t:p){
        if(on[t.id])continue;
        vector<Point>b;
        for(auto &q:p){
            if(q.id==t.id)continue;
            b.push_back(q-t);
            b.back().id=q.id;
        }
        calc(b);
    }
    ans=(ans+mod)%mod;
    ans=(1LL*(n-1)*(n-(int)st.size())%mod*
        Area(st)%mod-ans+mod)%mod;
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}