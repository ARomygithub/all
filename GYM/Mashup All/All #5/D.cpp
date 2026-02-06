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
int n,m;
int a[mxn],b[mxn];
ll k;

void solve() {
    cin >>n >>m >>k;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,m) {
        cin >>b[i];
    }
    vector v(mxn*2 + 1,vi());
    int d = __gcd(n,m);
    n /=d;
    m /=d;
    rep(i,0,n*d) {
        v[a[i]].push_back(i);
    }
    rep(j,0,m*d) {
        v[b[j]].push_back(j);
    }
    vector<ll> vm;
    ll ni = -1;
    rep(i,1,m) {
        if((1ll*n*i %m)==1) {
            ni = i;
            break;
        }
    }
    // assert(ni!=-1);
    rep(i,1,sz(v)) {
        if(sz(v[i])==2) {
            int ii = v[i][0], jj=v[i][1];
            if(m==1) {
                if((ii%d)==(jj%d)) {
                    vm.push_back(ii);
                }
                continue;
            }
            int ji = (jj-ii)%(d*m);
            ji = (ji+d*m)%(d*m);
            if((ji%d)==0) {
                ll md = ji/d;
                md = md*ni%m;
                md = md*d*n;
                md = md+ii;
                // assert(md<1ll*d*n*m);
                vm.push_back(md);
            }
        }   
    }
    // assert(sz(vm)<1ll*d*n*m);
    sort(all(vm));
    // rep(i,0,sz(vm)-1) {
    //     assert(vm[i]!=vm[i+1]);
    // }
    // debug() <<imie(vm);
    ll ans = -1;
    ll dnm = 1ll*d*n*m;
    ll l=1, ri = ((k+dnm-sz(vm)-1)/(dnm-sz(vm)))*dnm;
    while(l<=ri) {
        ll mid = (l+ri)/2;
        ll r = mid%(dnm);
        ll s = mid/dnm;
        ll cur = s*sz(vm);
        if(sz(vm)) {
            cur += lower_bound(all(vm),r)-vm.begin();
        }
        if(mid-cur>=k) {
            ans = mid;
            ri = mid-1;
        } else {
            l = mid+1;
        }
    }
    // assert(ans!=-1);
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}