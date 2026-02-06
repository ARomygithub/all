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
typedef pair<int,pii> ipii; 

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, val = hi-1-lo;
    int f=-1,ls=-1;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    ipii query(int L, int R) {
        if (L <= lo && hi <= R) {
            ipii ret = {val,{f,ls}};
            return ret;
        }
        push();
        ipii ret;
        if(R > r->lo && L < l->hi) {
            auto rl = l->query(L,l->hi);
            auto rr = r->query(r->lo,R);
            ret.fi = max(rl.fi,rr.fi);
            ret.se = {rl.se.fi, rr.se.se};
            if(ret.se.fi==-1) {
                ret.se.fi = rr.se.fi;
            }
            if(ret.se.se==-1) {
                ret.se.se = rl.se.se;
            }
            int le = rl.se.se==-1?L:rl.se.se;
            int ri = rr.se.fi==-1?R-1:rr.se.fi;
            max_self(ret.fi, ri-le);
        } else if(R <= l->hi) {
            ret = l->query(L,R);
        } else if(L >= r->lo) {
            ret = r->query(L,R);
        }
        // debug() <<imie(L) <<imie(R);
        // debug() <<imie(lo) <<imie(hi) <<imie(val) <<imie(f) <<imie(ls);
        // debug() <<imie(ret);
        return ret;
    }
    void set(int L, int R) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            f = lo;
            ls = lo;
            val = 0;
        } else {
            push(), l->set(L, R), r->set(L, R);
            val = max(l->val, r->val);
            int rr = r->f==-1?hi-1:r->f;
            int rl = l->ls==-1?lo:l->ls;
            max_self(val, rr-rl);
            f = l->f;
            if(f==-1) {
                f = r->f;
            }
            ls = r->ls;
            if(ls==-1) {
                ls = l->ls;
            }
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
    }
};

const int mxn = 5e4;
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> ans;
        Node st(0, mxn+1);
        rep(i,0,sz(queries)) {
            int qt = queries[i][0];
            int x = queries[i][1];
            if(qt==1) {
                st.set(x,x+1);
            } else {
                int szi = queries[i][2];
                ipii ret = st.query(0,x+1);
                // cout <<ret.fi <<endl;
                ans.push_back(ret.fi>=szi);
            }
        }
        return ans;
    }
};

// [[1,18],[1,19],[2,26,15],[1,5],[1,26],[2,2,23],[1,9],[2,9,20],[2,21,11],[2,17,20]]

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;
    // vector<vector<int>> que = {{1,18},{1,19},{2,26,15},{1,5},{1,26},{2,2,23},{1,9},{2,9,20},{2,21,11},{2,17,20}};
    vector<vector<int>> que = {{1,18},{1,19},{1,5},{1,26},{1,9},{2,21,11},{2,17,20}};
    auto ret =sol.getResults(que);
}