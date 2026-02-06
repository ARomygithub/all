#include <bits/stdc++.h>
using namespace std;

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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}
typedef pair<pii,int> piii;
typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
// static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)
static const H C = (ll)10; // (order ~ 3e9; random also ok)
typedef pair<ull,piii> pui;

const int mxn=1e3;
int n;
string a[mxn];

H getHash(string ai) {
    H ha;
    rep(i,0,sz(ai)) {
        ha = ha * C + (ai[i]-'0');
    }
    return ha;
}

void solve() {
    cin >>n;
    vector<H> v;
    vector<double> vd;
    rep(i,0,n) {
        cin >>a[i];
        v.push_back(getHash(a[i]));
        int ct=18;
        double pw = 1.0;
        double vdi = 0.0;
        rep(j,0,min(ct,sz(a[i]))) {
            vdi += pw*(a[i][j]-'0');
            pw /=10.0;
        }
        vd.push_back(vdi);
    }
    map<pui, int> mp;
    rep(i,0,n) {
        mp[{v[i].get(),{{sz(a[i]),a[i][0]-'0'},(a[i][sz(a[i])-1]-'0')}}]++;
    }
    int ans = 0;
    rep(i,0,n) {
        rep(j,0,n) {
            H temp = v[i]*v[j];
            double temp2 = vd[i]*vd[j];
            int len = sz(a[i])+sz(a[j])-1 + (temp2>=10.0);
            int temp22 = temp2;
            int akhir = (a[i][sz(a[i])-1]-'0')*(a[j][sz(a[j])-1]-'0');
            akhir = (akhir)%10;
            while(temp22>=10) {
                temp22 /=10;
            }
            ans += mp[{temp.get(),{{len,temp22},akhir}}];
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}