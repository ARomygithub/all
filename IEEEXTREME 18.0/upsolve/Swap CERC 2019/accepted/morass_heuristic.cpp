/*
 * Some greedy unproved heuristic
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define ZERO (1e-10)
#define INF int(1e9+1)
#define CL(A,I) (memset(A,I,sizeof(A)))
#define DEB printf("DEB!\n");
#define D(X) cout<<"  "<<#X": "<<X<<endl;
#define EQ(A,B) (A+ZERO>B&&A-ZERO<B)
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define IN(n) int n;scanf("%d",&n);
#define FOR(i, m, n) for (int i(m); i < n; i++)
#define F(n) FOR(i,0,n)
#define FF(n) FOR(j,0,n)
#define FT(m, n) FOR(k, m, n)
#define aa first
#define bb second
void ga(int N,int *A){F(N)scanf("%d",A+i);}
#define MX 1000666
#define VL(C) (C^65?C^67?C^71?3:2:1:0)
char s[MX],r[MX];
int N,G[4][4],S;
int main(void){
    scanf("%s%s",s,r),N=strlen(s),assert(N==int(strlen(r)));
    F(N)++G[VL(s[i])][VL(r[i])];
    F(4)S+=G[i][i],G[i][i]=0;
    FT(2,5){
        int a,A[]={0,1,2,3};
        do{
            a=INF;
            F(k)a=min(G[A[i]][A[(i+1)%k]],a);
            S+=a;
            F(k)G[A[i]][A[(i+1)%k]]-=a;
        }while(next_permutation(A,A+4));
    }
    printf("%d\n",N-S);
    return 0;
}
