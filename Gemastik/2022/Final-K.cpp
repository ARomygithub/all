#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
map<string,char> mp = {{"NN",'S'}, {"VB", 'P'}, {"RB",'K'}, {"CC",'C'}};
set<string> s = {"SP", "SPK", "SPS", "SPSK"};
int n;
map<string,char> mpk;

void solveLine(string line) {
    string endPattern = "";
    for(int i=0;i<line.length();) {
        string kata="";
        while(i<line.length() && line[i]!=' ') {
            kata +=line[i];
            i++;
        }
        char c = mpk.find(kata)!=mpk.end()?mpk[kata]:'S';
        if(c=='C') {
            if(s.find(endPattern)!=s.end()) {
                endPattern = "";
            } else {
                cout <<"tidak dapat diterima\n";
                // cout <<endPattern <<"\n";
                cout <<flush;
                return;
            }
        } else {
            endPattern +=c;
        }
        i++;
    }
    if(s.find(endPattern)!=s.end()) {
        cout <<"dapat diterima\n";
    } else {
        cout <<"tidak dapat diterima\n";
        // cout <<endPattern <<"\n";
    }
    cout <<flush;
}

void solve() {
    cin >>n;
    for(int i=0;i<n;i++) {
        string kata, label; cin >>kata >>label;
        mpk[kata] = mp[label];
    }
    char c; cin >>c;
    string line;
    while(getline(cin, line)) {
        solveLine(line);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}