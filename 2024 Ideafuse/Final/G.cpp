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
typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int t;

const ll inf = LLONG_MAX;
struct Ed { int a, b, w, s() { return a < b ? a : -a; }};
struct Node { ll dist = inf; int prev = -1; };

void bellmanFord(vector<Node>& nodes, vector<Ed>& eds, int s) {
	nodes[s].dist = 0;
	sort(all(eds), [](Ed a, Ed b) { return a.s() < b.s(); });

	int lim = sz(nodes) / 2 + 2; // /3+100 with shuffled vertices
	rep(i,0,lim) for (Ed ed : eds) {
		Node cur = nodes[ed.a], &dest = nodes[ed.b];
		if (abs(cur.dist) == inf) continue;
		ll d = cur.dist + ed.w;
		if (d < dest.dist) {
			dest.prev = ed.a;
			dest.dist = (i < lim-1 ? d : -inf);
		}
	}
	rep(i,0,lim) for (Ed e : eds) {
		if (nodes[e.a].dist == -inf)
			nodes[e.b].dist = -inf;
	}
}

void solve() {
    int n,m;
    cin >>n >>m;
    vector<Node> vnd(n*2);
    vector<Ed> eds;
    rep(i,0,m) {
        int u,v,r,b; cin >>u >>v >>r >>b; u--,v--;
        eds.push_back({u*2,v*2+1, b});
        eds.push_back({u*2+1, v*2, r});
        eds.push_back({v*2,u*2+1,b});
        eds.push_back({v*2+1,u*2,r});
    }
    bellmanFord(vnd,eds, 0);
    ll ans = min(vnd[(n-1)*2].dist,vnd[(n-1)*2+1].dist);
    if(ans==-inf) {
        cout <<"abyss\n";
    } else {
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    rep(i,1,t+1) {
        cout <<"CASE #" <<i <<": ";
        solve();
    }
}