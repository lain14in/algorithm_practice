//https://vjudge.net/problem/UVA-1497
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=4,mod=1e9+7;
const double eps=1e-6,pi=acos(-1.0);
struct matrix{
    double num[N][N];
    matrix(double a){
        memset(num,0,sizeof(num));
        for(int i=0;i<N;++i)num[i][i]=a;
    }
    matrix(double x,double y,double z){
        memset(num,0,sizeof(num));
        for(int i=0;i<N;++i)num[i][i]=1;
        num[3][0]=x,num[3][1]=y,num[3][2]=z;
    }
    matrix(double x,double y,double z,int X){
        memset(num,0,sizeof(num));
        for(int i=0;i<N;++i)num[i][i]=1;
        num[0][0]=x,num[1][1]=y,num[2][2]=z;
    }
    matrix(double P[3],double ang){
        memset(num,0,sizeof(num));
        for(int i=0;i<N;++i)num[i][i]=1;
        double flag[3][3]={0,1,-1,-1,0,1,1,-1,0};
        double sum=P[0]+P[1]+P[2];
        for(int i=0;i<3;++i)
            for(int j=0;j<3;++j)
                if(i==j)num[i][j]=P[i]*P[i]+(1-P[i]*P[i])*cos(ang);
                else num[i][j]=P[i]*P[j]*(1-cos(ang))+(sum-P[i]-P[j])*sin(ang)*flag[i][j];
    }
};
matrix operator*(matrix a,matrix b){
    matrix c(0);
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            for(int k=0;k<N;++k)
                c.num[i][j]+=a.num[i][k]*b.num[k][j];
    return c;
}
matrix pow_matrix(matrix a,int n){
    matrix ans(1);
    while(n){
        if(n&1)ans=ans*a;
        a=a*a;
        n>>=1;
    }
    return ans;
}
matrix dfs(){
    matrix ans(1);
    while(1){
        string cmd;cin>>cmd;
        if(cmd=="end")return ans;
        if(cmd=="repeat"){
            int k;cin>>k;
            matrix temp=dfs();
            ans=ans*pow_matrix(temp,k);
        }else{
            double x,y,z;cin>>x>>y>>z;
            if(cmd=="translate"){matrix temp(x,y,z);ans=ans*temp;}
            else if(cmd=="scale"){matrix temp(x,y,z,0);ans=ans*temp;}
            else if(cmd=="rotate"){
                double a;cin>>a;
                a=a/180*pi;
                double sum=sqrt(x*x+y*y+z*z);
                double p[3]={x/sum,y/sum,z/sum};
                matrix temp(p,a);
                ans=ans*temp;
            }
        }
    }
}
void solve(){
    int n;
    while(cin>>n&&n){
        matrix t=dfs();
        while(n--){
            double x,y,z,px,py,pz;cin>>x>>y>>z;
            px=x*t.num[0][0]+y*t.num[1][0]+z*t.num[2][0]+t.num[3][0];
            py=x*t.num[0][1]+y*t.num[1][1]+z*t.num[2][1]+t.num[3][1];
            pz=x*t.num[0][2]+y*t.num[1][2]+z*t.num[2][2]+t.num[3][2];
            cout<<fixed<<setprecision(2)<<px+eps<<' '
                <<fixed<<setprecision(2)<<py+eps<<' '
                <<fixed<<setprecision(2)<<pz+eps<<'\n';
        }
        cout<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}