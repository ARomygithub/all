#include <bits/stdc++.h>
using namespace std;

// #define fi first
// #define se second
// #define sim template < class c
// #define ris return * this
// #define dor > debug & operator <<
// #define eni(x) sim > typename \
//     enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
// sim > struct rge {c b, e;};
// sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
// sim > auto dud(c* x) -> decltype(cerr << *x, 0);
// sim > char dud(...);
// struct debug{
//     ~debug() {cerr << endl;}
//     eni(!=) cerr << boolalpha << i; ris; }
//     eni(==) ris << range(begin(i), end(i)); }
//     sim, class b dor(pair <b, c> d) {
//         ris <<"(" <<d.fi <<", " <<d.se <<")";
//     }
//     sim dor(rge<c> d) {
//         *this << "[";
//         for(auto it=d.b;it!=d.e;++it) {
//             *this <<", " + 2*(it==d.b) <<*it;
//         }
//         ris << "]";
//     }
// };
// #define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=3e5;
int n,c,t;

ll f(ll l, ll r, ll ct0, ll ct1, ll step, bool even) {
    min_self(step, (r-l+2)/2);
    ll ret = 0;
    ll st = (r-l+2)/2;
    ll en = st-(step-1);
    ret += step*(st+en)/2;
    ret -= (ct0+ct1)*(step/2) + (step%2==1? (even?ct0:ct1):0ll);
    return ret;
}

void solve() {
    cin >>n >>c;
    vector<int> s(n);
    rep(i,0,n) {
        cin >>s[i];
    }
    int l = 0, r= c*2;
    ll ans = 0;
    int ct0 = 0,ct1=0;
    rep(i,0,n) {
        if(s[i]%2) {
            ct1++;
        } else {
            ct0++;
        }
    }
    while(l<=r) {
        auto itl = lower_bound(s.begin(),s.end(), l);
        auto itr = upper_bound(s.begin(),s.end(),r);
        if(itr==s.begin() || itl==s.end()) {
            bool even = (l%2)==0;
            ans += f(l, r, ct0, ct1, (int)(1e9), even);
            // debug() <<imie(ct);
            // debug() <<imie(l) <<imie(r);
            break;
        }
        itr--;
        bool even = (l%2)==0;
        int diff;
        if((*itl)-l <= r-(*itr)) {
            ans += f(l,r, ct0, ct1,(*itl)-l, even);
            diff = (*itl)-l;
        } else {
            ans += f(l,r,ct0,ct1,r-(*itr), even);
            diff = r-(*itr);
        }
        // debug() <<imie(l) <<imie(r) <<imie(diff);
        // debug() <<imie((*itr)) <<imie((*itl));
        l += diff;
        r -= diff;
        // if(tot<10) {
        //     tot++;
        //     cout <<l <<" " <<r <<" " <<diff <<"\n" <<flush;
        // }
        while(itl!=s.end() && l==(*itl)) {
            if(l%2) {
                ct1--;
            } else {
                ct0--;
            }
            l++;
            itl++;
        } 
        while(r==(*itr)) {
            if(r%2) {
                ct1--;
            } else {
                ct0--;
            }
            r--;
            if(itr==s.begin()) {
                break;
            } else {
                itr--;
            }
        } 
        while(r>c*2-l) {
            if(c*2-l<=(*itr) && (*itr)<r) {
                r = (*itr)-1;
                if((*itr)%2) {
                    ct1--;
                } else {
                    ct0--;
                }
                if(itr!=s.begin()) itr--;
            } else {
                r = c*2-l;
            }
        }
    }
    cout <<ans <<"\n";
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