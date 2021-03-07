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
  int n, m; cin >> n >> m;
  string s, t; cin >> s >> t;
  int ans = inf;
  vector<int> pos;
  rep(j, m) {
    if(j+n>m) continue;
    int count = 0;
    vector<int> p;
    rep(i, n) {
      if(s[i] != t[j+i]) {
        count++;
        p.push_back(i);
      }
    }
    if(ans > count) {
      ans = count;
      pos = p;
    }
  }
  cout << ans << endk;
  assert(pos.size() == ans);
  rep(i, ans) cout << pos[i]+1 << ' ';
  cout << endk;
  return 0;
}
