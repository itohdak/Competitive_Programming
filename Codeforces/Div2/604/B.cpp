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
  vector<int> P(n), id(n);
  rep(i, n) {
    cin >> P[i];
    P[i]--;
    id[i] = i;
  }
  sort(all(id), [&](int i, int j) {
    return P[i] < P[j];
  });
  // cout << P << endk;
  // cout << id << endk;
  vector<bool> ans(n);
  int mn = n, mx = -1;
  for(int i: id) {
    chmin(mn, i);
    chmax(mx, i);
    ans[P[i]] = (mx - mn == P[i]);
  }
  rep(i, n) cout << ans[i];
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
