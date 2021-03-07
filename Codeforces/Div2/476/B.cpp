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
  vector<string> S(n); rep(i, n) cin >> S[i];
  vector<vector<int>> cnt(n, vector<int>(n));
  rep(i, n) rep(j, n) {
    if(j + k > n) continue;
    int tmp = 0;
    rep(l, k) if(S[i][j+l] == '.') tmp++;
    if(tmp == k) rep(l, k) cnt[i][j+l]++;
  }
  rep(i, n) rep(j, n) {
    if(i + k > n) continue;
    int tmp = 0;
    rep(l, k) if(S[i+l][j] == '.') tmp++;
    if(tmp == k) rep(l, k) cnt[i+l][j]++;
  }
  int ans = 0;
  int x = 0, y = 0;
  rep(i, n) rep(j, n) {
    if(cnt[i][j] > ans) {
      ans = cnt[i][j];
      x = i;
      y = j;
    }
  }
  cout << x+1 << ' ' << y+1 << endk;
  return 0;
}
