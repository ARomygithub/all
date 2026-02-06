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

const int mxn=1e5;
int n;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    } 

    map<pii,int> m;
    vector<int> cnt(32), cnt1(32);
    for(int i = n - 1; i >= 0; --i){
        int cur = 0;
        for(int j = 31; j >= 0; --j){
            if(a[i] >> j & 1) cur += (1LL << j);
            if(j - 1 >= 0 && ((a[i] >> (j - 1) & 1) == 0)){
                cnt1[j - 1] += m[{j - 1, cur + (1LL << (j - 1))}];
            }
            if(j - 1 >= 0 && ((a[i] >> (j - 1) & 1) == 1)){
                cnt[j - 1] += m[{j - 1, cur}];
            }
        }
        cur = 0;
        for(int j = 31; j >= 0; --j){
            if(a[i] >> j & 1) cur += (1LL << j);
            m[{j, cur}]++;
        }
    }

    int x = 0;
    int inv = 0;
    for(int i = 0; i <= 30; ++i){
        if(cnt[i] < cnt1[i]){
            inv += cnt[i];
        }
        else{
            if(cnt[i] > cnt1[i]) x += (1LL << i);
            inv += cnt1[i];
        }
    }
    cout << inv << " " << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}