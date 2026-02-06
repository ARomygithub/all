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

const int mxn=2e3+1,mxa=2e3,mxnm=4e3+1;
int n,m;
int a[mxn],b[mxn];
clock_t st = clock();

void cek_time() {
    clock_t cur = clock()-st;
    cerr <<"TIME: " <<(double) cur/CLOCKS_PER_SEC <<endl;
}

void solve() {
    cin >>n >>m;
    int sa=0,sb=0;
    int amx = 0;
    rep(i,0,n) {
        cin >>a[i];
        max_self(amx, a[i]);
        sa += a[i];
    }
    rep(i,0,m) {
        cin >>b[i];
        sb += b[i];
    }
    max_self(amx, sb);
    // vector<bool> ok(mxa+1,0);
    // ok[0] = 1;
    // rep(i,0,n) {
    //     per(j,mxa,a[i]) {
    //         ok[j] = ok[j] || ok[j-a[i]];
    //     }
    // }
    if(sb>=sa) {
        cout <<sb <<"\n";
        return;
    }
    vector<bitset<mxn>> bs(mxn);
    bs[0].set(0);
    rep(i,0,n) {
        per(j,mxn-1,-1) {
            bs[j] = bs[j] | (bs[j] << a[i]);
            if(j>=a[i]) {
                bs[j] = bs[j] | bs[j-a[i]];
            }
        }
    }
    // cek_time();
    // tes
    // rep(i,0,mxn) {
    //     rep(j,i+1,mxn) {
    //         assert(bs[i][j]==bs[j][i]);
    //     }
    // }
    // rep(i,0,mxn) {
    //     rep(j,0,mxn) {
    //         if(bs[i][j]) {
    //             debug() <<imie(i) imie(j);
    //         }
    //     }
    // }
    bitset<mxn> bsm;
    bsm.set(0);
    rep(i,0,m) {
        bsm = bsm | (bsm << b[i]);
    }
    // vi vm;
    vi vml(mxn);
    rep(j,0,mxn) {
        if(bsm[j]) {
            vml[j] = j;
        } else {
            vml[j] = vml[j-1];
        }
    }
    // vector<bitset<mxnm>> bs2(mxn);
    // rep(i,0,mxn) {
    //     for(auto j : vm) {
    //         // if(i==0) {
    //         //     debug() <<imie(j);
    //         // }
    //         bs2[i] = bs2[i] | (bs[i] << j);
    //     }
    // }
    // cek_time();
    int ans = -1;
    int l = max((sa+sb+2)/3, amx), r = max(sa,sb);
    // debug() <<imie(l) imie(r);
    while(l<=r) {
        int mid = (l+r)/2;
        int s1 = mid, s2 = mid-sb;
        bool ok = 0;
        rep(i,0,min(s2,sa)+1) {
            rep(j,i,min(s1,sa)+1) {
                if(bs[i][j]) {
                    auto it = vml[s1-j];
                    int sisa = sa+sb - i-j - (it);
                    if(sisa<=s1) {
                        ok = 1;
                        break;
                    }
                }
            }
            if(ok) break;
        }
        if(ok) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    // cek_time();
    assert(ans!=-1);
    cout << ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}