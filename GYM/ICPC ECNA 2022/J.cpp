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

const int mxn=1e5;
string s[52];

void solve() {
    int n = 52;
    // cin >>n;
    rep(i,0,n) {
        cin >>s[i];
    }
    vector<string> v;
    function<void(vector<string>&,int)> rec;
    rec = [&](vector<string>& vs, int ls) -> void {
        int cand = -1;
        int szi = sz(vs);
        per(i,sz(vs)-1,sz(vs)-ls-1) {
            if(i-3>=0) {
                if(vs[i-3][0]==vs[i][0]) {
                    // do rank
                    stack<string> tmp;
                    per(j,sz(vs)-1,i) {
                        tmp.push(vs[j]);
                    }
                    per(j,sz(vs)-1,i) {
                        vs.pop_back();
                    }
                    rep(j,0,4) {
                        vs.pop_back();
                    }
                    int ls_new = sz(tmp);
                    ls_new += max(0, ls-(szi-i+3));
                    while(sz(tmp)) {
                        vs.push_back(tmp.top()); tmp.pop();
                    }
                    if(ls_new>0) {
                        rec(vs, ls_new);
                    }
                    return;

                } else if(vs[i-3][1]==vs[i][1]) {
                    if(cand==-1) {
                        cand = i;
                    }
                }
            }
        }
        if(cand!=-1) {
            // do suit
            int ls_new = szi-cand;
            ls_new += max(0, ls-(szi-cand+3));
            // if(szi-(cand-1) <=ls) ls_new++;
            // if(szi-(cand-2) <=ls) ls_new++;
            ls_new += 2;
            stack<string> tmp;
            per(j,szi-1,cand) {
                tmp.push(vs.back());
                vs.pop_back();
            }
            string b1 = vs[sz(vs)-2], b2= vs[sz(vs)-3];
            rep(j,0,4) {
                vs.pop_back();
            }
            vs.push_back(b2); vs.push_back(b1);
            while(sz(tmp)) {
                vs.push_back(tmp.top()); tmp.pop();
            }
            // debug() <<imie(vs);
            rec(vs, ls_new);
        }
    };
    rep(i,0,n) {
        if(sz(v)>=3) {
            string b3 = v[sz(v)-3];
            if(b3[0]==s[i][0]) {
                rep(j,0,3) {
                    v.pop_back();
                }
            } else if(b3[1]==s[i][1]) {
                string b2 = v[sz(v)-2], b1 = v[sz(v)-1];
                rep(j,0,3) {
                    v.pop_back();
                }
                v.push_back(b2);
                v.push_back(b1);
                rec(v, 2);
            } else {
                v.push_back(s[i]);
            }
        } else {
            v.push_back(s[i]);
        }
        // debug() <<imie(v);
    }
    cout <<sz(v) <<" \n"[sz(v)==0];
    rep(i,0,sz(v)) {
        cout <<v[i] <<" \n"[i==sz(v)-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}