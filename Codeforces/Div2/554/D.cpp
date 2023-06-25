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
  vector<vector<pair<ll, bool>>> memo(2*n+1, vector<pair<ll, bool>>(2*n+1, make_pair(-1, false)));
  auto dfs = [&](auto dfs, int depth, int balance) -> void {
    auto isValid = [&](int depth, int balance) -> bool {
      return depth <= 2*n && balance <= 2*n-depth && balance >= 0;
    };
    if(!isValid(depth, balance)) return;
    if(memo[depth][balance].first != -1) return;
    dfs(dfs, depth+1, balance+1); // add (
    dfs(dfs, depth+1, balance-1); // add )
    bool matched = false;
    memo[depth][balance].first = 0;
    if(isValid(depth+1, balance+1)) {
      (memo[depth][balance].first += memo[depth+1][balance+1].first + (!matched && !memo[depth+1][balance+1].second)) %= mod;
      matched |= !memo[depth+1][balance+1].second;
    }
    if(isValid(depth+1, balance-1)) {
      (memo[depth][balance].first += memo[depth+1][balance-1].first + (!matched && !memo[depth+1][balance-1].second)) %= mod;
      matched |= !memo[depth+1][balance-1].second;
    }
    memo[depth][balance].second = matched;
  };
  dfs(dfs, 0, 0);
  cout << memo[0][0].first << endk;
  return 0;
}
