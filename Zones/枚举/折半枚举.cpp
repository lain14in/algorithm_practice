//https://vjudge.net/problem/CSES-3355
//把四平方和拆成两组两平方和，先枚举并记录所有两平方和的表示，再找一对和为n的两平方和并还原四个数，总时间为 O(n)
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);

void solve(){
    int n;cin>>n;
    vector<int>f(n+1,-1);//f[s]记录s=a²+b²中的a，-1表示没有找到表示方法
    for(int a=0;a*a<=n;++a)//O(√n)
        for(int b=a;a*a+b*b<=n;++b)//O(√n)
            f[a*a+b*b]=a;//记录这个平方和的一种表示，覆盖旧方案也没关系
    for(int s=0;s<=n/2;++s){//将n拆成s和n-s，两组对称，只需枚举较小的一组
        if(f[s]==-1||f[n-s]==-1)continue;
        int a=f[s],b=sqrt(s-a*a);//s=a²+b²来还原
        int c=f[n-s],d=sqrt(n-s-c*c);//n-s=c²+d²来还原
        cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
        return;
    }
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