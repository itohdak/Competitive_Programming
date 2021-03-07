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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  vector<vector<char>> dp(k+1, vector<char>(2*n));
  rep(i, 2*n) dp[0][i] = s[i%n];
  rep(j, k) {
    rep(i, n) {
      auto next = [&](char c1, char c2) {
        string s;
        s += c1;
        s += c2;
        if(s == "RR" || s == "RS" || s == "SR") return 'R';
        else if(s == "PP" || s == "PR" || s == "RP") return 'P';
        else if(s == "SS" || s == "SP" || s == "PS") return 'S';
        else assert(false);
      };
      dp[j+1][i] = next(dp[j][2*i], dp[j][2*i+1]);
    }
    rep(i, n) dp[j+1][i+n] = dp[j+1][i];
  }
  // cout << dp << endk;
  cout << dp[k][0] << endk;
  return 0;
}
