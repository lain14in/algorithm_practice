//https://vjudge.net/problem/CSES-3397
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=21,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
ll fac[N];
void init(){
    fac[0]=1;
    for(int i=1;i<N;++i)fac[i]=fac[i-1]*i;
}
//排列->排名 康托展开：统计每位右边比它小的数字个数，乘以剩余位数的阶乘，最后加 1。 O(n^2)
ll cantor(vector<int>a){//不需要对数组排序
    int n=a.size();
    ll k=1;
    for(int i=0;i<n;++i){
        int cnt=0;
        for(int j=i+1;j<n;++j)
            if(a[j]<a[i])++cnt;
        k+=cnt*fac[n-i-1];//数组下标i应该是第i+1个数，所以多-1
    }
    return k;
}
//排名->排列 逆康托展开：把排名减 1，用阶乘不断整除、取余，逐位选择剩余数字。 O(n^2)
vector<int>decantor(int n,ll k){//对于不是1~n的元素排列，只需传入数组a然后升序排序一下
    vector<int>a(n),res;
    for(int i=0;i<n;++i)a[i]=i+1;
    --k;
    for(int i=n-1;i>=0;--i){
        int p=k/fac[i];
        res.push_back(a[p]);
        a.erase(a.begin()+p);
        k%=fac[i];
    }
    return res;
}
/*
// 多重集康托展开：排列 -> 排名 O(n^2)
ll cantor(vector<int>a){//传入字典序第k个序列，返回字典序k
    map<int,int>cnt;
    for(int x:a)++cnt[x];
    int n=a.size();
    ll ways=fac[n],k=1;
    for(auto [x,c]:cnt)ways/=fac[c];
    for(int x:a){
        for(auto [v,c]:cnt){
            if(v>=x)break;
            k+=ways*c/n;
        }
        ways=ways*cnt[x]/n;
        --cnt[x];
        --n;
    }
    return k;
}
// 多重集逆康托展开：排名 -> 排列 O(n^2)
vector<int>decantor(vector<int>a,ll k){//传入集合、字典序k，返回字典序第k个序列
    map<int,int>cnt;
    for(int x:a)++cnt[x];
    int n=a.size();
    ll ways=fac[n];
    for(auto [x,c]:cnt)ways/=fac[c];
    vector<int>res;
    for(int i=n;i>=1;--i){
        for(auto &[v,c]:cnt){
            if(!c)continue;
            ll t=ways*c/i;
            if(k>t)k-=t;
            else{
                res.push_back(v);
                ways=t;
                --c;
                break;
            }
        }
    }
    return res;
}
*/
void solve(){
    int op,n;cin>>op>>n;
    if(op==1){
        ll k;cin>>k;
        vector<int>ans=decantor(n,k);
        for(int x:ans)cout<<x<<' ';
        cout<<'\n';
    }else{
        vector<int>a(n);
        for(int i=0;i<n;++i)cin>>a[i];
        cout<<cantor(a)<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    init();
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}