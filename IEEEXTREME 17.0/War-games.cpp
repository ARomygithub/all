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
map<char,int> mp;

void solve() {
    string l1;
    string l2;
    getline(cin,l1);
    getline(cin,l2);
    stringstream ss1(l1);
    stringstream ss2(l2);
    vector<char> v1,v2;
    char c1,c2;
    while(ss1 >> c1) {
        v1.push_back(c1);
    }
    while(ss2 >> c2) {
        v2.push_back(c2);
    }
    // rep(i,0,sz(v1)) {
    //     cout <<v1[i] <<" \n"[i==sz(v1)-1];
    // }
    set<int> s;
    int last=0;
    while(true) {
        int sawal = sz(v1)+sz(v2);
        vector<char> v1_new,v2_new;
        // rep(i,0,sz(v1)) {
        //     cout <<v1[i] <<" \n"[i==sz(v1)-1];
        // }
        // rep(i,0,sz(v2)) {
        //     cout <<v2[i] <<" \n"[i==sz(v2)-1];
        // }
        rep(i,min(sz(v1),sz(v2)),sz(v1)) {
            v1_new.push_back(v1[i]);
        }
        rep(i,min(sz(v1),sz(v2)),sz(v2)) {
            v2_new.push_back(v2[i]);
        }
        rep(i,0,min(sz(v1),sz(v2))) {
            if(mp[v1[i]]==mp[v2[i]]) {
                v1_new.push_back(v1[i]);
                v2_new.push_back(v2[i]);
            } else if(mp[v1[i]]>mp[v2[i]]) {
                v1_new.push_back(v2[i]);
            } else {
                v2_new.push_back(v1[i]);
            }
        }
        v1.swap(v1_new);
        v2.swap(v2_new);
        if(sz(v1)==0) {
            cout <<"player 2\n";
            return;
        }
        if(sz(v2)==0) {
            cout <<"player 1\n";
            return;
        }
        if(sz(v1)+sz(v2)==sawal) {
            if(s.find(last)!=s.end()) {
                cout <<"draw\n";
                return;
            } else {
                s.insert(last);
                last = (last+min(sz(v1),sz(v2)))%max(sz(v1),sz(v2));
            }
        } else {
            s.clear();
            last = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    getline(cin,s);
    stringstream ss(s);
    ss >>t;
    rep(i,2,10) {
        mp[(char)(i+'0')] = i;
    }
    mp['T'] = 10;
    mp['J'] = 11;
    mp['Q'] = 12;
    mp['K'] = 13;
    mp['A'] = 14;
    while(t--) {
        solve();
    }
}