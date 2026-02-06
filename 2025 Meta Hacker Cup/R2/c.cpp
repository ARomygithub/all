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

const int mxn=5e5;
int n,k,m,t;

void solve() {
    cin >>n >>k >>m;
    vector a(m, vi());
    rep(i,0,m) {
        int li; cin >>li;
        a[i].resize(li);
        rep(j,0,li) {
            cin >>a[i][j]; a[i][j]--;
        }
    }
    vector tr(n, vector<pii>());
    rep(i,0,m) {
        rep(j,0,sz(a[i])) {
            tr[a[i][j]].push_back({i,j});
        }
    }
    vi dp(n,-1);
    dp[0] = 0;
    queue<int> q;
    q.push(0);
    while(sz(q)) {
        queue<int> q_new;
        set<int> s;
        int cur = -1;
        while(sz(q)) {
            auto u = q.front(); q.pop();
            cur = dp[u]+1;
            for(auto& [tri,id]: tr[u]) {
                rep(j,id+1,id+k+1) {
                    if(j>=sz(a[tri])) break;
                    int val = a[tri][j];
                    if(dp[val]!=-1) break;
                    // dp[val] = dp[u]+1;
                    s.insert(val);
                }
            }
        }
        for(auto& si: s) {
            dp[si] = cur;
            q_new.push(si);
        }
        q.swap(q_new);
    }
    ll ans = 0;
    rep(i,0,n) {
        ans += 1ll*(i+1)*dp[i];
    }
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