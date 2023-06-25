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
  vector<string> S(n);
  rep(i, n) cin >> S[i];
  vector<vector<int>> pos(n, vector<int>(10));
  rep(i, n) {
    rep(j, 10) {
      pos[i][S[i][j]-'0'] = j;
    }
  }
  int ans = inf;
  rep(j, 10) {
    vector<int> cnt(10);
    rep(i, n) {
      cnt[pos[i][j]]++;
    }
    int tmp = 0;
    rep(i, 10) {
      chmax(tmp, (cnt[i]-1)*10+i);
    }
    chmin(ans, tmp);
  }
  cout << ans << endk;
  return 0;
}
