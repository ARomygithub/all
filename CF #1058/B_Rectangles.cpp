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

const int mxn=1e5,mxa=250000;
int n,m,t;

const int inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, val = inf;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    int query(int L, int R) {
        if (R <= lo || hi <= L) return inf;
        if (L <= lo && hi <= R) return val;
        push();
        return min(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = min(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != -inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = -inf;
    }
};

using ipii = pair<int,pii>;

void solve() {
    cin >>n >>m;
    vector a(n, vector<bool>(m));
    rep(i,0,n) {
        string s; cin >>s;
        rep(j,0,m) {
            a[i][j] = s[j]=='1';
        }
    }
    bool tuker = 0;
    if(n < m) {
        tuker = 1;
        vector a_new(m, vector<bool>(n));
        rep(i,0,n) {
            rep(j,0,m) {
                a_new[j][i] = a[i][j];
            }
        }
        a.swap(a_new);
        swap(n,m);
    }
    vector rec(mxa+1, vector<ipii>());
    vector ls(m, vi(m,-1));
    // debug() <<imie(a);
    int cta = 0;
    rep(i,0,n) {
        rep(j,0,m) {
            rep(k,j+1,m) {
                if(a[i][k] && a[i][j]) {
                    if(ls[j][k]!=-1) {
                        int are = (k-j+1)*(i-ls[j][k]+1);
                        rec[are].push_back({i, {j,k}});
                        cta++;
                    }
                    ls[j][k] = i;
                }
            }
        }
    }
    // cout <<ct <<endl;
    vector<Node> st;
    rep(i,0,m) {
        st.push_back(Node(0,n));
    }
    per(ct,mxa,0) {
        for(auto& [d, jk]: rec[ct]) {
            if(cta>=2e5) {
                cta--;
                continue;
            }
            auto& [j,k] = jk;
            int u = d - (ct/(k-j+1)) + 1;
            rep(jj,j,k+1) {
                st[jj].set(u,d+1, ct);
            }
        }
    }
    // cout <<cta <<endl;
    vector ans(n, vi(m,0));
    rep(i,0,n) {
        rep(j,0,m) {
            int qry = st[j].query(i,i+1);
            if(qry!=inf) {
                ans[i][j] = qry;
            }
        }
    }
    if(tuker) {
        rep(j,0,m) {
            rep(i,0,n) {
                cout <<ans[i][j] <<" \n"[i==n-1];
            }
        }
    } else {
        rep(i,0,n) {
            rep(j,0,m) {
                cout <<ans[i][j] <<" \n"[j==m-1];
            }
        }
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