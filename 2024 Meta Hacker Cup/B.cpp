#include <bits/stdc++.h>
using namespace std;

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

const int mxn=1e7;
int n,t;
int ans[mxn+1];

void solve() {
    cin >>n;
    if(n<5) {
        cout <<"0\n";
        return;
    }
    cout <<ans[n-2] <<"\n";
}

void init() {
    vector<bool> iscomp(mxn+1,0);
    vi pr;
    rep(i,2,mxn+1) {
        if(!iscomp[i]) {
            pr.push_back(i);
            for(ll j = i*2;j<=mxn;j+=i) {
                iscomp[j] = 1;
            }
        }
    }
    ans[2] = 1;
    rep(i,1,sz(pr)-1) {
        if(pr[i]==pr[i+1]-2) {
            ans[pr[i]] = 1;
        }
    }
    rep(i,1,mxn+1) {
        ans[i] += ans[i-1];
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