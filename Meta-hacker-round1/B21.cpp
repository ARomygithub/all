#include <bits/stdc++.h>
using namespace std;

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

const int mxn=1e5;
int p,t;

vector<int> apply(int bts, int _p, int sum) {
    if(_p==1) {
        vector<int> ret(sum,1);
        return ret;
    }
    vector<int> ans;
    int szi = 1e9;
    for(int i=bts;i>=2;i--) {
        if((_p%i)!=0) continue;
        if(i>sum) continue;
        if(i==sum) {
            if(i==_p) {
                vector<int> ret(1,i);
                return ret;
            } else {
                continue;
            }
        }
        int temp=0;
        int pi=_p/i;
        for(int j=2;1ll*j*j<=pi;j++) {
            if((pi%j)==0) {
                while((pi%j)==0) {
                    temp +=j;
                    pi /=j;
                }
            }
        }
        if(pi>1) {
            temp +=pi;
        }
        if(i+temp>sum) continue;
        vector<int> ret2 = apply(i,_p/i,sum-i);
        // if(i==16) {
        //     cout <<sz(ret2) <<"\n";
        //     for(auto ret2i : ret2) {
        //         cout <<ret2i <<" ";
        //     }
        //     cout <<"\n";
        //     cout <<szi <<"\n";
        // }
        if(sz(ret2)==0) continue;
        ret2.push_back(i);
        // return ret2;
        if(sz(ret2)<szi) {
            // cout <<bts <<" " <<_p <<" " <<sum <<"\n";
            szi = sz(ret2);
            ans.swap(ret2);
        }
    }
    return ans;
}

void solve() {
    cin >>p;
    int _p = p;
    vector<int> ans;
    int sum=0;
    for(int i=2;1ll*i*i<=p;i++) {
        if((p%i)==0) {
            while((p%i)==0) {
                ans.push_back(i);
                sum +=i;
                p /=i;
            }
        }
    }
    if(p>1) {
        ans.push_back(p);
        sum +=p;
    }
    if(sum<=41) {
        ans = apply(41,_p,41);
        // ans.clear();
        // while(sz(pq)) {
        //     ans.push_back(pq.top()); pq.pop();
        // }
        // int ct1 = 41-sum;
        // for(int i=0;i<ct1;i++) {
        //     ans.push_back(1);
        // }
        cout <<sz(ans) <<" ";
        for(int i=0;i<sz(ans);i++) {
            cout <<ans[i] <<" \n"[i==sz(ans)-1];
        }
    } else {
        cout <<"-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    for(int i=1;i<=t;i++) {
        cout <<"Case #" <<i <<": ";
        solve();
    }
}