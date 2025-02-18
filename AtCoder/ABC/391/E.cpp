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
  int n; cin >> n;
  string s; cin >> s;

  vector<vector<int>> cost(n+1);
  vector<string> S(n+1);
  int pw = 1;
  rep(i, n+1) {
    if(i == n) {
      cost[i] = vector<int>(pw, 1);
      S[i] = s;
    } else {
      cost[i] = vector<int>(pw, -1);
      S[i] = string(pw, ' ');
    }
    pw *= 3;
  }

  auto dfs = [&](auto dfs, int i, int j) -> pair<char, int> {
    if(cost[i][j] != -1) {
      return {S[i][j], cost[i][j]};
    }
    vector<vector<int>> tmp(2);
    rep(k, 3) {
      const auto& [ch, co] = dfs(dfs, i+1, j*3+k);
      tmp[ch=='1'].push_back(co);
    }
    rep(k, 2) {
      sort(all(tmp[k]));
    }
    if(tmp[0].size() == 0) {
      S[i][j] = '1';
      cost[i][j] = tmp[1][0] + tmp[1][1];
    } else if(tmp[0].size() == 1) {
      S[i][j] = '1';
      cost[i][j] = tmp[1][0];
    } else if(tmp[0].size() == 2) {
      S[i][j] = '0';
      cost[i][j] = tmp[0][0];
    } else {
      S[i][j] = '0';
      cost[i][j] = tmp[0][0] + tmp[0][1];
    }
    return {S[i][j], cost[i][j]};
  };

  cout << dfs(dfs, 0, 0).second << endk;
  return 0;
}
