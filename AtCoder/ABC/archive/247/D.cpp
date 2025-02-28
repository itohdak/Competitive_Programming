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
  int q; cin >> q;
  deque<pair<int, int>> Q;
  rep(i, q) {
    int t; cin >> t;
    if(t == 1) {
      int x, c; cin >> x >> c;
      Q.push_back({x, c});
    } else {
      int c; cin >> c;
      ll sum = 0;
      while(c) {
        auto front = Q.front();
        Q.pop_front();
        if(front.second > c) {
          front.second -= c;
          sum += 1LL * front.first * c;
          c = 0;
          Q.push_front(front);
        } else {
          c -= front.second;
          sum += 1LL * front.first * front.second;
        }
      }
      cout << sum << endk;
    }
  }
  return 0;
}
