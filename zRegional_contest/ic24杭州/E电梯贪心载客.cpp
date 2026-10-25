//https://codeforces.com/gym/105657/problem/E
//我们不是要让电梯总共上升的距离最短，而是要让电梯「没有载人时」上升的距离最短。
//在当前不需要空载上升就能接到的乘客中，优先选择终点最高的那个。
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=1e6+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
struct E{
    ll l,r;
    int id;
};
void solve(){
    int n;ll f;cin>>n>>f;
    vector<E>a(n);
    ll ans=0,mx=0;
    for(int i=0;i<n;++i){
        cin>>a[i].l>>a[i].r;
        a[i].id=i;
        ans+=a[i].r-a[i].l;
        mx=max(mx,a[i].l);
    }
    sort(a.begin(),a.end(),[](E x,E y){return x.l<y.l;});
    vector<int>ord,vis(n);
    ll h=f;
    int j=0;
    while(h<mx){
        ll best=h;
        int id=-1;
        while(j<n&&a[j].l<=h){
            if(a[j].r>best){
                best=a[j].r;
                id=j;
            }
            ++j;
        }
        if(id!=-1){
            ord.push_back(id);
            vis[id]=1;
            h=best;
        }else h=a[j].l;
    }
    for(int i=n-1;i>=0;--i)
        if(!vis[i])ord.push_back(i);
    h=f;
    for(int id:ord){
        ans+=max(a[id].l-h,0LL);
        h=a[id].r;
    }
    cout<<ans<<'\n';
    for(int id:ord)cout<<a[id].id+1<<' ';
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
/*
贪心 + 排序 + 双指针，\(O(n\log n)\)。 由于每位乘客从 \(l_i\) 到 \(r_i\) 的载客上升费用固定，因此只需最小化空载上升费用。
首先将乘客按起点 \(l\) 升序排序，令 \(h=f\) 表示当前向上扩展到的高度，用双指针扫描所有满足 \(l_i\le h\) 的乘客，
贪心选择其中终点 \(r_i\) 最大的乘客，将其加入答案序列并更新 \(h=r_i\)；如果没有乘客能够继续向上扩展，就将 \(h\) 提升到下一个尚未扫描的乘客起点（必须空载上升）。
重复直到 \(h\ge\max(l_i)\)，此时所有剩余乘客都可以免费下降接到，因此将未选中的乘客按照 \(l\) 降序加入答案序列。最后按照构造的顺序模拟电梯运行，计算固定载客费用与空载上升费用之和。
核心贪心：优先利用乘客的上升区间尽可能到达更高楼层，只有无法继续扩展时才支付空载上升费用。
*/