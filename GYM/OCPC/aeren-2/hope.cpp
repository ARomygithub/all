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

const int mxn=1e5,mxm=14e5,mxa=2e9;
int n;
using piii = pair<pii,int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    vector<piii> v;
    set<piii> s;
    rep(i,0,220) {
        rep(j,0,220) {
            v.push_back({{i,j},1});
        }
    }
    vector<pii> vm;
    // hori
    rep(y,0,220) {
        int b = 1, c = -y; 
        for(int id = y;id<220*220;id+=220) {
            vm.push_back({id,sz(v)});
        }
        v.push_back({{0,b},c});
        b = -1, c = y;
        for(int id = y;id<220*220;id+=220) {
            vm.push_back({id,sz(v)});
        }
        v.push_back({{0,b},c});        
    }
    // verti
    rep(x,0,220) {
        int a = 1, c = -x;
        rep(i,0,220) {
            int id = x*220+i;
            vm.push_back({id,sz(v)});
        }
        v.push_back({{a,0},c});
        a = -1, c = x;
        rep(i,0,220) {
            int id = x*220+i;
            vm.push_back({id,sz(v)});
        }
        v.push_back({{a,0},c});
    }
    for(auto [xy,z]: v) {
        s.insert({xy,z});
    }
    rep(i1,0,220) {
        rep(i2,i1+1,220) {
            rep(j1,0,220) {
                rep(j2,0,220) {
                    if(j1==j2) continue;
                    if(gcd(i2-i1,j2-j1)!=1) continue;
                    if(abs(j1-j2)>13) continue;
                    int a = (j2-j1), b = (i1-i2);
                    int c = -(a*i1 + b*j1);
                    int d = gcd(gcd(a,b), c);
                    a /= d, b /=d , c /= d;
                    if(!s.count({{a,b},c})) {
                        piii cur = {{a,b},c};
                        rep(i,0,220) {
                            int temp = a*i+c;
                            if((temp%b)==0) {
                                int j = (-temp)/b;
                                if(j>=0 && j<220) {
                                    // assert(1ll*i*a+1ll*b*j+c==0);
                                    // bool pas = v[i*220+j].fi== pii({i,j}); 
                                    // if(!pas) {
                                    //     debug() <<imie(i) imie(j) imie(i*220+j);
                                    // }
                                    // assert(pas);
                                    vm.push_back({i*220+j,sz(v)});
                                }
                            }
                        }
                        v.push_back(cur);
                        s.insert(cur);
                    } 
                    a *= -1, b *= -1, c *= -1;
                    if(!s.count({{a,b},c})) {
                        piii cur = {{a,b},c};
                        rep(i,0,220) {
                            int temp = a*i+c;
                            if((temp%b)==0) {
                                int j = (-temp)/b;
                                if(j>=0 && j<220) {
                                    // assert(1ll*i*a+1ll*b*j+c==0);
                                    // bool pas = v[i*220+j].fi== pii({i,j}); 
                                    // if(!pas) {
                                    //     debug() <<imie(i) imie(j) imie(i*220+j);
                                    // }
                                    // assert(pas);
                                    vm.push_back({i*220+j,sz(v)});
                                }
                            }
                        }
                        v.push_back(cur);
                        s.insert(cur);
                    }     
                    if(sz(v)>=mxn || sz(vm)>=mxm) break;                
                }
                if(sz(v)>=mxn || sz(vm)>=mxm) break;
            }
            if(sz(v)>=mxn || sz(vm)>=mxm) break;
        }
        if(sz(v)>=mxn || sz(vm)>=mxm) break;
    }
    auto rnd = [&]() -> int {
        return (rng()%mxa)-(mxa/2);
    };
    while(sz(v)<mxn) {
        int a = rnd(), b = rnd(), c= rnd();
        if(a==0 && b==0 && c==0) {
            continue;
        }
        int d = gcd(gcd(a,b), c);
        a /= d, b /= d, c /= d;
        piii cur = {{a,b},c};
        if(!s.count(cur)) {
            v.push_back(cur);
            s.insert(cur);
        }
    }
    // assert(sz(s)==sz(v));
    cout <<sz(v) <<"\n";
    rep(i,0,sz(v)) {
        // if(v[i]==piii{{0,0},0}) {
        //     assert(false);
        // }
        cout <<v[i].fi.fi <<" " <<v[i].fi.se <<" " <<v[i].se <<"\n";
    }
    cout <<min(sz(vm),mxm) <<"\n";
    rep(i,0,min(sz(vm),mxm)) {
        cout <<vm[i].fi <<" " <<vm[i].se <<"\n";
        // auto [j,k] = vm[i];
        // bool ok = 1ll*v[j].fi.fi*v[k].fi.fi + 1ll*v[j].fi.se*v[k].fi.se + 1ll*v[j].se*v[k].se == 0; 
        // if(!ok) {
        //     debug() <<imie(v[j]) imie(v[k]);
        // }
        // assert(ok);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}