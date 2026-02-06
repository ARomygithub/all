#include <bits/stdc++.h>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <set>
#include <locale>
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
typedef vector<int> vi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

/**
 * @param n The number of buildings
 * @param building_map Representation of the n buildings
 * @return The height of each building.
 */
vector<int> buildingHeights(int n, vector<string> building_map) {
  // Write your code here
    assert(n==sz(building_map));
    vector<int> ret(n,0);
    rep(i,0,n) {
        string cur = building_map[i];
        ret[i] = cur.find(' ');
        if(ret[i]<0) {
            ret[i] = sz(cur);
        }
    }
    return ret;
}

/* Ignore and do not change the code below */

void trySolution(vector<int> output) {
  Json::Value output_json;

  output_json = Json::Value(Json::arrayValue);
  Json::Value current_value;
  for (int i = 0 ; i < output.size() ; i++) {
    current_value = Json::Value(output[i]);
    output_json.append(current_value);
  }

  Json::FastWriter fastWriter;
  std::string output_str = fastWriter.write(output_json);
  cout << "" << output_str.c_str();
}

int main () {
  setlocale(LC_ALL, "en_US.UTF-8");
  Json::Reader reader;
  string line;
  Json::Value parsed_json;
  std::getline(std::cin, line, '\n');
  reader.parse(line, parsed_json);
  int n = parsed_json.asInt();
  std::getline(std::cin, line, '\n');
  reader.parse(line, parsed_json);

  vector<string> array;
  for (int i = 0 ; i < parsed_json.size() ; i++) {
    array.push_back(parsed_json[i].asString());
  }
  vector<string> building_map = array;

  vector<int> output = buildingHeights(n, building_map);
  trySolution(output);
}
/* Ignore and do not change the code above */
