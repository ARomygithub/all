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

const int mxn=2e5;
const ll mod = 998244353;
int n,q;
string s;
using tup = tuple<ll,ll,ll,ll,ll,ll,ll>;

const ll inf = 0;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
    ll a=0, pr=0,suf=0;
    ll apr = 0, as = 0, prs = 0;
    ll val = 0, ma=0,mp=0,ms=0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	tup query(int L, int R) {
		if (R <= lo || hi <= L) return {0,0,0,0,0,0,0};
		if (L <= lo && hi <= R) return {a,pr,suf,apr,as,prs,val};
		push();
        auto [a1,pr1,suf1,apr1,as1,prs1,val1] = l->query(L,R);
        auto [a2,pr2,suf2,apr2,as2,prs2,val2] = r->query(L,R);
		return {(a1+a2)%mod, (pr1+pr2)%mod, (suf1+suf2)%mod, (apr1+apr2)%mod, (as1+as2)%mod, (prs1+prs2)%mod, (val1+val2)%mod};
	}
    void cmb() {
        a = (l->a + r->a)%mod;
        pr = (l->pr + r->pr)%mod;
        suf = (l->suf + r->suf)%mod;
        apr = (l->apr + r->apr)%mod;
        as = (l->as + r->as)%mod;
        prs = (l->prs + r->prs)%mod;
        val = (l->val + r->val)%mod;
    }
    void adda(int L, int R, ll ai) {
        if(R <= lo || hi <= L) return;
        if(L <= lo && hi <= R) {
            ma += ai;
            a += (hi-lo)*ai;
            apr = (apr + ai*pr%mod)%mod;
            as = (a + ai*suf%mod)%mod;
            val = (val + ai*prs%mod)%mod;
        } else {
            push(), l->adda(L,R,ai), r->adda(L, R, ai);
            cmb();
        }
    }
	void addp(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			mp += x;
            pr = (pr + (hi-lo)*x%mod)%mod;
            apr = (apr + x*a%mod)%mod;
            prs = (prs + x*suf%mod)%mod;
            val = (val + x*as%mod)%mod;
		}
		else {
			push(), l->addp(L, R, x), r->addp(L, R, x);
			cmb();
		}
	}
	void adds(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			ms += x;
            suf = (suf + (hi-lo)*x%mod)%mod;
            as = (as + x*a%mod)%mod;
            prs = (prs + x*pr%mod)%mod;
            val = (val + x*apr%mod)%mod;
        }
		else {
			push(), l->adds(L, R, x), r->adds(L, R, x);
			cmb();
		}
	}    
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (ma)
			l->adda(lo,hi,ma), r->adda(lo,hi,ma), ma = 0;
        if(mp) {
            l->addp(lo,hi,mp), r->addp(lo,hi,mp), mp = 0;
        }
        if(ms) {
            l->adds(lo,hi,ms), r->adds(lo,hi,ms), ms = 0;
        }
	}
};

void solve() {
    cin >>n >>q;
    cin >>s;
    Node stu(0,n), sta(0,n);
    rep(i,0,n) {
        if(s[i]=='F') {
            stu.addp(i,n,1);
            sta.addp(i,n,1);
            stu.adds(0,i+1,1);
            sta.adds(0,i+1,1);
        } else if(s[i]=='A') {
            sta.adda(i,i+1,1);
        } else if(s[i]=='U') {
            stu.adda(i,i+1,1);
        }
    }
    rep(ii,0,q) {
        int qt; cin >>qt;
        if(qt==1) {
            int i; char c; cin >>i >>c;
            i--;
            if(s[i]=='F') {
                stu.addp(i,n,-1);
                sta.addp(i,n,-1);
                stu.adds(0,i+1,-1);
                sta.adds(0,i+1,-1);                
            } else if(s[i]=='A') {
                sta.adda(i,i+1,-1);
            } else if(s[i]=='U') {
                stu.adda(i,i+1,-1);
            }
            s[i] = c;
            if(s[i]=='F') {
                stu.addp(i,n,1);
                sta.addp(i,n,1);
                stu.adds(0,i+1,1);
                sta.adds(0,i+1,1);
            } else if(s[i]=='A') {
                sta.adda(i,i+1,1);
            } else if(s[i]=='U') {
                stu.adda(i,i+1,1);
            }
        } else if(qt==2) {
            int l,r; cin >>l >>r; l--;
            auto stuq = stu.query(l,r);
            // debug() <<imie(stuq);
            auto [a,pr,s,apr,as,prs,val] = stuq;
            debug() <<imie(val) imie(a) imie(as) imie(apr);
            ll pl = 0;
            if(l>0) {
                pl = get<1>(stu.query(l-1,l));
            }
            ll sr = get<2>(stu.query(r,min(r+1,n)));
            debug() <<imie(pl) imie(sr);
            ll ans = (val + a*pl%mod*sr%mod + mod - as*pl%mod + mod - apr*sr%mod )%mod;
            cout <<ans <<"\n";
        } else {
            int l,r; cin >>l >>r; l--;
            auto [a,pr,s,apr,as,prs,val] = sta.query(l,r);
            ll pl = 0;
            if(l>0) {
                pl = get<1>(sta.query(l-1,l));
            }
            ll sr = get<2>(sta.query(r,min(r+1,n)));
            ll ans = (val + a*pl%mod*sr%mod + mod - as*pl%mod + mod - apr*sr%mod )%mod;
            cout <<ans <<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}