#include <bits/stdc++.h>
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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=800;
int n,m,t;
ll k;
int b[mxn][mxn];

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
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
	void update(int x, int y, ll dif) {
		for (; x < sz(ys); x |= x + 1)
			ft[x].update(ind(x, y), dif);
	}
	ll query(int x, int y) {
		ll sum = 0;
		for (; x; x &= x - 1)
			sum += ft[x-1].query(ind(x-1, y));
		return sum;
	}
    ll qry2(int x1, int y1, int x2, int y2) {
        ll ret = query(x2+1,y2+1)-query(x2+1,y1)-query(x1,y2+1)+query(x1,y1);
        // debug() <<imie(x1)  imie(y1) imie(x2) imie(y2);
        // debug() <<imie(ret);
        return ret;
    }
};

using ipii = pair<int,pii>;

void solve() {
    cin >>n >>m >>k;
    rep(i,0,n) {
        rep(j,0,m) {
            cin >>b[i][j];
        }
    }
    vector<ipii> v;
    rep(i,0,n) {
        rep(j,0,m) {
            v.push_back({b[i][j],{i+1,j+1}});
        }
    }
    sort(all(v));
    int ans = -1;
    int l = 0, r = max(n,m);
    while(l<=r) {
        int mid = (l+r)/2;
        ll ct = 0;
        FT2 ft2(n+2);
        rep(i,1,n+1) {
            rep(j,1,m+1) {
                ft2.fakeUpdate(i,j);
            }
        }
        ft2.init();
        // cout <<"tes" <<endl;
        for(int i=0;i<sz(v);) {
            int j = i;
            while(j<sz(v) && v[j].fi==v[i].fi) {
                j++;
            }
            // debug() <<imie(v[i].fi);
            rep(p,i,j) {
                auto [x,y] = v[p].se;
                // debug() <<imie(x) imie(y);
                ft2.update(x,y,1);
            }
            rep(p,i,j) {
                auto [x,y] = v[p].se;
                int le = max(1, y-mid);
                int ri = min(m, y+mid);
                int up = max(1, x-mid);
                int dw = min(n, x+mid);
                ct += (1ll*(ri-le+1)*(dw-up+1) - ft2.qry2(up,le, dw, ri));
            }
            rep(p,i,j) {
                auto [x,y] = v[p].se;
                ft2.update(x,y,-1);
            }            
            i = j;
        }
        if(ct>=k) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout <<ans <<"\n";
}

void main_() {
    // implement your solution here
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    for(int i=1;i<=t;i++) {
        cout <<"Case #" <<i <<": ";
        solve();
    }    
}

static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%rsp, (%0)\n"
        "mov %0, %%rsp\n"
        :
        : "r"(send));
    func();
    asm volatile("mov (%0), %%rsp\n" : : "r"(send));
    free(stack);
}

int main() {
    run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
    return 0;
}