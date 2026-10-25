//https://ac.nowcoder.com/acm/contest/141878/C
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);

void solve(){
    int n;cin>>n;
    vector<pair<int,int>>p(n);
    int xmin,xmax,ymin,ymax,a1,a2,b1,b2;
    ymin=xmin=b2=a2=1e9;
    ymax=xmax=b1=a1=-1e9;
    for(auto &[x,y]:p){//维护凸包边界
        cin>>x>>y;
        xmin=min(xmin,x),xmax=max(xmax,x);//原黑点自身范围限制
        ymin=min(ymin,y),ymax=max(ymax,y);
        b2=min(b2,y-x),b1=max(b1,y-x);//y=x+b这两条“凸包”的外接线
        a2=min(a2,x+y),a1=max(a1,x+y);//y=-x+a这两条“凸包”的外接线
    }
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    ll ans=0;
    for(int x=xmin;x<=xmax;++x){
        int h=min({x+b1,-x+a1,ymax}),l=max({x+b2,-x+a2,ymin});//h小于上面两条交叉线以及ymax;l大于下面两条交叉线以及ymin
        if(h>=l)ans+=h-l+1;//枚举每一列当中夹在“凸包”内的黑点数
    }
    ans-=p.size();//去除已有的黑点
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}