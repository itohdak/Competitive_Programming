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
  vector<int> P(n); rep(i, n) cin >> P[i];
  int pos1;
  rep(i, n) if(P[i] == 1) pos1 = i;
  vector<int> ans;
  auto shift = [&](int sz) {
    rep(i, sz) {
      ans.push_back(pos1);
      swap(P[pos1], P[(pos1+P[pos1])%n]);
      // cout << P << endk;
    }
    pos1 = (pos1+1)%n;
  };
  for(int i=2; i<=n; i++) {
    while(P[(pos1+i-1)%n] != i%n) shift(i-1);
  }
  while(pos1 != 1) shift(n);
  cout << ans.size() << endk;
  for(int a: ans) cout << a << endk;
  return 0;
}
