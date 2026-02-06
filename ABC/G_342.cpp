#include <bits/stdc++.h>
using namespace std;

// #define fi first
// #define se second
// #define sim template < class c
// #define ris return * this
// #define dor > debug & operator <<
// #define eni(x) sim > typename \
//     enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
// sim > struct rge {c b, e;};
// sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
// sim > auto dud(c* x) -> decltype(cerr << *x, 0);
// sim > char dud(...);
// struct debug{
//     ~debug() {cerr << endl;}
//     eni(!=) cerr << boolalpha << i; ris; }
//     eni(==) ris << range(begin(i), end(i)); }
//     sim, class b dor(pair <b, c> d) {
//         ris <<"(" <<d.fi <<", " <<d.se <<")";
//     }
//     sim dor(rge<c> d) {
//         *this << "[";
//         for(auto it=d.b;it!=d.e;++it) {
//             *this <<", " + 2*(it==d.b) <<*it;
//         }
//         ris << "]";
//     }
// };
// #define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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
typedef pair<pii,int> piii;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,q;

struct Tree {
	typedef pair<priority_queue<int>,priority_queue<int>> T;
	// static constexpr T unit = T();
	// T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0) : s(2*n), n(n) {}
	// void update(int pos, T val) {
	// 	for (s[pos += n] = val; pos /= 2;)
	// 		s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	// }
    void range_update(int b, int e, const auto& f) {
        for(b +=n, e+=n; b<e; b/=2,e/=2) {
            if(b%2) f(s[b++]);
            if(e%2) f(s[--e]);
        }
    }
    void range_add(int b, int e, int x) {
        range_update(b, e, [&](T& pq) -> void {
            pq.fi.push(x);
        });
    }
    void range_erase(int b, int e, int x) {
        range_update(b, e, [&](T& pq) -> void {
            pq.se.push(x);
        });
    }
    // void dbg() {
    //     rep(i,0,n*2) {
    //         debug() <<imie(i);
    //         dbg_pq(s[i]);
    //     }
    // }
    // void dbg_pq(T& pq) {
    //     vector<int> temp;
    //     debug() <<"start\n";
    //     while(sz(pq.fi)) {
    //         int fiTop = pq.fi.top();
    //         debug() <<imie(pq.fi.top()); pq.fi.pop();
    //         temp.push_back(fiTop);
    //     }
    //     for(int v: temp) {
    //         pq.fi.push(v);
    //     }
    //     temp.clear();
    //     while(sz(pq.se)) {
    //         int seTop = pq.se.top();
    //         debug() <<imie(seTop); pq.se.pop();
    //         temp.push_back(seTop);
    //     }
    //     for(int v: temp) {
    //         pq.se.push(v);
    //     }
    //     debug() <<"end\n";
    // }
    int top_or_zero(T& pq) {
        while(sz(pq.se) && pq.fi.top()==pq.se.top()) {
            pq.fi.pop();
            pq.se.pop();
        }
        return sz(pq.fi)? pq.fi.top() : 0;
    }
    int point_query(int pos) {
        int r = 0;
        for(pos+=n; pos; pos/=2) {
            // cout <<pos <<" What\n" <<flush;
            max_self(r, top_or_zero(s[pos]));
        }
        return r;
    }
	// T query(int b, int e) { // query [b, e)
	// 	T ra = unit, rb = unit;
	// 	for (b += n, e += n; b < e; b /= 2, e /= 2) {
	// 		if (b % 2) ra = f(ra, s[b++]);
	// 		if (e % 2) rb = f(s[--e], rb);
	// 	}
	// 	return f(ra, rb);
	// }
};

void solve() {
    cin >>n;
    Tree st(n);
    rep(i,0,n) {
        int ai; cin >>ai;
        st.range_add(i,i+1, ai);
    }
    cin >>q;
    map<int,piii> mp;
    rep(i,1,q+1) {
        int qt; cin >>qt;
        if(qt==1) {
            int l,r,x; cin >>l >>r >>x; l--;
            st.range_add(l, r, x);
            mp[i] = {{l,r},x};
        } else if(qt==2) {
            int ii; cin >>ii;
            auto [lr, x] = mp[ii];
            auto [l,r] = lr;
            st.range_erase(l, r, x);
        } else {
            int pos; cin >>pos; pos--;
            cout <<st.point_query(pos) <<"\n";
        }
    }
    // st.dbg();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}