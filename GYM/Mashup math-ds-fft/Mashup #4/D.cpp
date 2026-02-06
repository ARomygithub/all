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

const int mxn=5e5;
int n;
int a[mxn+1];

set<pii>::iterator addInterval(set<pii>& is, int L, int R) {
    if (L == R) return is.end();
    auto it = is.lower_bound({L, R}), before = it;
    while (it != is.end() && it->first <= R) {
        R = max(R, it->second);
        before = it = is.erase(it);
    }
    if (it != is.begin() && (--it)->second >= L) {
        L = min(L, it->first);
        R = max(R, it->second);
        is.erase(it);
    }
    return is.insert(before, {L,R});
}

void removeInterval(set<pii>& is, int L, int R) {
    if (L == R) return;
    auto it = addInterval(is, L, R);
    auto r2 = it->second;
    if (it->first == L) is.erase(it);
    else (int&)it->second = L;
    if (R != r2) is.emplace(R, r2);
}

const int inf = 0,setc=1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = setc, madd = 0, val = -inf;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    int query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R)+ r->query(L, R);
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = x, val=x*(hi-lo), madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = (l->val+ r->val);
        }
    }
    void add(int L, int R, int x) {
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
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    sort(a,a+n);
    vector<ll> pr(n+1,0);
    rep(i,1,n+1) {
        pr[i] = pr[i-1]+a[i-1];
    }
    n++;
    ll mxa = 1ll*n*(n-1) - pr[n-1];
    if(mxa<0) {
        cout <<"-1\n";
        return;
    }
    min_self(mxa, 1ll*n-1);
    Node st(0,mxa+1);
    st.set(0,mxa+1, 1);
    rep(i,1,n) {
        ll tmp = pr[n-1]-pr[n-i] - 1ll*i*(i-1);
        auto it = upper_bound(a, a+n-i-1, i) - (a);
        tmp -= (1ll*(n-1-i-it)*i + pr[it]);
        ll mx = -tmp;        
        set<pii> s;
        bool ok1 = i>= a[n-i-1]-mx;
        // debug() <<imie(i) imie(tmp) imie(mx);
        if(ok1) {
            ll l1 = a[n-i-1]-mx, r1 = a[n-i-1];
            if(l1<=r1) {
                if(!(r1<0 || l1>mxa)) {
                    // debug() <<imie(l1) imie(r1);
                    addInterval(s, max(0ll,l1), min(r1,mxa)+1);
                }
            }
        }
        ll l2 = a[n-i-1]+1, r2 = mx + min(i, a[n-i-1]);
        // debug() <<imie(l2) imie(r2);
        if(l2<=r2 && !(l2>mxa || r2<0)) {
            addInterval(s, max(0ll,l2),min(r2,mxa)+1);
        }
        if(!sz(s)) {
            cout <<"-1\n";
            return;
        }
        vi v;
        for(auto [l,r]: s) {
            v.push_back(l); v.push_back(r);
        }
        for(int j=0;j<sz(v);j+=2) {
            int le = j>0?v[j-1]:0;
            st.set(le,v[j],0);
        }
        st.set(v[sz(v)-1],mxa+1,0);
    }
    if(st.query(0,mxa+1)) {
        rep(i,0,mxa+1) {
            if(st.query(i,i+1) && ((pr[n-1]+i)%2)==0) {
                cout <<i <<" ";
            }
        }
        cout <<"\n";
    } else {
        cout <<"-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}