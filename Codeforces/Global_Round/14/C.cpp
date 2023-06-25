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
  int n, m, x; cin >> n >> m >> x;
  vector<int> H(n); rep(i, n) cin >> H[i];
  vector<int> id(n);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return H[i] > H[j];
  });
  priority_queue<pair<ll, int>> q;
  vector<int> ans(n, -1);
  rep(i, n) {
    if(i < m) {
      ans[id[i]] = i;
      q.push({-H[id[i]], i});
    } else {
      auto [sumh, j] = q.top(); q.pop();
      sumh = -sumh;
      ans[id[i]] = j;
      sumh += H[id[i]];
      q.push({-sumh, j});
    }
  }
  cout << "YES" << endk;
  rep(i, n) {
    cout << ans[i]+1 << ' ';
  }
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
