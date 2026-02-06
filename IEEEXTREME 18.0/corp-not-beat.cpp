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

const ll setc = 1e18;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
	ll mset = setc, madd = 0, val = 0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return (l->query(L, R) + r->query(L, R));
	}
	void set(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			val = x*(hi-lo);
			mset = x;
			madd = 0;
		}
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = (l->val + r->val);
		}
	}
	void add(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != setc) {
                mset += x;
            } else {
                madd += x;
            } 
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
    int n,m;
    cin >>n >>m;
	Node st(0,n),hp(0,n);
    vi v;
    rep(i,0,n) {
        int ci; cin >>ci;
        v.push_back(ci);
    }
	rep(i,0,n) {
		st.set(i,i+1,v[i]);
	}
    while(m--) {
        int k1,k2,k3; cin >>k1 >>k2 >>k3;
        if(k1==0) {
            int k4; cin >>k4;
            rep(i,k2-1,k3) {
                ll qry = st.query(i,i+1);
                if(qry<k4) {
                    hp.add(i,i+1,1);
                } else if(qry>k4) {
                    hp.add(i,i+1,-1);
                }
            }
			st.set(k2-1,k3,k4);
        } else if(k1==1) {
            int k4; cin >>k4;
            if(k4!=0) {
				st.add(k2-1,k3,k4);
                if(k4>0) {
                    hp.add(k2-1,k3,1);
                } else {
                    hp.add(k2-1,k3,-1);
                }
			}
        } else if(k1==2) {
            ll p = st.query(k2-1,k3), q = k3-k2+1;
            ll d = __gcd(p,q);
            p /= d;
            q /= d;
            if(q<0) {
                q *= -1;
                p *= -1;
            }
			// if(q==1) {
			// 	cout <<p <<"\n";
			// } else {
            	cout <<p <<"/" <<q <<"\n";
			// }
        } else {
            ll p = hp.query(k2-1,k3), q = k3-k2+1;
            ll d = __gcd(p,q);
            p /= d;
            q /= d;
            if(q<0) {
                p *= -1;
                q *= -1;
            }
			// if(q==1) {
			// 	cout <<p <<"\n";
			// } else {
            	cout <<p <<"/" <<q <<"\n";
			// }
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