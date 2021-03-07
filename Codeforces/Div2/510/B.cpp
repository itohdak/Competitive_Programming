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
  vector<int> C(n), B(n);
  rep(i, n) {
    cin >> C[i];
    string s; cin >> s;
    set<char> st;
    for(char c: s) st.insert(c);
    for(char c='A'; c<='C'; c++) {
      if(st.count(c)) B[i] ^= 1<<(c-'A');
    }
  }
  vector<vector<ll>> dp(n+1, vector<ll>(1<<3, longinf));
  dp[0][0] = 0;
  rep(i, n) {
    rep(j, 1<<3) {
      chmin(dp[i+1][j], dp[i][j]);
      chmin(dp[i+1][j|B[i]], dp[i][j]+C[i]);
    }
  }
  cout << (dp[n][7]==longinf ? -1 : dp[n][7]) << endk;
  return 0;
}
