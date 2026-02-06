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
int t;
const int n=6,m=7;
vector<string> s(n);
set<char> sc;
ll sp[m+1];
vector<bool> vis;

void chk(vi& st, int p) {
    ll stn = 0;
    rep(j,0,m) {
        stn += sp[j]*st[j];
    }
    if(vis[stn]) return;
    vis[stn] = 1;
    if(sz(sc)==2) return;
    // debug() <<imie(st);
    char cur = p==0?'C':'F';
    auto e = [=](int x, int y) -> bool {
        return x>=0&&x<n&&y>=0&&y<m&&s[x][y]==cur && st[y]>n-1-x;
    };
    auto isWin = [&](int x, int y, pii v) -> bool {
        int tmp = 1;
        int i = x, j = y;
        while(tmp<4 && e(i-v.fi,j-v.se)) {
            i -= v.fi;
            j -= v.se;
            tmp++;
        }
        i = x, j = y;
        while(tmp<4 && e(i+v.fi,j+v.se)) {
            i += v.fi;
            j += v.se;
            tmp++;
        }
        // debug() <<imie(tmp);
        if(tmp>=4) {
            return 1;
        } else {
            return 0;
        }
    };
    rep(j,0,m) {
        if(st[j]<n && s[n-1-st[j]][j]==cur) {
            if(isWin(n-1-st[j],j, {1,0}) || isWin(n-1-st[j],j,{1,1}) || isWin(n-1-st[j],j,{1,-1}) || isWin(n-1-st[j],j,{0,1})) {
                sc.insert(cur);
            } else {
                st[j]++;
                chk(st, 1-p);
                st[j]--;
            }
        }
    }
}

void init() {
    sp[0] = 1;
    rep(i,1,m+1) {
        sp[i] = sp[i-1]*7;
    }
    vis.resize(sp[m],0);    
}

void solve() {
    rep(i,0,n) {
        cin >>s[i];
    }
    // debug() <<imie(s);
    vi st(m,0);
    sc.clear();
    rep(i,0,sp[m]) {
        vis[i] = 0;
    }
    chk(st, 0);
    if(sz(sc)==2) {
        cout <<"?\n";
    } else if(sz(sc)==0) {
        cout <<"0\n";
    } else {
        cout <<(*sc.begin()) <<"\n";
    }
}

void main_() {
    // implement your solution here
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init();
    for(int i=1;i<=t;i++) {
        cout <<"Case #" <<i <<": ";
        solve();
    }    
}

static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%rsp, (%0)\n"
        "mov %0, %%rsp\n"
        :
        : "r"(send));
    func();
    asm volatile("mov (%0), %%rsp\n" : : "r"(send));
    free(stack);
}

int main() {
    run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
    return 0;
}