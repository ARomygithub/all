#include "testlib.h"
#include <vector>
using namespace std;

const int MAXN = 200000;
const int MAXQ = 200000;

int main(int argc, char **argv) {
    registerValidation(argc, argv);
    int n = inf.readInt(2, MAXN, "n");
    inf.readEoln();
    vector<int> A(n+1), B(n+1), C(n+1);
    for(int i=0; i<n; i++){
    	int a = inf.readInt(1, n);
    	inf.readSpace();
    	int b = inf.readInt(1, n);
    	inf.readSpace();
    	int c = inf.readInt(1, n);
    	inf.readEoln();
    	ensuref(!A[a] && !B[b] && !C[c], "non-distinct ranks");
    	A[a] = B[b] = C[c] = true;
    }
    int q = inf.readInt(1, MAXQ, "q");
    inf.readEoln();
    while(q--){
    	int a = inf.readInt(1, n);
    	inf.readSpace();
    	int b = inf.readInt(1, n);
    	inf.readEoln();
    	ensuref(a != b, "a = b in question");
    }
    inf.readEof();
    return 0;
}
