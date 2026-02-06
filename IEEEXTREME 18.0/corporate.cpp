// https://github.com/jiry17/STBExercises/blob/master/t2/std.cpp

#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
    ~debug() {cerr << endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair <b, c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it=d.b;it!=d.e;++it) {
            *this <<", " + 2*(it==d.b) <<*it;
        }
        ris << "]";
    }
};
#define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()

const int N=210000,inf=2e9;
int mi[N<<2],ma[N<<2],tmi[N<<2],tma[N<<2],semi[N<<2],sema[N<<2],n,m,A[N<<2],B[N<<2],C[N<<2],szi[N<<2];
int tA[N<<2],tB[N<<2],tC[N<<2],pd[N<<2];
ll num2[N<<2],mset[N<<2],madd[N<<2];
long long num[N<<2];
void change(int k1){
	int l=k1*2,r=k1*2+1;
	if (mi[l]==mi[r]){
		mi[k1]=mi[l]; semi[k1]=min(semi[l],semi[r]); tmi[k1]=tmi[l]+tmi[r];
	} else if (mi[l]<mi[r]){
		mi[k1]=mi[l]; semi[k1]=min(semi[l],mi[r]); tmi[k1]=tmi[l];
	} else {
		mi[k1]=mi[r]; semi[k1]=min(mi[l],semi[r]); tmi[k1]=tmi[r];
	}
	if (ma[l]==ma[r]){
		ma[k1]=ma[l]; sema[k1]=max(sema[l],sema[r]); tma[k1]=tma[l]+tma[r];
	} else if (ma[l]>ma[r]){
		ma[k1]=ma[l]; sema[k1]=max(sema[l],ma[r]); tma[k1]=tma[l];
	} else {
		ma[k1]=ma[r]; sema[k1]=max(ma[l],sema[r]); tma[k1]=tma[r];
	}
	num[k1]=num[l]+num[r];
    num2[k1]=num2[l]+num2[r];
	if (mi[k1]!=ma[k1]) pd[k1]=0; else pd[k1]=1;
}
void addA(int k1,int k2,int k3){
	mi[k1]+=k2; num[k1]+=1ll*tmi[k1]*k3; A[k1]+=k2; tA[k1]+=k3;
	if (tmi[k1]+tma[k1]==szi[k1]) sema[k1]+=k2;
}
void addB(int k1,int k2,int k3){
	if (pd[k1]==0) num[k1]+=1ll*(szi[k1]-tmi[k1]-tma[k1])*k3; B[k1]+=k2; tB[k1]+=k3;
	if (tmi[k1]+tma[k1]<szi[k1]){
		semi[k1]+=k2; sema[k1]+=k2;
	}
}
void addC(int k1,int k2,int k3){
	ma[k1]+=k2; if (pd[k1]==0) num[k1]+=1ll*tma[k1]*k3; C[k1]+=k2; tC[k1]+=k3;
	if (tmi[k1]+tma[k1]==szi[k1]) semi[k1]+=k2;
}
void doSet(int k1, ll x) {
    num2[k1] = x*szi[k1];
    mset[k1] = x; madd[k1]=0;
}
void doAdd(int k1, ll x) {
    debug() <<imie(num2[k1]) imie(szi[k1]) imie(x);
    num2[k1] += x*szi[k1];
    debug() <<imie(num2[k1]);
    if(mset[k1]!=inf) {
        mset[k1] += x;
    } else {
        madd[k1] += x;
    }
}
void pushdown(int k1){
	int l=k1*2,L=min(mi[l],mi[l+1]),R=max(ma[l],ma[l+1]);
	if (mi[l]==L) addA(l,A[k1],tA[k1]); else if (mi[l]==R) addA(l,C[k1],tC[k1]); else addA(l,B[k1],tB[k1]);
	if (ma[l]==L) addC(l,A[k1],tA[k1]); else if (ma[l]==R) addC(l,C[k1],tC[k1]); else addC(l,B[k1],tB[k1]);
	addB(l,B[k1],tB[k1]);

    if(mset[k1]!=inf) {
	    doSet(l, mset[k1]);
    } else if(madd[k1]>0) {
        doAdd(l, madd[k1]);
    }
    l++;
	if (mi[l]==L) addA(l,A[k1],tA[k1]); else if (mi[l]==R) addA(l,C[k1],tC[k1]); else addA(l,B[k1],tB[k1]);
	if (ma[l]==L) addC(l,A[k1],tA[k1]); else if (ma[l]==R) addC(l,C[k1],tC[k1]); else addC(l,B[k1],tB[k1]);
	addB(l,B[k1],tB[k1]);
	A[k1]=0; tA[k1]=0; B[k1]=0; tB[k1]=0; C[k1]=0; tC[k1]=0;
    if(mset[k1]!=inf) {
	    doSet(l, mset[k1]);
    } else if(madd[k1]>0) {
        doAdd(l, madd[k1]);
    }
    mset[k1] = inf; madd[k1] = 0;
}
void buildtree(int k1,int k2,int k3){
	szi[k1]=k3-k2+1;
    mset[k1] = inf, madd[k1]=0;    
	if (k2==k3){
		int k4; cin >>k4; mi[k1]=k4; ma[k1]=k4; semi[k1]=inf; sema[k1]=-inf; tmi[k1]=1; tma[k1]=1;
		pd[k1]=1;
        num2[k1] = k4;
		return;
	}
	int mid=(k2+k3)>>1;
	buildtree(k1*2,k2,mid); buildtree(k1*2+1,mid+1,k3);
	change(k1);
}
long long findans(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return 0;
	if (k2>=k4&&k3<=k5) return num[k1];
	int mid=(k2+k3)>>1; pushdown(k1);
	return findans(k1*2,k2,mid,k4,k5)+findans(k1*2+1,mid+1,k3,k4,k5);
}
long long findans2(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return 0;
	if (k2>=k4&&k3<=k5) return num2[k1];
	int mid=(k2+k3)>>1; pushdown(k1);
	return findans2(k1*2,k2,mid,k4,k5)+findans2(k1*2+1,mid+1,k3,k4,k5);
}
void down1(int k1,int k2,int k3,int k4){
	if (mi[k1]>=k4) return;
	if (semi[k1]>k4){
		int now=k4-mi[k1]; addA(k1,now,1);
		if (pd[k1]==1) addB(k1,now,1),addC(k1,now,1);
		return;
	}
	int mid=(k2+k3)>>1; pushdown(k1);
	down1(k1*2,k2,mid,k4);
	down1(k1*2+1,mid+1,k3,k4);
	change(k1);
}
void down2(int k1,int k2,int k3,int k4){
	//cout<<"fa "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<ma[k1]<<" "<<sema[k1]<<endl;
	if (ma[k1]<=k4) return;
	if (sema[k1]<k4){
		int now=k4-ma[k1]; addC(k1,now,-1);
		if (pd[k1]==1) addB(k1,now,-1),addA(k1,now,-1);
		return;
	}
	int mid=(k2+k3)>>1; pushdown(k1);
	down2(k1*2,k2,mid,k4);
	down2(k1*2+1,mid+1,k3,k4);
	change(k1);
}
void getmax(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
        doSet(k1, k6);
		down1(k1,k2,k3,k6); return;
	}
	int mid=(k2+k3)>>1; pushdown(k1);
	getmax(k1*2,k2,mid,k4,k5,k6);
	getmax(k1*2+1,mid+1,k3,k4,k5,k6);
	change(k1);
}
void getmin(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		down2(k1,k2,k3,k6); return;
	}
