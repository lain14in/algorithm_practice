//https://codeforces.com/contest/2275/problem/D
//贪心+分类讨论，小根堆批量处理（本题也可以二分）
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-6;

void solve(){
    ll n,k;cin>>n>>k;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;//小根堆处理当前abc和最小的实验室
    for(int i=0;i<n;++i){
        ll a,b,c;cin>>a>>b>>c;
        ll extra;//可以在原abc之和的基础上开始+1所付出的操作数量代价
        if(a==b&&b==c)extra=-1;//改不了abc之和
        else if(a<=b&&b<=c)extra=2*(min(b-a,c-b)+1);//降低原有abc之和产生逆序对然后再加回来原来的abc之和，注意要严格>所以“+1”
        else extra=0;//一开始就可以直接+1
        q.push({a+b+c,extra});
    }
    ll h=q.top().first,cnt=0;
    while(1){
        ll extra=0;
        bool NOfix=0;//能不能提高当前最小实验室的abc和
        while(!q.empty()&&h==q.top().first){//算当前代价
            ll e=q.top().second;
            q.pop();
            ++cnt;
            if(e==-1)NOfix=1;
            else extra+=e;
        }
        if(NOfix||k<extra){//提高不了当前最小值（h）了
            cout<<h<<'\n';
            return;
        }
        ll res=h+(k-extra)/cnt;//剩下给当前cnt个全部整体提升的
        if(q.empty()){//已经把所有实验室都并进来了
            cout<<res<<'\n';
            return;
        }
        ll next=q.top().first;
        i128 need=(i128)(next-h)*cnt+extra;//下轮提高当前h所需要的操作数
        if(need>k){//再操作已经影响不了下一个实验室的值了，只能提提当前最小（h）
            cout<<res<<'\n';
            return;
        }
        k-=need;
        h=next;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
/*
算可以+1的代价extra（制造出逆序对然后变成相对原来abc之和开始+1的代价extra），
每次把当前最小的cnt个实验室并起来一起+1，然后看每轮能不能继续O(nlogn)
*/