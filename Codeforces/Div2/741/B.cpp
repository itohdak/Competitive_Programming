#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

bool is_prime(const unsigned n) {
  switch(n) {
  case 0:
  case 1: return false;
  case 2:
  case 3: return true;
  }
  if(n % 2 == 0) return false;
  if(n % 3 == 0) return false;
  if(n % 6 != 1 && n % 6 != 5) return false;
  for(unsigned i=5; i*i<=n; i+=6) {
    if(n % i     == 0) return false;
    if(n % (i+2) == 0) return false;
  }
  return true;
}
void solve() {
  int k; cin >> k;
  string n; cin >> n;
  int ans = inf;
  int d = inf;
  auto dfs = [&](auto dfs, int cur, int dep, int val) -> void {
    if(cur == k) {
      if(val && (val == 1 || !is_prime(val))) {
        chmin(d, dep);
        chmin(ans, val);
      }
      return;
    }
    if(dep == 4) {
      dfs(dfs, cur+1, dep, val);
    } else {
      dfs(dfs, cur+1, dep, val);
      dfs(dfs, cur+1, dep+1, val*10+(n[cur]-'0'));
    }
  };
  dfs(dfs, 0, 0, 0);
  cout << d << endk << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
