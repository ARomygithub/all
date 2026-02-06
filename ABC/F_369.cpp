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
using piii = pair<pii,int>;

const int mxn=2e5;
int n,m,k;
int r[mxn],c[mxn];

struct FT {
	vector<pii> s;
	FT(int n) : s(n,{0,-1}) {}
	void update(int pos, pii dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] = max(s[pos],dif);
	}
	pii query(int pos) { // sum of values in [0, pos)
		pii res = {0,-1};
		for (; pos > 0; pos &= pos - 1) res = max(res,s[pos-1]);
		return res;
	}
};

struct FT2 {
	vector<vi> ys; vector<FT> ft;
	FT2(int limx) : ys(limx) {}
	void fakeUpdate(int x, int y) {
		for (; x < sz(ys); x |= x + 1) ys[x].push_back(y);
	}
	void init() {
		for (vi& v : ys) sort(all(v)), ft.emplace_back(sz(v));
	}
	int ind(int x, int y) {
		return (int)(lower_bound(all(ys[x]), y) - ys[x].begin()); }
	void update(int x, int y, pii dif) {
		for (; x < sz(ys); x |= x + 1)
			ft[x].update(ind(x, y), dif);
	}
	pii query(int x, int y) {
		pii sum = {0,-1};
		for (; x; x &= x - 1)
			max_self(sum,ft[x-1].query(ind(x-1, y)));
		return sum;
	}
};

void solve() {
    cin >>n >>m >>k;
    rep(i,0,k) {
        cin >>r[i] >>c[i]; r[i]--;c[i]--;
    }
    vi par(k,-1), vali(k,0);
    FT2 ft2(n);
    set<pii> s;
    rep(i,0,k) {
        s.insert({r[i]+c[i],i});
        ft2.fakeUpdate(r[i], c[i]);
    }
    ft2.init();
    // rep(i,0,k) {
    //     ft2.update(r[i],c[i],{2,3});
    // }
    // cout <<"tes" <<endl;
    for(auto it = s.begin();it!=s.end();) {
        auto it2 = it;
        vi idx;
        while(it2!=s.end() && it2->fi==it->fi) {
            idx.push_back(it2->se);
            it2++;
        }
        for(auto id : idx) {
            auto [val,idp] = ft2.query(r[id]+1,c[id]+1);
            vali[id] = val+1;
            par[id] = idp;
        }
        for(auto id : idx) {
            ft2.update(r[id],c[id], {vali[id],id});
            // cout <<id <<endl;
        }
        it = it2;
    }
    int lsu = -1, mx=0;
    rep(i,0,k) {
        if(vali[i]>mx) {
            lsu = i;
            mx = vali[i];
        }
    }
    vector<pii> v;
    v.push_back({n-1,m-1});
    while(lsu!=-1) {
        v.push_back({r[lsu],c[lsu]});
        lsu = par[lsu];
    }
    v.push_back({0,0});
    cout <<sz(v)-2 <<"\n";
    string anss = "";
    per(i,sz(v)-1,0) {
        rep(j,v[i].fi+1,v[i-1].fi+1) {
            anss +='D';
        }
        rep(j,v[i].se+1,v[i-1].se+1) {
            anss +='R';
        }
    }
    cout <<anss <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}