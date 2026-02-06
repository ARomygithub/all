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

const int mxn=1e6;
int n,m,t;
int a[mxn],b[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,m) {
        cin >>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    vi v;
    int inf = -1;
    rep(i,0,n) {
        if(a[i]!=inf) {
            v.push_back(i);
            inf = a[i];
        }
    }
    int ans = 0;
    int le = 0, ri = sz(v)-1;
    // while(le<=ri) {
    //     int mid = (le+ri)/2;
        // debug() <<imie(le) imie(ri) imie(mid);
        // bool dbg = mid==85893;
        int mid = 85893;
        bool ok = 1;
        vi c(m,0);
        int k = m-1;
        per(i,sz(v)-1,mid-1) {
            int ct = (i+1<sz(v)?v[i+1]:n) - v[i];
            int hd = i-(mid-1);
            rep(j,0,ct) {
                rep(ki,0,hd) {
                    c[k]++;
                    if(c[k]>b[k]) {
                        ok = 0;
                        break;
                    }
                    k = (k-1+m)%m;
                }
                if(!ok) {
                    break;
                }
            }
            if(!ok) break;
        }
        if(ok) {
            ans = n - v[mid];
            ri = mid-1;
        } else {
            le = mid+1;
        }
    // }
    cout <<ans <<"\n";
}

void main_() {
    // implement your solution here
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
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