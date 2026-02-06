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

const int mxn=3e5;
int n,q,t;
string s;

void solve() {
    cin >>n >>q;
    cin >>s;
    int sm = 0;
    int ct1 = 0, ct5 = 0, ctb=0;
    int ctlen = 0;
    int min1 = 0;
    map<char,int> mp;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['I'] = 1;
    int len = 0;
    for(int i=0;i<n;) {
        if(s[i]!='?') {
            if(s[i]=='I' && i+1<n && (s[i+1]=='V' || s[i+1]=='X')) {
                min1++;
            }
            sm += mp[s[i]];
            i++;
            continue;
        }
        int j = i;
        while(j<n && s[j]=='?') {
            j++;
        }
        int cur = j-i;
        if(i>0 && s[i-1]=='I') {
            ct1++;
            cur--;
        }
        if(j<n && s[j]!='I') {
            ct5++;
            cur--;
        }
        if(cur==-1) {
            ctb++;
            ct1--;
            ct5--;
            cur = 0;
        }
        len += (j-i);
        ctlen += cur/2;
        i = j;
    }
    // debug() <<imie(ct1) imie(ct5) imie(ctb);
    while(q--) {
        int x,v,i; cin >>x >>v >>i;
        int clen = len;
        i = min(i,clen);
        clen -= i;
        v = min(v,clen);
        clen -= v;
        x = min(x,clen);
        int cur = sm + i + v*5 + x*10;
        int cmin1 = min1;
        v += x;
        int temp = min(ct1,v);
        cmin1 += temp;
        v -= temp;
        temp = min(ct5, i);
        cmin1 += temp;
        i -= temp;
        int ctbb = ctb;
        if(i>=v) {
            temp = min(i-v, ctbb);
            cmin1 += temp;
            i -= temp;
            ctbb -= temp;
        } else {
            temp = min(v-i, ctbb);
            cmin1 += temp;
            v -= temp;
            ctbb -= temp;
        }
        // debug() <<imie(cmin1) imie(cur);
        int bw = ctbb/2, ats = ctbb-bw;
        // debug() <<imie(bw) imie(ats);
        // debug() <<imie(i) imie(v);
        temp = min(i,bw);
        cmin1 += temp;
        i -= temp;
        temp = min(v,ats);
        cmin1 += temp;
        v -= temp;
        temp = min(min(i,v), ctlen);
        cmin1 += temp;
        cout <<cur -cmin1*2 <<"\n";
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