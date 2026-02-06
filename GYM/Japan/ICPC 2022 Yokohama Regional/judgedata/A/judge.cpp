#include<stdio.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

string readline_rstrip(ifstream &ifs) {
    string line;
    getline(ifs, line);

    while (!line.empty()) {
        if (line.back() == ' '
                || line.back() == '\n' 
                || line.back() == '\t'
                || line.back() == '\r') {
            line.erase(line.end()-1);
        } else {
            break;
        }
    }
    return line;
}

map<string, int> date_map;

// 1 ~ 31 に完全一致した整数を読み取る。末尾の空白は許される。
int readdate(ifstream &ifs) {
    string line = readline_rstrip(ifs);

    auto it = date_map.find(line);

    if (it == date_map.end()) {
        printf("wa : output line is not a valid date.(line = %s)\n", line.c_str());
        exit(-1);
    }

    return it->second;
}

void initialize() {
    for (int i=1; i<=31; i++) {
        date_map[to_string(i)] = i;
    }
}

int main(int argc, char* argv[]) {
    initialize();

    ifstream input(argv[1]);

    // Read input file;
    int N, K;
    input >> N >> K;

    vector<int> A(N);
    vector<int> B(N);

    for (int i=0; i<N; i++) {
        input >> A[i] >> B[i];
    }
    input.close();

    // Read contestans' output data without testlib.
    ifstream output(argv[2]);
    assert(output);

    // Read output file;
    vector<int> date(N);
    for (int i=0; i<N; i++) {
        if (output.eof()) {
            puts("wa : output file has less n lines.");
            return -1;
        }
        date[i] = readdate(output);
    }

    if (!output.eof()) {
        string line;
        getline(output, line);
        // 最後の改行 (n個目の改行) のあとに文字があると wa
        if (!line.empty() || !output.eof()) {
            printf("wa : output file has more n lines. (line = %s)", line.c_str());
            return -1;
        }
    }
    output.close();

    vector<int> cnt(32);
    for (int i=0; i<N; i++) {
        if (date[i] < A[i] || B[i] < date[i]) {
            puts("wa : the date must be in the range a_i to b_i.");
            return -1;
        }

        cnt[date[i]]++;

        // 1日に配る回数は K 回までで有ることをチェック
        if (cnt[date[i]] > K) {
            puts("wa : the number of deliveries should be k or less.");
            return -1;
        }
    }

    // quitf(_ok, "ok");
    return 0;
}
