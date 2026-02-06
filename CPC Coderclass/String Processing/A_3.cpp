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
string s;

array<vi, 2> manacher(const string& s) {
    int n = sz(s);
    array<vi,2> p = {vi(n+1), vi(n)};
    rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
        int t = r-i+!z;
        if (i<r) p[z][i] = min(t, p[z][l+t]);
        int L = i-p[z][i], R = i+p[z][i]-!z;
        while (L>=1 && R+1<n && s[L-1] == s[R+1])
            p[z][i]++, L--, R++;
        if (R>r) l=L, r=R;
    }
    return p;
}

void solve() {
    cin >>n;
    cin >>s;
    bool pali = 1;
    for(int i=0,j=n-1-i;i<=j;i++,j--) {
        if(s[i]!=s[j]) {
            pali = 0;
            break;
        }
    }
    if(pali) {
        cout <<n <<"\n";
        return;
    }
    auto man = manacher(s);
    vector<int> pal(n,0);
    vector<pii> v;
    rep(i,0,n+1) {
        int li = i-man[0][i], ri=i+man[0][i]-1;
        if(li<ri) {
            v.push_back({li,i});
        }
    }
    sort(v.begin(),v.end());
    set<int> st;
    int iv = 0;
    rep(i,0,n) {
        while(iv<sz(v) && v[iv].fi==i) {
            st.insert(v[iv].se);
            iv++;
        }
        int mxmid = (n-1)/2;
        auto it = st.upper_bound(mxmid);
        if(it!=st.begin()) {
            it--;
            if((*it)>i) {
                max_self(pal[i], ((*it)-i)*2);
            }
        }
    }
    v.clear();
    rep(i,0,n+1) {
        int li=i-man[0][i], ri=i+man[0][i]-1;
        if(li<ri) {
            v.push_back({ri,i});
        }
    }
    sort(v.begin(),v.end(),greater<pii>());
    st.clear();
    iv = 0;
    rep(i,0,n) {
        while(iv<sz(v) && v[iv].fi==n-1-i) {
            st.insert(v[iv].se);
            iv++;
        }
        int mnmid = (n)/2 + 1;
        auto it = st.lower_bound(mnmid);
        if(it!=st.end()) {
            if(n-i-1 >= (*it)) {
                max_self(pal[i], ((n-i-1) - (*it)+1)*2);
            }
        }
    }
    v.clear();
    rep(i,0,n) {
        int li = i-man[1][i], ri=i+man[1][i];
        if(li<=ri) {
            v.push_back({li,i});
        }
    }
    sort(v.begin(),v.end());
    st.clear();
    iv = 0;
    rep(i,0,n) {
        while(iv<sz(v) && v[iv].fi==i) {
            st.insert(v[iv].se);
            iv++;
        }
        int mxmid = (n-2)/2;
        auto it = st.upper_bound(mxmid);
        if(it!=st.begin()) {
            it--;
            if((*it)>=i) {
                max_self(pal[i], ((*it)-i)*2+1);
            }
        }
    }
    v.clear();
    rep(i,0,n) {
        int li = i-man[1][i], ri=i+man[1][i];
        if(li<=ri) {
            v.push_back({ri,i});
        }
    }
    sort(v.begin(),v.end(),greater<pii>());
    st.clear();
    iv = 0;
    rep(i,0,n) {
        while(iv<sz(v) && v[iv].fi==n-1-i) {
            st.insert(v[iv].se);
            iv++;
        }
        int mnmid = (n-1)/2 + 1;
        auto it = st.lower_bound(mnmid);
        if(it!=st.end()) {
            if((*it)<=n-1-i) {
                max_self(pal[i], 2*(n-1-i-(*it))+1);
            }
        }
    }
    int ans = 0;
    for(int i=0,j=n-1;i<=j;i++,j--) {
        max_self(ans, i*2+pal[i]);
        if(s[i]!=s[j]) break;
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}