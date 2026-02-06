#include <bits/stdc++.h>
using namespace std;

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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const ll mxn=1e9;
int t;
long double a;

typedef long double d; // for N ~ 1e7; long double for N ~ 1e9
pair<ll, ll> approximate(d x, ll N) {
	ll LP = 0, LQ = 1, P = 1, Q = 0, inf = LLONG_MAX; d y = x;
	for (;;) {
		ll lim = min(P ? (N-LP) / P : inf, Q ? (N-LQ) / Q : inf),
		   a = (ll)floor(y), b = min(a, lim),
		   NP = b*P + LP, NQ = b*Q + LQ;
		if (a > b) {
			// If b > a/2, we have a semi-convergent that gives us a
			// better approximation; if b = a/2, we *may* have one.
			// Return {P, Q} here for a more canonical approximation.
			return (abs(x - (d)NP / (d)NQ) < abs(x - (d)P / (d)Q)) ?
				make_pair(NP, NQ) : make_pair(P, Q);
		}
		if (abs(y = 1/(y - (d)a)) > 3*N) {
			return {NP, NQ};
		}
		LP = P; P = NP;
		LQ = Q; Q = NQ;
	}
}
const ll mod=1e9+7;
ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

void solve() {
    cin >>a;
    if(a<(long double)0.0) {
        a +=(long double)360.0;
    }
    auto pq = approximate(a,mxn);
    if(pq.se==1) {
        if((pq.fi%180)==0) {
            cout <<"1\n";
            return;
        }
    }
    ll atas = 90;
    ll dd = __gcd(atas,pq.fi);
    atas /=dd;
    pq.fi /=dd;
    if(pq.fi%2) {
        ll ans = pq.se*atas;
        cout <<ans <<"\n";
        return;
    } else {
        atas = atas*pq.se;
        ll phic = 1;
        ll u = pq.fi;
        for(int i=2;i*i<=u;i++) {
            if((u%i)==0) {
                ll ui=1;
                while((u%i)==0) {
                    u/=i;
                    ui *=i;
                }
                ui /=i;
                ui *=(i-1);
                phic *=ui;
            }
        }
        if(u>1) {
            phic *=u-1;
        }
        // cout <<phic <<"\n";
        ll ai = fastexpo(atas,phic-1,pq.fi);
        ll k1 = ((ai+1)*-1)%pq.fi;
        k1 = (k1+pq.fi)%pq.fi;
        k1 /=2;
        ll k2 = (ai-1+pq.fi)%pq.fi;
        k2 /=2;
        if(k1<=k2) {
            ll ans = atas*2*k1+atas+1;
            ans /=pq.fi;
            cout <<ans <<"\n";
        } else {
            ll ans = atas*2*k1+atas-1;
            // cout <<ans <<"\n";
            // ans /=pq.fi;
            // cout <<pq.fi <<"\n";
            cout <<ans <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}