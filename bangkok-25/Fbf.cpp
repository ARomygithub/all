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

    
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<ll, ll> solve1(ll N, ll P, vector<pair<ll, ll>> vp) {
    // ll N, P;
    //  cin >> N >> P;
    // vector<pair<ll, ll>> vp(N);

    ll mx = 0;
    for (int i = 0; i < N; i++) {
        // cin >> vp[i].first >> vp[i].second;
        mx = max(mx, vp[i].first);
    }

    ll ans = 0;
    ll thresh = -1;
    for (int i = 0; i <= mx; i++) {
        int threshold = i;
        ll ht = 0;
        ll m = 0;
        for (int j = 0; j < N; j++) {
            if (vp[j].first > threshold && m + vp[j].second <= P) {
                ht = ht + vp[j].first;
                m = m + vp[j].second;
            }
        }

        
        if (ans < ht) {
            ans = ht;
            thresh = threshold;
        }
    }

    return {ans, thresh};
}

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

pair<ll, ll> solve2(ll n, ll pp, vector<pair<ll, ll>> vp) {
    // cin >>n >>pp;
    rep(i,0,n) {
        h[i] = vp[i].first;
        p[i] = vp[i].second;
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
        // what_is(i)
        // what_is(j)
        rep(k,j+1,i+1) {
            auto [hi, pid] = v[k];
            // what_is(k)
            auto [pi, id] = pid;
            // what_is(hi)
            // what_is(pi)
            // what_is(id)
            sth.update(id, hi);
            stp.update(id, pi);
        }
        int le = 0, ri = n;
        int ct = -1;
        ll ch = 0;
        while(le<=ri) {
            int mid = (le+ri)/2;
            // what_is(mid)
            ll cur = stp.query(0,mid);
            // ll bcur = 0;
            // rep(k,0,mid) {
            //     bcur += stp.s[k+n];
            // }
            // assert(cur==bcur);
            // what_is(cur)
            if(cur<=pp) {
                ll cand = sth.query(0,mid);
                // what_is(cand)
                // ll bcand = 0;
                // rep(k,0,mid) {
                //     bcand += sth.s[k+n];
                // }
                // assert(cand==bcand);
                ct = mid;
                ch = cand;
                le = mid+1;
            } else {
                ri = mid-1;
            }
        }
        // what_is(ch)
        // what_is(ct)
        // what_is(mx)
        if(ch>=mx) {
            mx = ch;
            th = 0;
            if(j>=0) {
                th = v[j].fi;
            }
        }
        i = j;
    }
    return {mx, th};
}

int main() {

    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tc; tc = 1000;

    while(tc--) {
        what_is(tc)
        ll N = (rng() % 5) + 1;
        ll P = (rng() % 5) + 1;
        vector<pair<ll, ll>> vp;
        for (int i = 0; i < N; i++) {
            int rand1 = (rng() % 5) + 1;
            int rand2 = (rng() % 5) + 1;
            vp.push_back({rand1, rand2});
        } 

        pair<ll, ll> ans1 = solve1(N, P, vp);
        pair<ll, ll> ans2 = solve2(N, P, vp);
        if (ans1 != ans2) {
            cout << N << ' ' << P << '\n';
            for (int i = 0; i < N; i++) {
                cout << vp[i].first << ' ' << vp[i].second << '\n';
            }

            what_is(ans1.first)
            what_is(ans1.second)
            what_is(ans2.first)
            what_is(ans2.second)
            return 0;
        }
    }
}

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