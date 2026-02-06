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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const ll inf = 2e18;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
    ll mset = inf, val = -inf, dp=-inf,pref=-inf,prefmn=-inf;
    ll mpref = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vector<ll> v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		ll ret = max(l->query(L, R), r->query(L, R));
        // debug() <<imie(lo) <<imie(hi) <<imie(ret);
        // debug() <<imie(l->query(L,R)) <<imie(r->query(L,R));
        return ret;
    }
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
    void upd(int L, int R, ll prefi) {
        // cout <<"upd " <<L <<" " <<R <<endl;
        // cout <<"lo hi " <<lo <<" " <<hi <<endl;
        if(R <=lo || hi<=L) return;
        if(L<=lo && hi <=R) {
            if(prefi>prefmn) {
                // debug() <<imie(prefi) <<imie(prefmn);
                if(prefi>=pref) {
                    pref = prefi;
                    prefmn = prefi;
                    val = pref+dp;
                    mpref = prefi;
                    // debug() <<imie(lo) <<imie(hi) <<imie(pref) <<imie(val);
                } else {
                    push(), l->upd(L,R,prefi), r->upd(L,R,prefi);
                    pref = max(l->pref,r->pref);
                    prefmn = min(l->prefmn, r->prefmn);
                    val = max(l->val,r->val);
                    // debug() <<imie(lo) <<imie(hi) <<imie(pref) <<imie(val);
                }
            } else {
                return;
            }
        }
        else {
            push(), l->upd(L,R,prefi), r->upd(L,R,prefi);
            pref = max(l->pref,r->pref);
            prefmn = min(l->prefmn, r->prefmn);
            val = max(l->val,r->val);            
            // debug() <<imie(lo) <<imie(hi) <<imie(pref) <<imie(val);
        }
    }
    void set_dp(int L, int R, ll dpi) {
        // cout <<"set_dp " <<L <<" " <<R <<endl;
        if(R<=lo || hi<=L) return;
        if(L<=lo && hi<=R) {
            dp = dpi;
            val = pref + dp;
            // debug() <<imie(lo) <<imie(hi) <<imie(dp) <<imie(val);
        } else {
            push(), l->set_dp(L,R,dpi), r->set_dp(L,R,dpi);
            pref = max(l->pref,r->pref);
            prefmn = min(l->prefmn, r->prefmn);            
            dp = max(l->dp,r->dp);
            val = max(l->val,r->val);
            // debug() <<imie(lo) <<imie(hi) <<imie(dp) <<imie(val);
        }
    }
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
        else if(mpref!= -inf) {
            l->upd(lo,hi,mpref), r->upd(lo,hi,mpref), mpref = -inf;
        }
	}
    // void dbg() {
    //     debug() <<imie(lo) <<imie(hi);
    //     debug() <<imie(pref) <<imie(val) <<imie(dp) <<imie(mpref);
    //     if(l) l->dbg();
    //     if(r) r->dbg();
    // }
};

class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        vector<ll> pref(sz(nums));
        rep(i,0,sz(nums)) {
            pref[i] = (i-1>=0?pref[i-1]:0ll) + nums[i];
        }
        vector dp(sz(nums), vector<ll>(k+1,-2e18));
        ll ans = -2e18;
        vector<Node> vsgt;
        // vector<ll> pref0(sz(nums));
        // rep(i,0,sz(nums)) {
        //     pref0[i] = pref[i]*k*(-1);
        // }
        // Node cur0(pref0, 0, sz(nums));
        // vsgt.push_back(cur0);
        rep(i,0,k) {
            Node cur(0,sz(nums));
            vsgt.push_back(cur);
        }

        rep(i,0,sz(nums)) {
            // cout <<i <<endl;
            ll mn0 = vsgt[0].query(0,i);
            max_self(mn0, 0ll);
            dp[i][1] = pref[i]*(k+1-1)+mn0;
            // debug() <<imie(dp[i][1]) <<imie(pref[i]) <<imie(mn0);
            rep(j,2,min(k+1,i+2)) {
                // debug() <<imie(i) <<imie(j);
                // if(i==2 && j==3) {
                //     vsgt[j-1].dbg();
                // }
                if(j%2) {
                    ll mnj = vsgt[j-1].query(0,i);
                    dp[i][j] = pref[i]*(k+1-j)+mnj;
                    // debug() <<imie(dp[i][j]) <<imie(pref[i]) <<imie(mnj);
                } else {
                    ll mxj = vsgt[j-1].query(0,i);
                    dp[i][j] = pref[i]*(k+1-j)*(-1)+mxj;
                    // debug() <<imie(dp[i][j]) <<imie(pref[i]) <<imie(mxj);
                }
            }
            // upd vsgt
            rep(j,0,min(k,i+2)) {
                ll temp = pref[i]*(k+1-(j+1))*(-1)*(((j+1)%2)==1?1:-1);
                if(j>0) {
                    vsgt[j].set_dp(i,i+1, dp[i][j]);
                } else {
                    vsgt[j].set_dp(i,i+1, 0ll);
                }
                // if(j==2) {
                //     debug() <<imie(temp);
                // }
                vsgt[j].upd(0,i+1,temp);
            }
        }
        rep(i,0,sz(nums)) {
            max_self(ans, dp[i][k]);
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;
    vector<int> nums = {1,2,3,-1,2};
    cout <<sol.maximumStrength(nums, 3) <<"\n";
}