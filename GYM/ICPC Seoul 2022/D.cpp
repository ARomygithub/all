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

const int mxn=1e5;
int n;
int a[mxn];
int ans = 2e9;
vi pref;

bool chk(int r, int sm) {
    if(r<0) return 1;
    int pos = -1,pos2=-1;
    int li=0,ri=r;
    int bwh = sm-a[r+1];
    while(li<=ri) {
        int mid = (li+ri)/2;
        int sm2 = pref[r+1]-pref[mid];
        if(sm2<=bwh) {
            pos2 = mid;
            ri =mid-1;
        } else if(sm2>sm) {
            li = mid+1;
        } else {
            pos = mid;
            li = mid+1;
        }
    }
    if(pos==-1) {
        if(pos2!=-1) {
            int sm2 = pref[r+1]-pref[pos2];
            return chk(pos2-1,sm2);
        } else {
            return false;
        }
    }
    while(pos>=0) {
        int sm2 = pref[r+1]-pref[pos];
        if(sm2>sm) break;
        if(chk(pos-1,sm2)) return true;
        pos--;
    }
    return false;
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    pref.resize(n+1,0);
    rep(i,0,n) {
        pref[i+1] = pref[i]+a[i];
    }
    int suf = 0;
    per(i,n-1,-1) {
        int sm = 0;
        per(j,i,-1) {
            sm += a[j];
            if(sm<=suf) continue;
            if(sm>ans) break;
            bool res = chk(j-1,sm);
            if(res) {
                // debug() <<imie(i) imie(j) imie(sm) imie(suf);
                ans = sm;
                break;
            }
        }
        suf += a[i];
        if(suf>ans) break;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}