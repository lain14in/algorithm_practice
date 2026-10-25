//https://ac.nowcoder.com/acm/contest/141878/D
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=5e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
// p[i]：第i次进攻的位置
// nxt[i]：第i次进攻的位置，下一次被进攻的时间
// last[x]：倒序处理后，位置x第一次被进攻的时间
// ans[x]：第x个人受到伤害的次数
int n,m,k,p[N],nxt[N],last[N],ans[N];
int tr[N*4];
void build(int u,int l,int r){
    if(l==r){
        tr[u]=last[l];
        return;
    }
    int mid=(l+r)/2;
    build(u*2,l,mid);
    build(u*2+1,mid+1,r);
    tr[u]=max(tr[u*2],tr[u*2+1]);
}
void modify(int u,int l,int r,int x,int v){
    if(l==r){
        tr[u]=v;
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid)modify(u*2,l,mid,x,v);
    else modify(u*2+1,mid+1,r,x,v);
    tr[u]=max(tr[u*2],tr[u*2+1]);
}
int query(int u,int l,int r,int L,int R){//查询区间元素最大值
    if(L<=l&&r<=R)return tr[u];
    int mid=(l+r)/2,res=0;
    if(L<=mid)res=max(res,query(u*2,l,mid,L,R));
    if(R>mid)res=max(res,query(u*2+1,mid+1,r,L,R));
    return res;
}
void solve(){
    cin>>n>>m>>k;
    vector<vector<int>>event(k+2);//记录在1~k时间受伤的人
    fill(last+1,last+n+1,k+1);//k+1>k，在t=k+1攻击，即不会再攻击
    for(int i=1;i<=k;++i)cin>>p[i];
    for(int i=k;i>=1;--i){
        nxt[i]=last[p[i]];//下一次出现在哪
        last[p[i]]=i;//当前出现在i
    }
    build(1,1,n);
    for(int i=m;i<=n;++i){//初始化每个人第一次受伤时间
        int t=query(1,1,n,i-m+1,i);
        if(t<=k)event[t].push_back(i);
    }
    for(int i=1;i<=k;++i){//按进攻时间模拟
        modify(1,1,n,p[i],nxt[i]);//下次进攻时间发生变化
        for(int x:event[i]){//本次受伤
            ++ans[x];
            int t=query(1,1,n,x-m+1,x);
            if(t<=k)event[t].push_back(x);//更新下次受伤的人
        }
    }
    for(int i=1;i<=n;++i)cout<<ans[i]<<' ';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
线段树维护区间最大值：基础绿题知识。
倒序预处理下一次进攻时间：中等思维。
将集齐颜色转化为区间最大值：核心转化。
事件桶提前安排受伤时间：核心难点。
证明总受伤次数不超过 \(k\)：需要复杂度分析。
*/