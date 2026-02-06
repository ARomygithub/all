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

const int mxn=2e5;
int n,t;
int a[mxn];
using piii = pair<pii,int>;

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    set<piii> v;
    set<piii> s;
    for(int i=0;i<n;) {
        int j = i;
        while(j<n && a[j]==a[i]) {
            j++;
        }
        v.insert({{i,j},a[i]});
        s.insert({{j-i,-i},a[i]});
        i = j;
    } 
    int ct = 0;
    while(sz(s)) {
        ct++;
        auto it = --s.end();
        auto [szii, val] = (*it);
        auto [szi, i] = szii;
        i *= -1;
        auto iti = v.find({{i,i+szi},val});
        if(iti!=v.begin()) {
            auto itin = iti; itin++;
            if(itin!=v.end()) {
                auto itip = iti; itip--;
                if(itip->se == itin->se) {
                    auto le = *itip;
                    auto ri = *itin;
                    v.erase(le); v.erase(ri);
                    int szl = le.fi.se-le.fi.fi;
                    int szr = ri.fi.se-ri.fi.fi;
                    s.erase({{szl,le.fi.fi*-1},le.se});
                    s.erase({{szr,ri.fi.fi*-1},ri.se});
                    auto [lei,lej] = le.fi;
                    auto [rii, rij] = ri.fi;
                    int ni = min(lei,rii);
                    int nj = ni + (lej-lei)+(rij-rii);
                    v.insert({{ni,nj},le.se});
                    s.insert({{nj-ni, ni*-1},le.se});
                }
            }
        }
        v.erase({{i,i+szi},val});
        s.erase({szii,val});
    }
    cout <<ct <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}