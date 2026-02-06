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

const int mxn=300;
int n,a,b,t;
map<pii,int> mp4;

string div2(string& x) {
    string ret = "";
    int cr = 0;
    rep(i,0,sz(x)) {
        int cur = (x[i]-'0')+cr;
        if(cur>=2 || i>0) {
            ret += (char)('0'+ (cur/2));
        }
        cr = (cur%2)==1?10:0;
    }
    // debug() <<imie(x) imie(ret);
    return ret;
}

string add(string& s1, string& s2) {
    string ret = "";
    reverse(all(s1));
    reverse(all(s2));
    int id = 0;
    int cr = 0;
    while(id<max(sz(s1),sz(s2))) {
        int cur = cr;
        if(id<sz(s1)) {
            cur += (s1[id]-'0');
        }
        if(id<sz(s2)) {
            cur += (s2[id]-'0');
        }
        ret += (char)('0' + (cur%10));
        cr = cur/10;
        id++;
    }
    while(cr) {
        ret += (char)('0' + (cr%10));
        cr /= 10; 
    }
    reverse(all(ret));
    return ret;
}

void solve() {
    cin >>n >>a >>b;
    if(n<4) {
        int ad = (1<<n);
        int ats = 1;
        rep(i,0,n-1) {
            ats *= 10;
        }
        auto cek = [&](int x) -> bool {
            bool ok = 1;
            while(x) {
                int cur = x%10;
                ok = ok && ( (cur==a) || (cur==b));
                x /= 10;
            }
            return ok;
        };
        int u = ad;
        while(u<ats*10) {
            if(u>=ats) {
                if(cek(u)) {
                    cout <<u <<"\n";
                    return;
                }
            }
            u += ad;
        }
        cout <<"-1\n";
        return;
    }

    if(!mp4.count({a,b})) {
        cout <<"-1\n";
        return;
    }
    string u = to_string(mp4[{a,b}]);
    reverse(all(u));
    string r = to_string(mp4[{a,b}]/16);
    rep(i,5,n+1) {
        string cur = "";
        rep(j,0,i) {
            cur += '0';
        }
        if((r.back()-'0')%2) {
            u += (char)(a+'0');
            cur[0] = (char)(a+'0');
        } else {
            u += (char)(b+'0');
            cur[0] = (char)(b+'0');
        }
        // debug() <<imie(cur);
        rep(j,0,i-1) {
            cur = div2(cur);
        }
        // debug() <<imie(cur);
        r = add(r, cur);
        // debug() <<imie(r);
        r = div2(r);
        // debug() <<imie(r);
    }
    reverse(all(u));
    cout <<u <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    int ad = (1<<4);
    int ats = 1000;
    int u = ad;
    auto cek = [&](int x) -> pii {
        pii ret = {-1,-1};
        set<int> s;
        while(x) {
            int cur = x%10;
            x /= 10;
            s.insert(cur);
        }
        if(sz(s)==2) {
            int aa = *s.begin();
            int bb = *(++s.begin());
            if(((aa+bb)%2) == 1) {
                if((aa%2)) {
                    ret = {aa,bb};
                } else {
                    ret = {bb,aa};
                }
            }
        }
        return ret;
    };
    while(u<ats*10) {
        if(u>=ats) {
            pii ab = cek(u);
            if(ab.fi!=-1) {
                mp4[ab] = u;
            }
        }
        u += ad;
    }
    while(t--) {
        solve();
    }
}