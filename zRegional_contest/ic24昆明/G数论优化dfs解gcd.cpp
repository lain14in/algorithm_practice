//https://codeforces.com/gym/105588/problem/G
//1. 两个数同时除以最大公约数，操作次数不变，不影响答案。
//2. 答案最多26步操作，保守时间复杂度是O((a^2)log a)，空间复杂度O(log a)
//3. 从小到大dfs枚举允许步数
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
bool dfs(ll a,ll b,int d){//能否在d步以内将a、b归零
    if(d<2)return 0;//a、b都是正数，至少也要2步弄完
    ll g=__gcd(a,b);
    a/=g,b/=g;//不影响操作次数
    if(a==1||b==1)return 1;//2步可以做完：可以1步弄出一个0然后另一个数用性质gcd(0,b)=b去1步清0
    if(d==2)return 0;//2步不能做完
    return dfs(a-1,b,d-1)||dfs(a,b-1,d-1);//其余步数d>2去dfs递归解决
}
void solve(){
    ll a,b;cin>>a>>b;
    for(int ans=2;ans<=26;++ans){
        if(dfs(a,b,ans)){
            cout<<ans<<'\n';
            return;
        }
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
//2.考虑奇偶性：
//- 两个数都是偶数：直接同时除以2。
//- 存在奇数：此时最大公约数是奇数，选择一个奇数减去它，就变成偶数。
//所以最多操作两次，就能让两数都变成偶数，再同时除以2，重复12轮后：a<=(5000/(2^12))向上取整=1
//再用至多两步清零，总共不超过 \(24+2=26\) 步