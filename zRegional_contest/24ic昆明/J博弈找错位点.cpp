//https://codeforces.com/gym/105588/problem/J
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e6+5,mod=1e9+7;

void solve(){
    int n,d=0;cin>>n;
    string s;cin>>s;
    string t1="Alice",t2="Bob";
    for(int i=1,a;i<=n;++i){
        cin>>a;
        if(a!=i)++d;
    }
    if((n==2)||(d==2&&s==t1)||(d==3&&n==3&&s==t2))cout<<t1<<'\n';
    else cout<<t2<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}