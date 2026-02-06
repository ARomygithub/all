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

const int mxn=500;
int n,d,t;

const ll inf = 1LL << 62;
void floydWarshall(vector<vector<ll>>& m) {
	int n = sz(m);
	rep(i,0,n) m[i][i] = min(m[i][i], 0LL);
	rep(k,0,n) rep(i,0,n) rep(j,0,n)
		if (m[i][k] != inf && m[k][j] != inf) {
			auto newDist = max(m[i][k] + m[k][j], -inf);
			m[i][j] = min(m[i][j], newDist);
		}
	rep(k,0,n) if (m[k][k] < 0) rep(i,0,n) rep(j,0,n)
		if (m[i][k] != inf && m[k][j] != inf) m[i][j] = -inf;
}

void solve() {
    cin >>n >>d;
    map<string,int> mp;
    int m=0;
    vector<vector<ll>> dist(n,vector<ll>(n));
    vector<vector<ll>> awal(n,vector<ll>(n));
    rep(i,0,n) {
        dist[i][i] = 0;
        awal[i][i] = 0;
        rep(j,0,n) {
            if(i==j) continue;
            string si,si2; cin >>si >>si2;
            if(!mp.count(si)) {
                mp[si] = m++;
            }
            if(!mp.count(si2)) {
                mp[si2] = m++;
            }
            int ti; cin >>ti;
            dist[mp[si]][mp[si2]] = ti;
            awal[mp[si]][mp[si2]] = ti;
        }
    }
    // if(d==2) {
    //     vector<vector<ll>> dist_new(n,vector<ll>(n,inf));
    //     rep(i,0,n) {
    //         rep(j,0,n) {
    //             rep(k,0,n) {
    //                 min_self(dist_new[i][j], dist_new[i][k]+dist_new[k][j]);
    //             }
    //         }
    //     }
    // }
    floydWarshall(dist);
    ll mx=-1,mx2=-2;
    if(d == 1) {
        rep(i,0,n) {
            rep(j,0,n) {
                if(i==j) continue;
                max_self(mx,dist[i][j]);
            }
        }
        cout <<mx-1 <<"\n";
    } else {
        ll ans=0;
        rep(i,0,n) {
            ll mxi=-1,mxi2=-2;
            rep(j,0,n) {
                if(i==j) continue;
                if(dist[i][j]>=mxi) {
                    mxi2 = mxi;
                    mxi = dist[i][j];
                } else {
                    if(dist[i][j]>=mxi2) {
                        mxi2 = dist[i][j];
                    }
                }
            }
            max_self(ans,mxi+mxi2-2);
        }
        cout <<ans <<"\n";
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