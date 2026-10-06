//https://atcoder.jp/contests/abc476/tasks/abc476_e
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=2e5+5,mod=1e9+7;
int a[N],p[N],tr1[N],tr2[N],n,m;
int lb(int x){return x&(-x);}
void up(int x){
    while(x<=n){
        tr1[x]=tr2[x]=a[x];
        for(int i=1;i<lb(x);i<<=1){
            tr1[x]=max(tr1[x],tr1[x-i]);
            tr2[x]=min(tr2[x],tr2[x-i]);
        }
        x+=lb(x);
    }
}
int qr1(int l,int r){
    int ans=0;
    while(l<=r){
        ans=max(ans,a[r]);
        --r;
        while(r-l>=lb(r)){
            ans=max(ans,tr1[r]);
            r-=lb(r);
        }
    }
    return ans;
}
int qr2(int l,int r){
    int ans=n+1;
    while(l<=r){
        ans=min(ans,a[r]);
        --r;
        while(r-l>=lb(r)){
            ans=min(ans,tr2[r]);
            r-=lb(r);
        }
    }
    return ans;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i],p[a[i]]=i,up(i);
    while(m--){
        int l,r;cin>>l>>r;
        int mx=qr1(l,r),mn=qr2(l,r);
        swap(a[p[mx]],a[p[mn]]);
        swap(p[mx],p[mn]);
        up(p[mx]);
        up(p[mn]);
    }
    for(int i=1;i<=n;++i)cout<<a[i]<<' ';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}