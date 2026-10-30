//https://qoj.ac/contest/2609/problem/14721
//周期规律构造+分类讨论
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+5;
int a[3][6]={{0,1,1,2,2,0},{1,0,2,1,0,2},{2,2,0,0,1,1}};
int aa[3][6]={{2,2,0,0,1,1},{1,0,2,1,0,2},{0,1,1,2,2,0}};
int b[6][3]={{2,1,0},{2,0,1},{0,2,1},{0,1,2},{1,0,2},{1,2,0}};
int bb[6][3]={{0,1,2},{1,0,2},{1,2,0},{2,1,0},{2,0,1},{0,2,1}};
void solve(){
    int n,m;cin>>n>>m;
    if(n==1&&m==6){cout<<"Yes\n001122\n";return;}
    if(m==1&&n==6){cout<<"Yes\n0\n0\n1\n1\n2\n2\n";return;}
    if(n==6&&m==2){cout<<"Yes\n00\n00\n11\n11\n22\n22\n";return;}
    if(m==6&&n==2){cout<<"Yes\n001122\n001122\n";return;}
    if(n==4){
        cout<<"Yes\n";
        for(int i=0;i<n-1;++i){
            for(int j=0;j<m;++j)cout<<a[i%3][j%6];
            cout<<'\n';
            if(i%3==1){//两次中间
                for(int j=0;j<m;++j)cout<<a[1][j%6];
                cout<<'\n';
            }
        }
        cout<<'\n';
        return;
    }
    if(m==4){
        cout<<"Yes\n";
        for(int i=0;i<n;++i){
            for(int j=0;j<m-1;++j){
                cout<<b[i%6][j%3];
                if(j%3==1)cout<<b[i%6][j%3];//两次中间
            }
            cout<<'\n';
        }
        return;
    }
    if(m==3){//避免n>=6的时候出问题
        cout<<"Yes\n";
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j)cout<<b[i%6][j%3];
            cout<<'\n';
        }
        return;
    }
    if(n%3==0){
        if(n==3){
            cout<<"Yes\n";
            for(int i=0;i<n;++i){
                for(int j=0;j<m;++j)cout<<a[i%3][j%6];
                cout<<'\n';
            }
        }else if(n==6){
            if(m<4){cout<<"No\n";return;}//实际上已经有特解，前面给了，这条只是逻辑上看
            cout<<"Yes\n";
            for(int i=0;i<3;++i){
                for(int j=1;j<=m;++j)cout<<a[i%3][j%6];
                cout<<'\n';
            }
            for(int i=3;i<n;++i){
                for(int j=1;j<=m;++j)cout<<aa[i%3][j%6];
                cout<<'\n';
            }
        }else{
            if(m<5){cout<<"No\n";return;}
            cout<<"Yes\n";
            for(int i=0,f=0;i<n;++i){
                if(i%3==0)f^=1;
                if(f){
                    for(int j=0;j<m;++j)cout<<a[i%3][j%6];
                    cout<<'\n';
                }else{
                    for(int j=0;j<m;++j)cout<<aa[i%3][j%6];
                    cout<<'\n';
                }
            }
        }
    }else{
        if(m==3){
            cout<<"Yes\n";
            for(int i=0;i<n;++i){
                for(int j=0;j<m;++j)cout<<b[i%6][j%3];
                cout<<'\n';
            }
        }else if(m==6){
            if(n<4){cout<<"No\n";return;}//实际上已经有特解，前面给了，这条只是逻辑上看
            cout<<"Yes\n";
            for(int i=0;i<n;++i){
                for(int j=0,f=0;j<m;++j){
                    if(j%3==0)f^=1;
                    if(f)cout<<b[i%6][j%3];
                    else cout<<bb[i%6][j%3];
                }
                cout<<'\n';
            }
        }else{
            if(n<5){cout<<"No\n";return;}
            cout<<"Yes\n";
            for(int i=0;i<n;++i){
                for(int j=0,f=0;j<m;++j){
                    if(j%3==0)f^=1;
                    if(f)cout<<b[i%6][j%3];
                    else cout<<bb[i%6][j%3];
                }
                cout<<'\n';
            }
        }
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
有满足的n=3,m=6的循环周期块，然后每块循环取
按n是3的倍数还是m是3的倍数分类，还有别的几个特殊情况，
以及这两个类别的交叉处出问题（比如n是3的倍数，n>=6但是m==3的时候）
*/