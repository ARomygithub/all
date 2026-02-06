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

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e6;
int n;
string s;

struct SuffixTree {
    enum {N = 2*mxn+10, ALPHA=2};
    int toi(char c) {return c-'0';}
    string a;
    int t[N][ALPHA],l[N],r[N],p[N],s[N],v=0,q=0,m=2;
    void ukkadd(int i, int c) { suff:
        if(r[v]<=q) {
            if(t[v][c]==-1) {
                t[v][c] = m;
                l[m] = i;
                p[m++] = v;
                v = s[v];
                q = r[v];
                goto suff;
            }
            v = t[v][c]; q=l[v];
        }
        if(q==-1 || c==toi(a[q])) q++; else {
            l[m+1]=i; p[m+1]=m; l[m]=l[v]; r[m]=q;
            p[m]=p[v]; t[m][c]=m+1; t[m][toi(a[q])]=v;
            l[v]=q; p[v]=m; t[p[m]][toi(a[l[m]])]=m;
            v=s[p[m]]; q=l[m];
            while(q<r[m]) {v=t[v][toi(a[q])]; q+=r[v]-l[v];}
            if(q==r[m]) s[m]=v; else s[m]=m+2;
            q=r[v]-(q-r[m]); m+=2; goto suff;
        }
    }

    SuffixTree(string a) : a(a) {
        fill(r,r+N,sz(a));
        memset(s,0,sizeof s);
        memset(t,-1, sizeof t);
        fill(t[1],t[1]+ALPHA,0);
        s[0]=1; l[0]=l[1]=-1; r[0]=r[1]=p[0]=p[1]=0;
        for(int i=0;i<sz(a);i++) {
            ukkadd(i,toi(a[i]));
        }
    }

    int getLastLexiLen() {
        int ct=0;
        int u=0;
        while(t[u][1]!=-1 || t[u][0]!=-1) {
            if(t[u][1]!=-1) {
                u = t[u][1];
            } else {
                u = t[u][0];
            }
            ct +=r[u]-l[u];
        }
        return ct;
    }
};

void solve() {
    cin >>n;
    cin >>s;
    int l=0, ss=0;
    for(;l<n;l++) {
        if(s[l]=='0') break;
    }
    if(l<n) {
        SuffixTree st(s.substr(l,n-l));
        ss = (n-l) - st.getLastLexiLen();
    } else {
        l = 0;
    }
    cout <<l <<" " <<ss <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}