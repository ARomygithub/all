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

using pipi = pair<pii,pii>;
#include <bits/extc++.h> /** keep-include */
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { // To use most bits rather than just the lowest ones:
	const uint64_t C = ll(4e18 * acos(0)) | 71; // large odd number
	ll operator()(pipi xp) const { 
        auto [imj, ipj] = xp;
        auto [imj1,imj2] = imj;
        auto [ipj1, ipj2] = ipj;
        imj1 += 24;
        imj2 += 24;
        ll x = imj1*50*50*50 + imj2*50*50 + ipj1*50 + ipj2;
        return __builtin_bswap64((x^RANDOM)*C);
    }
};
__gnu_pbds::gp_hash_table<pipi, int, chash> sg({},{},{},{}, {1 << 16});

const int mxn=25;
int n,m;
string s[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
    }
    // map<pipi,int> sg;
    for(int len1=1;len1<=n+m-1;len1+=2) {
        rep(imj1,-m+1,n) {
            int imj2 = imj1+len1-1;
            if(imj2>=n) break;
            for(int len2=1;len2<=n+m-1;len2+=2) {
                for(int ipj1 = (imj1+n*m*2)%2;ipj1<n+m-1;ipj1+=2) {
                    int ipj2 = ipj1+len2-1;
                    if(ipj2>=n+m-1) break;
                    pipi st = {{imj1,imj2},{ipj1,ipj2}};
                    set<int> mx;
                    for(int imji=imj1;imji<=imj2;imji+=2) {
                        for(int ipji=ipj1; ipji<=ipj2;ipji+=2) {
                            int i = (imji+ipji)/2;
                            int j = (ipji-imji)/2;
                            if(i>=0&&i<n&&j>=0&&j<m) {
                                int temp = 0;
                                if(s[i][j]=='R') {
                                    temp ^= sg[{{imj1,imj2},{ipj1,ipji-2}}];
                                    temp ^= sg[{{imj1,imj2},{ipji+2,ipj2}}];
                                } else if(s[i][j]=='B') {
                                    temp ^= sg[{{imj1,imji-2},{ipj1,ipj2}}];
                                    temp ^= sg[{{imji+2,imj2},{ipj1,ipj2}}];
                                } else {
                                    pii kiri = {imj1,imji-2}, knn = {imji+2,imj2}, ats={ipj1,ipji-2}, bwh = {ipji+2,ipj2}; 
                                    temp ^= sg[{kiri,ats}];
                                    temp ^= sg[{kiri,bwh}];
                                    temp ^= sg[{knn,ats}];
                                    temp ^= sg[{knn,bwh}];
                                }
                                mx.insert(temp);
                            }
                        }
                    }
                    int mxi = 0;
                    for(auto a : mx) {
                        if(a==mxi) {
                            mxi++;
                        } else {
                            break;
                        }
                    }
                    sg[st] = mxi;
                    // debug() <<imie(st) imie(mxi);
                }
            }
        }
    }
    int kr1 = (-m+1),kr2=kr1+1;
    int kn1 = n-1,kn2=kn1-1;
    if(((kn1-kr1)%2)) {
        swap(kn1,kn2);
    }
    int bwh1 = 0, bwh2=1;
    int ats1 = n+m-2, ats2=ats1-1;
    if(ats1%2) {
        swap(ats1,ats2);
    }
    if((kr1-bwh1)%2) {
        swap(bwh1,bwh2);
        swap(ats1,ats2);
    }
    int ans = sg[{{kr1,kn1},{bwh1,ats1}}]^sg[{{kr2,kn2},{bwh2,ats2}}];
    // debug() <<imie(kr1) imie(kn1) imie(bwh1) imie(ats1);
    // debug() <<imie(kr2) imie(kn2) imie(bwh2) imie(ats2);
    if(ans) {
        cout <<"W\n";
    } else {
        cout <<"L\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}