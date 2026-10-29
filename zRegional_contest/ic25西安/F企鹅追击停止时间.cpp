//https://qoj.ac/contest/2562/problem/14686
//链式前向星存图，小根堆维护当前最近停止的事件，找到目标后就永远停下，所以目标只会停一次，最多改变一次时间状态
//只考虑同向目标停下、相向目标不停、相向目标停下三种情况（同向不停追不上，因为速度一致，而且题目是一定会停）
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<ll,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
const ll INF=1LL<<62;
void solve(){
    int n;cin>>n;//head[u]指向第一个追逐企鹅u的企鹅(企鹅u的追逐者链表从哪里开始);nxt[v]与企鹅v追逐同一个目标的下一个企鹅是谁
    vector<int>t(n+1),s(n+1),head(n+1,-1),nxt(n+1);
    vector<ll>a(n+1),ans(n+1,-1),time(n+1,INF);//ans确定的最终停止时间;time当前预计停止时间
    for(int i=1;i<=n;++i)cin>>t[i];
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        s[i]=(a[t[i]]>a[i])?1:-1;//1向右 -1向左
        nxt[i]=head[t[i]];//链式前向星存反向边（数组模拟链表，并采用头插法）
        head[t[i]]=i;
    }
    priority_queue<pii,vector<pii>,greater<pii>>q;//存{当前预计停止时间,企鹅编号}
    for(int i=1;i<=n;++i){//放入一开始就可以停止的事件（相向而行一定相遇）
        if(s[t[i]]!=s[i]){
            time[i]=abs(a[t[i]]-a[i]);
            q.push({time[i],i});
        }
    }
    while(!q.empty()){//每次处理当前最先停止的事件
        auto [now,u]=q.top();q.pop();
        if(ans[u]!=-1||now!=time[u])continue;//已停止/是过期事件则跳过
        ans[u]=now;//u在now时停止
        for(int v=head[u];v!=-1;v=nxt[v]){//遍历所有以u为目标的企鹅v
            if(ans[v]!=-1)continue;//v已经停下，不用更新
            ll d=abs(a[v]-a[u]);//u-v初始距离
            if(s[v]==s[u])time[v]=now+2*d;//同向
            else time[v]=2*d-now;//相向
            q.push({time[v],v});
        }
    }
    for(int i=1;i<=n;++i)cout<<ans[i]<<' ';
    cout<<'\n';
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