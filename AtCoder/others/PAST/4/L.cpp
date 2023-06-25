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
  int n, q; cin >> n >> q;
  vector<ll> H(n); rep(i, n) cin >> H[i];
  vector<multiset<ll>> diff(2);
  // vector<map<ll, int>> diff(2);
  rep(i, n-1) {
    diff[i%2].insert(H[i+1]-H[i]);
    // diff[i%2][H[i+1]-H[i]]++;
  }
  vector<ll> offset(2);
  rep(_, q) {
    int t; cin >> t;
    if(t == 1) {
      ll v; cin >> v;
      offset[1] += v;
    } else if(t == 2) {
      ll v; cin >> v;
      offset[0] += v;
    } else {
      int u; ll v; cin >> u >> v;
      u--;
      ll prev = H[u];
      H[u] += v;
      if(u+1 < n) {
        diff[u%2].erase(diff[u%2].find(H[u+1]-prev));
        diff[u%2].insert(H[u+1]-H[u]);
        // assert(diff[u%2].count(H[u+1]-prev));
        // diff[u%2][H[u+1]-prev]--;
        // if(diff[u%2][H[u+1]-prev] == 0) diff[u%2].erase(H[u+1]-prev);
        // diff[u%2][H[u+1]-H[u]]++;
      }
      if(u-1 >= 0) {
        diff[(u-1)%2].erase(diff[(u-1)%2].find(prev-H[u-1]));
        diff[(u-1)%2].insert(H[u]-H[u-1]);
        // assert(diff[(u-1)%2].count(prev-H[u-1]));
        // diff[(u-1)%2][prev-H[u-1]]--;
        // if(diff[(u-1)%2][prev-H[u-1]] == 0) diff[(u-1)%2].erase(prev-H[u-1]);
        // diff[(u-1)%2][H[u]-H[u-1]]++;
      }
    }
    // cout << diff << endk;
    // cout << offset << endk;
    cout << diff[0].count(offset[1]-offset[0]) + diff[1].count(offset[0]-offset[1]) << endk;
    // cout << (diff[0].count(offset[1]-offset[0]) ? diff[0][offset[1]-offset[0]] : 0) +
    //         (diff[1].count(offset[0]-offset[1]) ? diff[1][offset[0]-offset[1]] : 0) << endk;
  }
  return 0;
}
