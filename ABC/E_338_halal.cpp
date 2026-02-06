#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(2 * n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (a > b) swap(a, b);
        v[a] = {0, i};
        v[b] = {1, i};
    }
    stack<int> st;
    for (int i = 0; i < 2 * n; i++) {
        auto [t, id] = v[i];
        if (!t) {
            st.push(id);
        } else {
            if (st.top() != id) {
                cout << "Yes" << endl;
                return 0;
            }
            st.pop();
        }
    }
    cout << "No" << endl;
}
