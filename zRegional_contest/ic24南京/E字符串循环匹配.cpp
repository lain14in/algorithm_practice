//https://codeforces.com/gym/105484/problem/E
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e6+5,mod=1e9+7;

void solve(){
    int n,k;cin>>n>>k;
    string s,t="nanjing";cin>>s;
    if(n<7){cout<<"0\n";return;}
    s+=s;
    vector<int>p(2*n+1);
    int ans=0;
    for(int i=0;i<2*n;++i){
        p[i+1]=p[i];
        if(i+7<=2*n){
            bool ok=1;
            for(int j=0;j<7;++j)
                if(s[i+j]!=t[j])ok=0;
            p[i+1]+=ok;
        }
    }
    for(int i=0;i<=min(k,n-1);++i)ans=max(ans,p[i+n-6]-p[i]);
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
/*滑动窗口
void solve(){
    int n;
    ll k;cin>>n>>k;
    string s;cin>>s;
    if(n<7){
        cout<<0<<'\n';
        return;
    }
    s+=s;
    int w=n-6,lim=min<ll>(k,n-1),cnt=0,ans=0;
    for(int i=0;i<lim+w;++i){
        cnt+=s.compare(i,7,"nanjing")==0;
        if(i>=w)cnt-=s.compare(i-w,7,"nanjing")==0;
        if(i>=w-1)ans=max(ans,cnt);
    }
    cout<<ans<<'\n';
}
*/
/*substr版本前缀和
for(int i=0;i+7<=2*n;++i){
        pre[i+1]=pre[i]+(s.substr(i,7)==t);
    }
    for(int i=2*n-6;i<2*n;++i)pre[i+1]=pre[i];
*/