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
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  map<pair<int, int>, int> cnt;
  int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
  int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};
  rep(k, 8) {
    cnt[{x1+dx[k], y1+dy[k]}]++;
  }
  rep(k, 8) {
    cnt[{x2+dx[k], y2+dy[k]}]++;
  }
  for(auto [_, c]: cnt) {
    if(c > 1) {
      cout << "Yes" << endk;
      return 0;
    }
  }
  cout << "No" << endk;
  return 0;
}