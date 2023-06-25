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
  if(k > (n-1)*(n-2)/2) {
    cout << -1 << endk;
    return 0;
  }
  vector<pair<int, int>> E;
  rep(i, n) {
    if(i) {
      E.push_back({0, i});
    }
  }
  ll rem = (n-1)*(n-2)/2-k;
  REP(i, 1, n) {
    REP(j, i+1, n) {
      if(rem == 0) break;
      E.push_back({i, j});
      rem--;
    }
    if(rem == 0) break;
  }
  cout << E.size() << endk;
  for(auto [u, v]: E) {
    cout << u+1 << ' ' << v+1 << endk;
  }
  return 0;
}
