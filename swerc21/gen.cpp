#include <bits/stdc++.h>
using namespace std;

mt19937 rng(1234567);

int rnd(int l, int r) { return l + (int)(rng() % (r - l + 1)); }

string genCircular() {
    int r = rnd(1,20);
    int a = rnd(0,359);
    int b = rnd(0,359);
    while (b == a) b = rnd(0,359);
    return "C " + to_string(r) + " " + to_string(a) + " " + to_string(b);
}

string genStraight() {
    int r1 = rnd(1,19);
    int r2 = rnd(r1+1,20);
    int th = rnd(0,359);
    return "S " + to_string(r1) + " " + to_string(r2) + " " + to_string(th);
}

// Run an executable with given input, capture stdout.
string runProgram(const string &exe, const string &input) {
    // Write input to a temp file
    const string inFile = "curr_input.txt";
    const string outFile = "curr_output.txt";
    {
        ofstream ofs(inFile);
        ofs << input;
    }
    // Build command (Windows needs .exe)
#ifdef _WIN32
    string cmd = exe + " < " + inFile + " > " + outFile;
#else
    string cmd = "./" + exe + " < " + inFile + " > " + outFile;
#endif
    int code = system(cmd.c_str());
    if (code != 0) {
        cerr << "Execution failed for " << exe << " (exit code " << code << ")\n";
        exit(1);
    }
    ifstream ifs(outFile);
    string out((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
    return out;
}

int main() {
    // Adjust iterations if needed
    for (int iter = 1; iter <= 50000; ++iter) {
        int n = rnd(1, 30); // keep small for easier manual analysis
        vector<string> lines;
        int cCircular = rnd(0, n);
        for (int i = 0; i < cCircular; ++i) lines.push_back(genCircular());
        while ((int)lines.size() < n) lines.push_back(genStraight());

        // Assemble test case (t=1)
        stringstream ss;
        ss << 1 << "\n" << n << "\n";
        for (auto &s : lines) ss << s << "\n";
        string input = ss.str();

        string outRef = runProgram("ref.exe", input);
        string outMine = runProgram("mine.exe", input);

        if (outRef != outMine) {
            cout << "Mismatch found at iteration " << iter << "\n";
            cout << "Test case:\n" << input;
            cout << "ref.exe output:\n" << outRef;
            cout << "mine.exe output:\n" << outMine;
            return 0;
        }
    }
    cout << "No mismatch found in allotted iterations.\n";
    return 0;
}