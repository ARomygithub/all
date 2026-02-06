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

const int mxn=2e5;
int n,t;
using tup = tuple<int,int,int,int,int>;

void solve() {
    cin >>n;
    vector<tup> ats,bwh,v2;
    rep(i,0,n) {
        int u,l,d,r; cin >>u >>l >>d >>r;
        if(u==1 && d==2) {
            v2.push_back({u,l,d,r,i});
        } else if(u==1) {
            ats.push_back({u,l,d,r,i});
        } else {
            bwh.push_back({u,l,d,r,i});
        }
    }
    {
        sort(all(v2));
        int ls = 0;
        rep(i,0,sz(v2)) {
            auto [u,l,d,r,id] = v2[i];
            if(r>ls) {
                max_self(l, ls+1);
                ls = r;
                v2[i] = {u,l,d,r,id};
            } else {
                v2[i] = {0,0,0,0,id};
            }
        }
    }
    {
        sort(all(v2));
        sort(all(ats));
        int ls = 0;
        int j = 0;
        while(j<sz(v2) && get<0>(v2[j])==0) {
            j++;
        }
        // ls = ?
        rep(i,0,sz(ats)) {
            auto [u,l,d,r,id] = ats[i];
            // debug() <<imie(u) imie(l) imie(d) imie(r) imie(id);
            if(r<=ls) {
                ats[i] = {0,0,0,0,id};
                continue;
            }
            while(j<sz(v2) && get<3>(v2[j])<l) {
                max_self(ls, get<3>(v2[j]));
                j++;
            }
            max_self(l, ls+1);
            // irisan, non-irisan
            while(true) {
                if(j<sz(v2)) {
                    auto [u2,l2,d2,r2,id2] = v2[j];
                    // debug() <<imie(u2) imie(l2) imie(d2) imie(r2) imie(id2);
                    if(l2<=l) {
                        if(r2>=r) {
                            max_self(ls,r2);
                            u = 0, l=0,d=0,r=0;
                            break;
                        } else {
                            max_self(l, r2+1);
                        }
                        j++;
                    } else if(l<=l2 && r2<=r) {
                        v2[j] = {2,l2,2,r2,id2};
                        j++;
                    } else {
                        // debug() <<imie(r) imie(l2-1);
                        min_self(r, l2-1);
                        break;
                    }
                } else {
                    break;
                }
            }
            max_self(ls, r);
            if(l>r) {
                u=0,l=0,d=0,r=0;
            }
            ats[i] = {u,l,d,r,id};
        }
    }
    {
        sort(all(bwh));
        int ls = 0;
        int j = 0;
        while(j<sz(v2) && get<0>(v2[j])==0) {
            j++;
        }
        rep(i,0,sz(bwh)) {
            auto [u,l,d,r,id] = bwh[i];
            if(r<=ls) {
                bwh[i] = {0,0,0,0,id};
                continue;
            }
            while(j<sz(v2) && get<3>(v2[j])<l) {
                max_self(ls, get<3>(v2[j]));
                j++;
            }
            max_self(l, ls+1);
            while(true) {
                if(j<sz(v2)) {
                    auto [u2,l2,d2,r2,id2] = v2[j];
                    if(l2<=l) {
                        if(r2>=r) {
                            max_self(ls,r2);
                            u = 0, l=0,d=0,r=0;
                            break;
                        } else {
                            max_self(l, r2+1);
                        }
                        j++;
                    } else if(l<=l2 && r2<=r) {
                        if(u2==1) {
                            v2[j] = {1,l2,1,r2,id2};
                        } else {
                            v2[j] = {0,0,0,0,id2};
                        }
                        j++;
                    } else {
                        min_self(r, l2-1);
                        break;
                    }
                } else {
                    break;
                }
            }
            max_self(ls, r);
            if(l>r) {
                u=0,l=0,d=0,r=0;
            }
            bwh[i] = {u,l,d,r,id};            
        }
    }

    vector<tup> ans(n);
    int area = 0;
    auto isi = [&](vector<tup>& vv) -> void {
        for(auto& [u,l,d,r,id]: vv) {
            ans[id] = {u,l,d,r,id};
            if(u>0) {
                area += (d-u+1)*(r-l+1);
            }
        }
    };
    isi(v2);
    isi(ats);
    isi(bwh);
    cout <<area <<"\n";
    rep(i,0,n) {
        auto& [u,l,d,r,id] = ans[i];
        cout <<u <<" " <<l <<" " <<d <<" " <<r <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}