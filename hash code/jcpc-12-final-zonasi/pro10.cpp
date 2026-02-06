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

const int mxn=3e4,mxm=1e3,mxa=1e8,dv=1e5,mxp=100;
int n,m;
struct P {
    double x,y;
};
/*
tc 1:
set sekolah di orang
tc 2,3 : 1D
ambil media dari ai orang
tc 4: n = 50
tc 5: n = 500, lingkaran gitu
tc 6: n = 5000, m = 2
2 sekolah. 
cari garis inside-border vs outside

*/
// using pvi = pair<int,vi>;
// using pd = pair<double,double>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int skor[mxp], iskor=-1;
P v[mxn];
int a[mxm];
int eval(vector<P>& vp) {
    vector cand0(m, vi()), cand1(m, vi());
    rep(i,0,n) {
        double mn = 1e9;
        vi sklh;
        rep(j,0,m) {
            double dist = hypot(abs(v[i].x-vp[j].x), abs(v[i].y-vp[j].y));
            if(dist<mn) {
                mn = dist;
                sklh.clear();
                sklh.push_back(j);
            } else if(dist==mn) {
                sklh.push_back(j);
            }
        }
        if(sz(sklh)>1) {
            for(auto sklhi: sklh) {
                cand1[sklhi].push_back(i);
            }
        } else {
            cand0[sklh[0]].push_back(i);
        }
    }
    vi idx(m);
    iota(all(idx), 0);
    sort(all(idx), [&](int i, int j) -> bool {
        return sz(cand0[i])+sz(cand1[i])>sz(cand0[j])+sz(cand1[j]);
    });
    vector<bool> udh(n,0);
    int cur_skor = 0;
    rep(i,0,sz(idx)) {
        int cap = a[i];
        int id = idx[i];
        int tmp = min(sz(cand0[id]), cap);
        rep(j,0,tmp) {
            udh[cand0[id][j]] = 1;
            cur_skor++;
        }
        cap -= tmp;
        rep(j,0,sz(cand1[id])) {
            if(cap==0) break;
            int candi = cand1[id][j];
            if(!udh[candi]) {
                udh[candi] = 1;
                cur_skor++;
                cap--;
            }
        }
    }
    return cur_skor;
}
vector<P> genM() {
    vector<P> ret;
    rep(i,0,m) {
        P p;
        p.x = rng()%(mxa+1);
        p.y = rng()%(mxa+1);
        p.x /= dv;
        p.y /= dv;
        ret.push_back(p);
    }
    // skor[iskor] = eval(ret);
    return ret;
}

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>v[i].x >>v[i].y;
    }
    rep(i,0,m) {
        cin >>a[i];
    }
    sort(a,a+m,greater<int>());
    // GA
    // init
    vector<vector<P>> par;
    rep(i,0,100) {
        iskor = i;
        par.push_back(genM());
    }
    while(true) {
        // eval skor
        // if perfect stop
        rep(i,0,sz(par)) {
            skor[i] = eval(par[i]);
            if(skor[i]==n) {
                cout <<
            }
        }
        // cut bottom-half
        vi idx(sz(par));
        iota(all(idx),0);
        sort(all(idx), )
        // mutate the other half
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}