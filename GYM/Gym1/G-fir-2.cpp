#include <bits/stdc++.h>

using namespace std;

#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;


typedef tree<pair<ll, int>,null_type,less<pair<ll, int>>,rb_tree_tag,
tree_order_statistics_node_update> oset;


oset s;
vector<pair<ll, ll>> v;

ll n, k;

void remove(int idx) {
    s.erase({v[idx].se, idx});
}  

void add(int idx) {
    s.insert({v[idx].se, idx});
}

int get_answer(int y){
    auto it = --s.lower_bound({min(y+k-1,n),n+1});
    ll yr = it->first;
    y = max(0ll,yr-(k-1));
    return s.order_of_key({min(y+k-1, n), n+1}) - s.order_of_key({y, 0});
}

int block_size = 1000;

struct Query {
    int l, r, idx;
    ll y;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = 0;
    add(0);
    // invariant: data structure will always reflect the range [cur_l, cur_r]
  for (Query q: queries) {
    while (cur_l > q.l) add(--cur_l);
    while (cur_r < q.r) add(++cur_r);
    while (cur_l < q.l) remove(cur_l++);
    while (cur_r > q.r) remove(cur_r--);
    answers[q.idx] = get_answer(q.y);
  }
    return answers;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> n >> m >> k;
    vector<array<ll, 3>> a(m);

    for(int i=0; i<m; i++){
        cin >> a[i][0] >> a[i][1];
        v.pb({a[i][0], a[i][1]});
    }

    sort(a.begin(), a.end());
    sort(v.begin(), v.end());
    for(int i=0; i<m; i++){
        a[i][2] = i;
    }
    vector<Query> q;
    for(int i=0; i<m; i++){
        auto it = --lower_bound(v.begin(), v.end(), make_pair(min(v[i].fi + k-1, n), n+1));
        ll ir = it->first;
        ll il = max(0ll,ir-(k-1)); 
        int ild = lower_bound(v.begin(), v.end(), make_pair(il, 0ll)) - v.begin();
        int id = it - v.begin();
        // if(id < i){
        //     id = i;
        // }
        q.push_back({ild, id, i, v[i].se});
    }


    vector<int> ans = mo_s_algorithm(q);




    int res = 0;
    for(int i=0; i<m; i++){
        res = max(res, ans[i]);
    }
    cout << res << "\n";

    return 0;
}