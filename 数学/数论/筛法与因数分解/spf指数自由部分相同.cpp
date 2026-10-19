//https://codeforces.com/contest/2275/problem/F
//用质因子指数的奇偶性，判断乘积是不是完全平方数
//“平方自由部分”：把一个数中的平方因子全部除掉，只保留指数为奇数的质因子各一个（完全平方数的平方自由部分是1）
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e6+5,mod=1e9+7,INF=1e6;
const double eps=1e-6;
int spf[N],cnt[N];//最小质因子；平方自由部分的出现次数
void init(){//预处理最小质因子
    for(int i=2;i<=INF;++i){
        if(spf[i])continue;
        for(int j=i;j<=INF;j+=i)
            if(!spf[j])spf[j]=i;
    }
}
int odde(int x){//只保留指数为奇数的质因子
    int ans=1;
    while(x>1){
        int p=spf[x],odd=0;
        while(x%p==0){
            x/=p;
            odd^=1;
        }
        if(odd)ans*=p;
    }
    return ans;
}
void solve(){
    int n;cin>>n;
    vector<int>s(n+1);
    for(int i=1;i<=n;++i){//统计ai的所有“平方自由部分”
        int x;cin>>x;
        s[i]=odde(x);
        ++cnt[s[i]];
    }
    set<int>odd;//维护前缀乘积的奇数指数质因子
    ll ans=0;
    for(int i=1;i<=n;++i){
        int x=s[i];
        while(x>1){
            int p=spf[x];
            if(odd.find(p)==odd.end())odd.insert(p);
            else odd.erase(p);
            x/=p;
        }
        ll ker=1;//算出前缀的平方自由部分，并统计匹配
        for(int p:odd){
            ker*=p;
            if(ker>INF)break;
        }
        if(ker<=INF)ans+=cnt[ker];
    }
    cout<<ans<<'\n';
    for(int i=1;i<=n;++i)cnt[s[i]]=0;//N数量较大，单独清除本组计数快捷
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    init();
    cin>>T;
    while(T--)solve();
    return 0;
}
/*
正因数个数为奇数等价于完全平方数，而两个数相乘为平方数，当且仅当它们的平方自由部分相同。
代码先用筛法预处理最小质因子，通过 `odde()` 求每个 `a[i]` 的平方自由部分并用 `cnt` 计数；
再遍历前缀，用 `set` 的插入、删除维护前缀乘积中指数为奇数的质因子，将它们相乘得到 `ker`，累加 `cnt[ker]`。
若 `ker>10^6`，则无法匹配，跳过本次统计；最后清除本组计数。
*/