//	cout<<"fa "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<k5<<" "<<k6<<" "<<ma[k1]<<" "<<sema[k1]<<endl;
	int mid=(k2+k3)>>1; pushdown(k1);
	getmin(k1*2,k2,mid,k4,k5,k6);
	getmin(k1*2+1,mid+1,k3,k4,k5,k6);
	change(k1);
}
int sgn(int x) {
    return (x>0)-(x<0);
}
void addall(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
        debug() <<imie(k2) imie(k3) imie(k1) imie(k6);
        doAdd(k1, k6);
		addA(k1,k6,sgn(k6)); addB(k1,k6,sgn(k6)); addC(k1,k6,sgn(k6)); return;
	}
	int mid=(k2+k3)>>1; pushdown(k1);
	addall(k1*2,k2,mid,k4,k5,k6);
	addall(k1*2+1,mid+1,k3,k4,k5,k6);
	change(k1);
    debug() <<imie(k1) imie(k2) imie(k3) imie(num2[k1]);
}

void solve() {
    cin >>n >>m;
    buildtree(1,1,n);
    cout <<findans2(1,1,n,1,n) <<endl;
    while(m--) {
        int k1,k2,k3; cin >>k1 >>k2 >>k3;
        if(k1==0) {
            int k4; cin >>k4;
            getmax(1,1,n,k2,k3,k4);
            getmin(1,1,n,k2,k3,k4);
        } else if(k1==1) {
            int k4; cin >>k4;
            if(k4!=0) {
                addall(1,1,n,k2,k3,k4); // ini add 1, ntar add sgn(k4)
                cout <<findans2(1,1,n,1,n) <<endl;
            }
        } else if(k1==2) {
            // lazy segtree aja? atau implemen di seg tree beats
            ll p = findans2(1,1,n,k2,k3), q = k3-k2+1;
            ll d = __gcd(p,q);
            p /= d;
            q /= d;
            cout <<p <<"/" <<q <<"\n";
        } else {
            ll p = findans(1,1,n,k2,k3), q = k3-k2+1;
            ll d = __gcd(p,q);
            p /= d;
            q /= d;
            cout <<p <<"/" <<q <<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
	return 0;
}