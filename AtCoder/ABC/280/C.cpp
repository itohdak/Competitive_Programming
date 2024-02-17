#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s, t; cin >> s >> t;
  map<char, vector<int>> mpS, mpT;
  rep(i, s.size()) {
    mpS[s[i]].push_back(i);
  }
  rep(i, t.size()) {
    mpT[t[i]].push_back(i);
  }
  for(auto [k, v]: mpT) {
    if(!mpS.count(k)) {
      cout << v[0]+1 << endk;
    } else if(mpS[k].size() != v.size()) {
      rep(i, v.size()) {
        if(i >= mpS[k].size() || mpS[k][i] != v[i]) {
          cout << v[i]+1 << endk;
          break;
        }
      }
    }
  }
  return 0;
}
