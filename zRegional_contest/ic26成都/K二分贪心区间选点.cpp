//https://qoj.ac/contest/4600/problem/23602
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
int n;
ll a[N],l[N];
bool check(ll d){//判断最大误差不超过d是否可行
    ll mn=a[1]-d,mx=a[1]+d;//上一步可行位置的最小值、最大值，中间不一定都可选
    for(int i=2;i<=n;++i){
        ll L=a[i]-d,R=a[i]+d;//当前误差限制允许的范围[L,R]
        ll x=min(R,mx-l[i]),y=max(L,mn+l[i]);
        //前一个位置取mx，当前可选左侧区间[L,x]
        //前一个位置取mn，当前可选右侧区间[y,R]
        //当前可行位置是这两个区间的并集，空区间忽略
        if(x<L&&y>R)return 0;//两个区间都为空，无解
        mn=x>=L?L:y;//左侧非空取L，否则取右侧起点y
        mx=y<=R?R:x;//右侧非空取R，否则取左侧终点x
    }
    return 1;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    ll L=0,R=0;
    for(int i=2;i<=n;++i){
        cin>>l[i];
        R=max(R,l[i]);//上界取最大的距离要求
    }
    while(L<=R){
        ll mid=(L+R)/2;
        if(check(mid))R=mid-1;
        else L=mid+1;
    }
    cout<<L<<'\n';
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
/*
二分最大误差 `d`，此时每个测试位置只能选在 `[a[i]-d,a[i]+d]` 内。
判定时维护上一步可行位置的最小值 `mn` 和最大值 `mx`：当前点若放在左边，只需与 `mx` 相距至少 `l[i]`；
若放在右边，只需与 `mn` 相距至少 `l[i]`。将这两种范围分别与当前允许区间相交，两者都为空则不可行，
否则更新可行位置的最小值、最大值并继续，
最终二分得到最小可行误差，复杂度为 `O(n log max(l[i]))`。
*/