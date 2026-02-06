using namespace std;
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int otoriter(string s) {
    if(s == "cipherpol") return 0;
    else if(s == "vegapunk") return 1;
    else return 2;
}

string aksi(int state) {
    return state ? "serang" : "berhenti";
}

int status(string aksi) {
    return aksi == "serang";
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int state = -1;
    int last_otoriter = -1;
    int stop = 0;
    string last = "";
    bool mode = ((rng()%2) == 0);
    for(int i=0; i<n; i++) {
        string s, t;
        cin >> s >> t;
        if(stop) continue;
        int otor = otoriter(s);
        int act = status(t);
        if(otor >= last_otoriter) {
            if(act == 0 && last == "") {
                cout << "Pacifista ngambek karena belum diperintah tetapi sudah disuruh berhenti!\n";
                stop = 1;
            } else if(state != act || last == "") {
                cout << "Pacifista " << t <<" sesuai dengan keinginan " << s <<".\n";
                state = act;
                last = s;
                last_otoriter = otor;
            } else  {
                cout << "Pacifista sudah diperintah untuk " << t <<" oleh " << last << ".\n";
                // if(mode) {
                    // last = s;
                    // last_otoriter = otor;
                // }
            } 
        } else {
            cout << "Pacifista tidak nurut karena wewenang "<< s << " lebih rendah dari " <<last << ".\n";
        }
    }
    return 0;
}
