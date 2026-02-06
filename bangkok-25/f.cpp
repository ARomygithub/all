#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i= a; i < (b);i++)
#define per(i,a,b) for(int i= a; i > (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
#define fi first
#define se second
#define what_is(x) cerr << #x <<": " <<x <<endl;

struct Tree {
    typedef ll T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a+b;}
    vector<T> s; int n;
    Tree(int n=0, T def = unit): s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for(s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos*2], s[pos*2+1]);
    }
    T query(int b, int e) {
        T ra = unit, rb = unit;
        for(b +=n, e += n; b < e; b /= 2, e /= 2) {
            if(b%2) ra = f(ra, s[b++]);
            if(e%2) rb = f(s[--e], rb);
        }
        return f(ra,rb);
    }
};

const int mxn = 2e5;
ll n,pp;
ll h[mxn],p[mxn];
using pli = pair<ll,int>;
using lpli= pair<ll,pli>;

void solve() {
    cin >>n >>pp;
    rep(i,0,n) {
        cin >>h[i] >>p[i];
    }
    Tree sth(n), stp(n);
    vector<lpli> v;
    rep(i,0,n) {
        v.push_back({h[i],{p[i],i}});
    }
    sort(all(v));
    ll mx = 0, th=0;
    for(int i=n-1;i>=0;) {
        int j = i;
        while(j>=0 && v[j].fi==v[i].fi) {
            j--;
        }
        what_is(i)
        what_is(j)
        rep(k,j+1,i+1) {
            auto [hi, pid] = v[k];
            what_is(k)
            auto [pi, id] = pid;
            what_is(hi)
            what_is(pi)
            what_is(id)
            sth.update(id, hi);
            stp.update(id, pi);
        }
        int le = 0, ri = n;
        int ct = -1;
        ll ch = 0;
        while(le<=ri) {
            int mid = (le+ri)/2;
            what_is(mid)
            ll cur = stp.query(0,mid);
            ll bcur = 0;
            rep(k,0,mid) {
                bcur += stp.s[k+n];
            }
            assert(cur==bcur);
            what_is(cur)
            if(cur<=pp) {
                ll cand = sth.query(0,mid);
                what_is(cand)
                ll bcand = 0;
                rep(k,0,mid) {
                    bcand += sth.s[k+n];
                }
                assert(cand==bcand);
                ct = mid;
                ch = cand;
                le = mid+1;
            } else {
                ri = mid-1;
            }
        }
        what_is(ch)
        what_is(ct)
        what_is(mx)
        if(ch>=mx) {
            mx = ch;
            th = 0;
            if(j>=0) {
                th = v[j].fi;
            }
        }
        i = j;
    }
    cout <<mx <<" " <<th <<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tc; cin >>tc;
    while(tc--) {
        solve();
    }
}

/*
1
5 2
2 5
1 1
4 3
4 4
4 5
i: 4
j: 1
k: 2
hi: 4
pi: 3
id: 2
k: 3
hi: 4
pi: 4
id: 3
k: 4
hi: 4
pi: 5
id: 4
mid: 2
cur: 0
cand: 0
mid: 4
cur: 7
mid: 3
cur: 3
ch: 0
ct: 2
mx: 0
i: 1
j: 0
k: 1
hi: 2
pi: 5
id: 0
mid: 2
cur: 5
mid: 0
cur: 0
cand: 0
mid: 1
cur: 5
ch: 0
ct: 0
mx: 0
i: 0
j: -1
k: 0
hi: 1
pi: 1
id: 1
mid: 2
cur: 6
mid: 0
cur: 0
cand: 0
mid: 1
cur: 5
ch: 0
ct: 0
mx: 0
0 0
*/

/*
1
4 14
4 6
1 5
3 3
3 1
i: 3
j: 2
mid: 2
cur: 5
cand: 1
mid: 3
cur: 5
cand: 1
mid: 4
cur: 5
cand: 1
ch: 1
ct: 4
mx: -1
i: 2
j: 0
mid: 2
cur: 5
cand: 1
mid: 3
cur: 8
cand: 4
mid: 4
cur: 9
cand: 7
ch: 7
ct: 4
mx: 1
i: 0
j: -1
mid: 2
cur: 11
cand: 5
mid: 3
cur: 14
cand: 8
mid: 4
cur: 15
ch: 8
ct: 3
mx: 7
8 0
*/