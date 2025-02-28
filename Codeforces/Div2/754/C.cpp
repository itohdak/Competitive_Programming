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

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  vector<vector<int>> sum(n+1, vector<int>(3));
  vector<int> apos;
  rep(i, n) {
    rep(j, 3) {
      sum[i+1][j] = sum[i][j] + (s[i] == char('a'+j));
    }
    if(s[i] == 'a') apos.push_back(i);
  }
  int ans = inf;
  rep(i, apos.size()-1) {
    rep(k, 2) {
      if(i+k+1 >= apos.size()) continue;
      bool ok = true;
      rep(j, 2) {
        if(sum[apos[i+k+1]+1][0]-sum[apos[i]][0] <= sum[apos[i+k+1]+1][j+1]-sum[apos[i]][j+1]) ok = false;
      }
      if(ok) chmin(ans, apos[i+k+1]-apos[i]+1);
    }
  }
  cout << (ans==inf ? -1 : ans) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
