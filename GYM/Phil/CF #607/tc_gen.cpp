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

vector<pair<int, int>> pruefer_decode(vector<int> const& code) {
    int n = code.size() + 2;
    vector<int> degree(n, 1);
    for (int i : code)
        degree[i]++;

    int ptr = 0;
    while (degree[ptr] != 1)
        ptr++;
    int leaf = ptr;

    vector<pair<int, int>> edges;
    for (int v : code) {
        edges.emplace_back(leaf, v);
        if (--degree[v] == 1 && v < ptr) {
            leaf = v;
        } else {
            ptr++;
            while (degree[ptr] != 1)
                ptr++;
            leaf = ptr;
        }
    }
    edges.emplace_back(leaf, n-1);
    return edges;
}

int rand(int a, int b) {
    return a + rand()%(b-a+1);
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(atoi(argv[1])); //atoi convert string to int
    cout <<"1\n";
    int n = 10;
    int m = rand(1,n);
    vector<int> b(n), w(n);
    rep(i,0,n) {
        b[i] = rand(0,n);
        w[i] = rand(0,n);
    }
    cout <<n <<" " <<m <<"\n";
    rep(i,0,n) {
        cout <<b[i] <<" \n"[i==n-1];
    }
    rep(i,0,n) {
        cout <<w[i] <<" \n"[i==n-1];
    }
    vector<int> code(n-2);
    for(int i=0;i<n-2;i++) {
        code[i] = rand(0, n-1);
    }
    vector<pair<int,int>> edges = pruefer_decode(code);
    for(auto [u,v] : edges) {
        cout <<u+1 <<" " <<v+1 <<"\n";
    }
}