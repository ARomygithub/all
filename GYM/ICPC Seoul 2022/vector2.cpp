/*
    created : 2024-09-01 22:37:11
*/
#include <bits/stdc++.h>

using namespace std;

#define int64 int64_t

// #ifdef LOCAL
// #include "Library/debug.h"
// #else
// #define debug(...) 42
// #endif

template <class T> auto vect(const T& v, int n) { return vector<T>(n, v); }
template <class T, class... D> auto vect(const T& v, int n, D... m) {
  return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}

const int N = 2e5 + 5;
// int suff[N][26][2], pref[N][26][2];
vector suff(N, vector(26, vector<int>(2,0)));
vector pref(N, vector(26, vector<int>(2,0)));

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        string s; cin >> s;
        bool can = true;
        if(n % 2 == 0) {
            // no hapus;
            int ans = 0;
            for(int i = 0; i < 2; ++i) {
                vector<int>cnt(26, 0);
                for(int j = i; j < n; j += 2) {
                    cnt[s[j] - 'a']++;
                }
                sort(cnt.begin(), cnt.end(), greater<int>());
                for(int j = 1; j < 26; ++j) {
                    ans += cnt[j];
                }
                //debug(cnt);
            }
            cout << ans << '\n';
        } else {
            for(int i = n - 1; i >= 0; i--) {
                for(int c = 0; c < 26; ++c) {
                    for(int j = 0; j < 2; ++j) suff[i][c][j] = suff[i + 1][c][j];
                }
                suff[i][s[i] - 'a'][i % 2]++;
            }
            // tiap i consider buat hapus;
            int ans = 1e9;
            for(int i = 0; i < n; ++i) {
                int ret = 1;
                for(int j = 0; j < 2; ++j) {
                    vector<int>cnt(26, 0);
                    for(int c = 0; c < 26; ++c) {
                        cnt[c] += suff[i + 1][c][j];
                    }
                    if(i) {
                        for(int c = 0; c < 26; ++c) {
                            int z = j == 0 ? 1 : 0;
                            cnt[c] += pref[i - 1][c][z];
                        }
                        sort(cnt.begin(), cnt.end(), greater<>());
                        for(int c = 1; c < 26; ++c) {
                            ret += cnt[c];
                        }
                        //debug(cnt, temp);
                    } else {
                        sort(cnt.begin(), cnt.end(), greater<>());
                        for(int c = 1; c < 26; ++c) {
                            ret += cnt[c];
                        }
                    }
                }
                //debug(ret);
                ans = min(ans, ret);
                if(i) {
                    for(int c = 0; c < 26; ++c) {
                        for(int j = 0; j < 2; ++j) pref[i][c][j] = pref[i - 1][c][j];
                    }
                }
                pref[i][s[i] - 'a'][i % 2]++;
            }
            for(int i = 0; i <= n; ++i) {
                for(int j = 0; j < 26; ++j) {
                    for(int k = 0; k < 2; ++k) {
                        pref[i][j][k] = 0;
                        suff[i][j][k] = 0;
                    }
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}