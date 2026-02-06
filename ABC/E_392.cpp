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
int n,m;

struct UF {
    vi e;
    set<int> st;
    UF(int n) : e(n, -1) {
        rep(i,0,n) {
            st.insert(i);
        }
    }
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        st.erase(b);
        return true;
    }
};
using ipii = pair<int,pii>;

void solve() {
    cin >>n >>m;
    UF uf(n);
    vector<ipii> cl;
    int ct = n;
    rep(i,0,m) {
        int u,v; cin >>u >>v; u--,v--;
        if(!uf.join(u,v)) {
            cl.push_back({i,{u,v}});
        } else {
            ct--;
        }
    }
    cout <<ct-1 <<"\n";
    for(auto [id, uv]: cl) {
        if(ct==1) break;
        auto [u,v] = uv;
        int pu = uf.find(u);
        auto it = uf.st.begin();
        while((*it)==pu) it++;
        cout <<id+1 <<" " <<v+1 <<" " <<(*it)+1 <<"\n";
        uf.join(pu,(*it));
        ct--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}