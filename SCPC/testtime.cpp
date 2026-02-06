#include<bits/stdc++.h>
using namespace std;
const int mxn=5e6+100;
int f[mxn];
long long dp[mxn];
int main(){
    int n,x;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        f[x]++;
    }
    clock_t start, end;
    start = clock();
    for(int i=1;i<mxn;++i){
        for(int j=i+i;j<mxn;j+=i){
            f[i]+=f[j];
        }
    }
 
    for(int i=mxn-1;i;--i){
        dp[i]=1LL*i*f[i];
        for(int j=i+i;j<mxn;j+=i){
            dp[i]=max(dp[i],1LL*i*(f[i]-f[j])+dp[j]);
        }
    }
    end = clock();
    double exec_time = double(end-start)/double(CLOCKS_PER_SEC);
    printf("%lld\n",dp[1]);
    cout <<"Exec_time= " <<exec_time;
    cin >>n;
}