#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rng(i,b,e) for(int i=(b);i<=(e);i++)
#define gnr(i,e,b) for(int i=(e);i>=(b);i--)
#define vc vector
#define vi vector<int>
#define pb push_back
#define fi first 
#define se second
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using t3 = tuple<int,int,int>;
#define si(x) (int)(x.size())
#define all(x) x.begin(),x.end()
unordered_map<int,int>Map;
bool Compare(t3 a, t3 b){ // true when a is stronger
	auto [ax,ay,az] = a;
	auto [bx,by,bz] = b;
	if((ax<bx) + (ay<by) + (az<bz) >= 2)return true;
	return false;
}
vc<t3>w;
#define N_ 201000
int A[500][1<<10], C[500], NB, TP[N_], Rank[N_], n;
void Spread(){
	int c=0;
	rng(i,0,NB){
		rep(j,C[i]){
			TP[c++] = A[i][j];
		}
		C[i]=0;
	}
	rep(i,c){
		A[i>>9][C[i>>9]++] = TP[i];
	}
	NB = (c-1)>>9;
}
void Ins(int a){
	int pv = -1;
	rng(i,0,NB){
		if(C[i] && Compare(w[a],w[A[i][C[i]-1]])){
			pv=i;
			break;
		}
	}
	if(pv==-1){
		A[NB][C[NB]]=a;
		C[NB]++;
		pv = NB;
	}
	else{
		int loc = 0;
		gnr(i,C[pv]-1,0){
			if(Compare(w[A[pv][i]],w[a])){
				loc = i+1;
				break;
			}
		}
		gnr(i,C[pv]-1,loc)A[pv][i+1]=A[pv][i];
		C[pv]++;
		A[pv][loc] = a;
	}
	if(C[pv]>=1000)Spread();
}
const int SZ = (1<<18);
int IT[SZ+SZ];
void Put(int a, int b){
	a+=SZ;
	while(a){
		IT[a]=max(IT[a],b);
		a>>=1;
	}
}
int GetMax(int b, int e){
	b+=SZ,e+=SZ;
	int r=0;
	while(b<=e){
		r=max(r,max(IT[b],IT[e]));
		b=(b+1)>>1,e=(e-1)>>1;
	}
	return r;
}

int R[N_];

void Do(vi X, vi Y){
	rep(i,SZ+SZ)IT[i]=0;
	vc<pii>Z(n);
	rep(i,n){
		Z[X[i]].fi=i;
		Z[Y[i]].se=i;
	}
	rep(i,n){
		int t = Z[X[i]].se;
		int u = GetMax(0, t);
		R[X[i]] = max(R[X[i]],u);
		Put(t, X[i]);
	}

}
int main(){
	scanf("%d",&n);
	w.resize(n);
	rep(i,n){
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		a--,b--,c--;
		w[i] = {a,b,c};
		Ins(i);
	}
	vi X(n), Y(n), Z(n);
	int c=0;
	rng(i,0,NB){
		rep(j,C[i]){
			Rank[A[i][j]]=c++;
		}
	}
	rep(i,n){
		auto [x,y,z] = w[i];
		X[x] = Rank[i];
		Y[y] = Rank[i];
		Z[z] = Rank[i];
	}
	rep(i,n)R[i]=i;
	Do(X,Y);
	Do(Y,Z);
	Do(Z,X);
	vi S(n+1), P(n+1);
	rep(i,n){
		S[i+1]++;
		S[R[i]+1]--;
	}
	rng(i,1,n){
		S[i]+=S[i-1];
		if(S[i]){
			P[i]=P[i-1];
		}
		else P[i]=i;
	}
	int Q;
	scanf("%d",&Q);
	while(Q--){
		int a, b;
		scanf("%d%d",&a,&b);
		a--,b--;
		a = Rank[a], b = Rank[b];
		puts(P[a]<=P[b]?"YES":"NO");
	}
}
