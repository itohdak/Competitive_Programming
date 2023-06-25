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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, m; cin >> n >> m;
  vector<int> X(m), W(m);
  rep(i, m) {
    cin >> X[i] >> W[i];
  }
  vector<int> id(m);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return W[i] < W[j];
  });
  vector<int> use(2*n);
  copy(begin(id), begin(id)+2*n, begin(use));
  sort(all(use), [&](int i, int j) {
    return X[i] < X[j];
  });
  ll sum = 0;
  vector<pair<int, int>> E(n);
  rep(i, n) {
    E[i] = {use[i], use[2*n-1-i]};
    sum += W[use[i]] + W[use[2*n-1-i]];
  }
  cout << sum << endk;
  for(auto [a, b]: E) cout << a+1 << ' ' << b+1 << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
