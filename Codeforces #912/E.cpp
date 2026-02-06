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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,t;
pii s, p[mxn];

void ask(int i) {
    cout <<i <<"\n";
    cout <<flush;
}

int recv() {
    int i; cin >>i;
    if(i!=-1) {
        return i;
    } else {
        exit(0);
    }
}

void solve() {
    cin >>n;
    cin >>s.fi >>s.se;
    set<int> s1,s2;
    rep(i,0,n) {
        cin >>p[i].fi >>p[i].se;
        if((p[i].fi%2)==(p[i].se%2)) {
            s1.insert(i+1);
        } else {
            s2.insert(i+1);
        }
    }
    bool firstA = (s.fi%2)==(s.se%2);
    if(firstA) {
        if(sz(s1)<sz(s2)) {
            //2nd
            cout <<"Second\n";
            cout <<flush;
            while(sz(s1)>0 || sz(s2)>0) {
                int i = recv();
                if(s1.count(i)) {
                    s1.erase(i);
                    if(sz(s1)) {
                        ask(*s1.begin());
                        s1.erase(s1.begin());
                    } else if(sz(s2)) {
                        ask(*s2.begin());
                        s2.erase(s2.begin());
                    }
                } else {
                    s2.erase(i);
                    if(sz(s1)) {
                        ask(*s1.begin());
                        s1.erase(s1.begin());
                    } else if(sz(s2)) {
                        ask(*s2.begin());
                        s2.erase(s2.begin());
                    }
                }
            }
        } else {
            //1st
            cout <<"First\n";
            cout <<flush;
            if(sz(s2)) {
                ask(*s2.begin());
                s2.erase(s2.begin());
            } else if(sz(s1)) {
                ask(*s1.begin());
                s1.erase(s1.begin());
            }
            s1.swap(s2);
            while(sz(s1)>0 || sz(s2)>0) {
                int i = recv();
                if(s1.count(i)) {
                    s1.erase(i);
                    if(sz(s1)) {
                        ask(*s1.begin());
                        s1.erase(s1.begin());
                    } else if(sz(s2)) {
                        ask(*s2.begin());
                        s2.erase(s2.begin());
                    }
                } else {
                    s2.erase(i);
                    if(sz(s1)) {
                        ask(*s1.begin());
                        s1.erase(s1.begin());
                    } else if(sz(s2)) {
                        ask(*s2.begin());
                        s2.erase(s2.begin());
                    }
                }
            }
        }
    } else {
        s1.swap(s2);
        if(sz(s1)<sz(s2)) {
            //2nd
            cout <<"Second\n";
            cout <<flush;
            while(sz(s1)>0 || sz(s2)>0) {
                int i = recv();
                if(s1.count(i)) {
                    s1.erase(i);
                    if(sz(s1)) {
                        ask(*s1.begin());
                        s1.erase(s1.begin());
                    } else if(sz(s2)) {
                        ask(*s2.begin());
                        s2.erase(s2.begin());
                    }
                } else {
                    s2.erase(i);
                    if(sz(s1)) {
                        ask(*s1.begin());
                        s1.erase(s1.begin());
                    } else if(sz(s2)) {
                        ask(*s2.begin());
                        s2.erase(s2.begin());
                    }
                }
            }
        } else {
            //1st
            cout <<"First\n";
            cout <<flush;
            if(sz(s2)) {
                ask(*s2.begin());
                s2.erase(s2.begin());
            } else if(sz(s1)) {
                ask(*s1.begin());
                s1.erase(s1.begin());
            }
            s1.swap(s2);
            while(sz(s1)>0 || sz(s2)>0) {
                int i = recv();
                if(s1.count(i)) {
                    s1.erase(i);
                    if(sz(s1)) {
                        ask(*s1.begin());
                        s1.erase(s1.begin());
                    } else if(sz(s2)) {
                        ask(*s2.begin());
                        s2.erase(s2.begin());
                    }
                } else {
                    s2.erase(i);
                    if(sz(s1)) {
                        ask(*s1.begin());
                        s1.erase(s1.begin());
                    } else if(sz(s2)) {
                        ask(*s2.begin());
                        s2.erase(s2.begin());
                    }
                }
            }
        }        
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