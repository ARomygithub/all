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

const int mxn=1e6;
ll n,m,k,a,b;

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a/b * x, d;
}

ll getMd(ll bi, ll md, ll ni) {
    // md >0
    ll d = __gcd(bi,ni);
    bi /= d;
    ni /= d;
    // md /= d; // prekondisi d | md
    ll x,y;
    euclid(bi,ni,x,y);
    x = ((x%ni)+ni)%ni;
    x = x*(md/d)%ni;
    return x;
}

ll crt(ll a, ll m, ll b, ll n) {
    // debug() <<imie(a) imie(m) imie(b) imie(n);
    if (n > m) swap(a, b), swap(m, n);
    ll x, y, g = euclid(m, n, x, y);
    if((a - b) % g != 0) {
        return -1;
    }
    assert((a - b) % g == 0); // else no solution
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m*n/g : x;
}

ll getVal(ll xi, ll yi) {
    ll db = __gcd(b,n), da = __gcd(a,m);
    if((xi%__gcd(b,n*2))!=0 || (yi%__gcd(a,m*2))!=0) {
        return -1;
    }
    vector<ll> x(2),y(2);
    x[0] = getMd(b, xi, n*2);
    x[1] = getMd(b, n*2-xi, n*2);
    y[0] = getMd(a, yi, m*2);
    y[1] = getMd(a, m*2-yi, m*2);
    ll ta = 1e18;
    ll ni = n*2/__gcd(n*2,b);
    ll mi = m*2/__gcd(m*2,a);
    rep(i,0,2) {
        rep(j,0,2) {
            ll temp = crt(x[i], ni, y[j], mi);
            if(temp<0) continue;
            min_self(ta, temp);
        }
    }
    ll lb = b*n/db, la = a*m/da;
    ll dlab = __gcd(la/a, lb/b);
    ll tend = (la/a)*(lb/b)/dlab;
    if(ta<tend) {
        ll pntul = ta*b/n + ta*a/m;
        return pntul;
    } else {
        return -1;
    }
}

const ll inf = 0, setc=1e18;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
    ll mset = setc, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return (l->query(L, R) + r->query(L, R));
	}
	void set(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
            mset = x, madd = 0;
            val = x*(hi-lo);
        } else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = (l->val + r->val);
		}
	}
	void add(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != setc) mset += x;
			else madd += x;
			val += x*(hi-lo);
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = (l->val + r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != setc)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = setc;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

void solve() {
    cin >>n >>m >>k >> a >>b; 
    vi x(k), y(k);
    rep(i,0,k) {
        cin >>x[i] >>y[i];
    }
    vector<ll> val(k);
    vector<pll> v;
    rep(i,0,k) {
        val[i] = getVal(x[i],y[i]);
        if(val[i]==-1) {
            val[i] = 1e18;
        }
        v.push_back({val[i],i});
    }
    sort(all(v), greater<pll>());
    set<int> s;
    rep(i,-1,k+1) {
        s.insert(i);
    }
    Node st(0,k);
    rep(i,0,sz(v)) {
        auto [vali, id] = v[i];
        s.erase(id);
        auto ir = s.lower_bound(id); 
        auto il = ir; il--;
        if(vali==1e18) {
            vali = -1;
        }
        st.add(id,*ir, vali*(id-(*il))); 
    }
    rep(i,0,k) {
        cout <<st.query(i,i+1) <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}