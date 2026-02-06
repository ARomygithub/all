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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<string> vs;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        vs.push_back(s);
    }
    if(n == 1) {
        cout << 300*1000 << "\n";
    } else {
        sort(vs.begin(), vs.end());
        vector<array<int, 2>> px;
        vector<int> col(n);
        int j = 0;
        vector<int> vis(100,0);
        for(int i=0; i<n; i++) {
            string cs = vs[i].substr(0, 2);
            int dig = (cs[0]-'0')*10 + (cs[1]-'0');
            vis[dig] = 1;
            int cnt = 0;
            while(i<n && cs == vs[i].substr(0, 2)) {
                col[i] = j;
                i++;
                cnt++;
            }
            px.push_back({cnt, 0});
            if(i < n) {
                i--;
            }
            j++;
        }

        for(int i=0; i<n; i++) {
            int cl = col[i];
            string cs = vs[i].substr(0, 4);
            int cnt = 0;
            while(i<n && col[i] == cl && vs[i].substr(0, 4) == cs) {
                cnt++;
                i++;
            }
            px[cl][1] = max(px[cl][1], cnt);
            i--;
        }

        multiset<int> ms;
        ll sum = 0;
        for(int i=0; i<px.size(); i++) {
            ms.insert(px[i][0]);
            sum += px[i][0];
        }
        if(px.size() == 1) {
            cout << max(300*1000, max(500*px[0][0], 4000*px[0][1]));
        } else{
            // cout << cn << "\n";
            ll ans = 0;
            rep(i1,0,sz(px)) {
                rep(i2,0,sz(px)) {
                    if(i1==i2) continue;
                    ll temp = 0;
                    auto [a1, b1] = px[i1];
                    auto [a2, b2] = px[i2];
                    if(sz(px)>=5) {
                        ms.erase(ms.find(a1));
                        ms.erase(ms.find(a2));
                        auto it = --ms.end();
                        rep(k,0,3) {
                            temp += 1ll*(*it)*500;
                            it--;
                        }
                        ms.insert(a1);
                        ms.insert(a2);
                        temp += 3e5;
                        temp += 1ll*4000*b2;
                    } else if(sz(px)==4) {
                        ll mn1 = 3e5, mx1 = max(mn1, 500ll*a1);
                        ll mn2 = 4000ll*b2, mx2 = max(mn2, 500ll*a2);
                        ll temp2 = (sum-a1-a2)*500;
                        temp = max(mn1+mx2,mx1+mn2) + temp2; 
                    } else {
                        temp += max((int)(3e5),500*a1);
                        temp += max(1ll*4000*b2, 1ll*500*a2);
                        temp += (sum-a1-a2)*500;
                    }
                    max_self(ans,temp);
                }
            } 
            // for(auto [a, b]: px) {
            //     // cout << a << " " << b << "\n";
            //     int mn1 = *ms.begin();
            //     ms.erase(ms.find(a));
            //     int mn = *ms.begin();

            //     ll cur = 300000 - mn*500;
            //     ll cur2 = b*4000 - a*500;
            //     ll cur3 = 300000 - mn1*500;

            //     ans = max(ans, sum + cur + cur2);
            //     // if(cn >= 1) {
            //         ans = max(ans, sum + cur2);
            //         ans = max(ans, sum + cur3);
            //     // }
            //     // if(cn >= 2) {
            //         ans = max(ans, sum);
            //     // }
            //     ms.insert(a);
            // }


            cout << ans << "\n";
        }
    }

    return 0;
}