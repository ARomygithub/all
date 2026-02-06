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
using piii = pair<pii,pii>;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=50;
const int di[4]={1,0,-1,0}, dj[4]={0,1,0,-1};
map<char,int> mp= {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
int m,n,ed, c1,r1,c2,r2;
char d1,d2;
set<pii> sh,sv;

int toSt(int ri, int ci) {
    if(ri<0) {
        return m*n;
    }
    return ri*m+ci;
}

pii toRc(int st) {
    if(st==(n*m)) {
        return {-1,ed};
    }
    return {st/m, st%m};
}

bool e(int& nr1, int& nc1, int& ri1, int& ci1, int& nr2, int& nc2, int& ri2, int& ci2, int& nb) {
    if(nr1!=ri1) {
        int mn = min(nr1,ri1);
        if(nr1==-1 && nc1 == ed) {
            ;
        } else if(sh.count({mn,ci1}) || nr1<0 || nr1>=n) {
            nr1 = ri1;
            nb++;
        }
    } else if(nc1!=ci1) {
        int mn = min(nc1,ci1);
        if(sv.count({ri1,mn}) || nc1<0 || nc1>=m) {
            nc1 = ci1;
            nb++;
        }
    }
    if(nr2!=ri2) {
        int mn = min(nr2,ri2);
        if(nr2==-1 && nc2 == ed) {
            ;
        } else if(sh.count({mn,ci2}) || nr2<0 || nr2>=n) {
            nr2 = ri2;
            nb++;
        }
    } else if(nc2!=ci2) {
        int mn = min(nc2,ci2);
        if(sv.count({ri2,mn}) || nc2<0 || nc2>=m) {
            nc2 = ci2;
            nb++;
        }
    }    
    assert((nr1==-1 && nc1==ed) || (nr1>=0&&nr1<n&&nc1>=0&&nc1<m));
    assert((nr2==-1 && nc2==ed) || (nr2>=0&&nr2<n&&nc2>=0&&nc2<m));
    assert(abs(nr1-ri1)+abs(nc1-ci1)<=1);
    assert(abs(nr2-ri2)+abs(nc2-ci2)<=1);
    if(nr1>=0 &&nr2>=0 && nr1==nr2 && nc1==nc2) return false;
    return true;
}

void solve() {
    cin >>m >>n >>ed; ed--;
    cin >>c1 >>r1 >>d1 >>c2 >>r2 >>d2; c1--,r1--,c2--,r2--;
    int shk; cin >>shk;
    rep(i,0,shk) {
        int ci, ri; cin >>ci >>ri; ci--,ri--;
        sh.insert({ri,ci});
    }
    int svk; cin >>svk;
    rep(i,0,svk) {
        int ci, ri; cin >>ci >>ri; ci--,ri--;
        sv.insert({ri,ci});
    }
    int dif = (mp[d2]-mp[d1]+4)%4;
    int mx = n*m+1;
    vector dp(mx, vector<pii>(mx, {1e9,1e9}));
    dp[toSt(r1,c1)][toSt(r2,c2)] = {0,0};
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    pq.push({{0,0},{toSt(r1,c1),toSt(r2,c2)}});
    while(sz(pq)) {
        auto [db, st1st2] = pq.top(); pq.pop();
        auto [d,b] = db;
        auto [st1,st2] = st1st2;
        if(dp[st1][st2]<db) continue;
        // debug() <<imie(st1) imie(st2);
        auto [ri1, ci1] = toRc(st1);
        // debug() <<imie(ri1) <<imie(ci1);
        auto [ri2, ci2] = toRc(st2);
        // debug() <<imie(ri2) <<imie(ci2);
        // debug() <<imie(db);
        rep(i,0,4) {
            int nr1 = ri1+ di[i];
            int nc1 = ci1 + dj[i];
            int i2 = (i+dif)%4;
            int nr2 = ri2+ di[i2];
            int nc2 = ci2 + dj[i2];
            if(st1==mx-1) {
                nr1 = ri1, nc1=ci1;
            }
            if(st2==mx-1) {
                nr2 = ri2, nc2 = ci2;
            }
            int nb = b;
            if(e(nr1,nc1,ri1,ci1,nr2,nc2,ri2,ci2, nb)) {
                auto nst1 = toSt(nr1,nc1);
                auto nst2 = toSt(nr2,nc2);
                if(nr1==-1 && nc1==ed) {
                    nst1 = mx-1;
                }
                if(nr2==-1 && nc2==ed) {
                    nst2 = mx-1;
                }
                // debug() <<imie(nr1) imie(nc1);
                // debug() <<imie(nst1) imie(nst2);
                if(dp[nst1][nst2] > (pii){d+1,nb}) {
                    dp[nst1][nst2] = {d+1,nb};
                    pq.push({dp[nst1][nst2],{nst1,nst2}});
                }
            }
        }
    }
    auto [f, b] = dp[mx-1][mx-1];
    // assert(f<=50);
    // debug() <<imie(dp);
    // rep(i,0,mx) {
    //     rep(j,0,mx) {
    //         auto [ri1,ci1] = toRc(i);
    //         auto [ri2,ci2] = toRc(j);
    //         debug() <<imie(ri1) imie(ci1) imie(ri2) imie(ci2) imie(dp[i][j]);
    //     }
    // }
    cout <<f <<" " <<b <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}