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
  vector<int> P(n); rep(i, n) cin >> P[i];
  vector<int> key(256, -1);
  vector<int> ans(n);
  rep(i, n) {
    if(key[P[i]] != -1) ans[i] = key[P[i]];
    else {
      int mn = P[i];
      for(int p=P[i]; p>=max(0, P[i]-k+1); p--) {
        if(key[p] == -1) chmin(mn, p);
        else if(key[p] >= P[i]-k+1) chmin(mn, key[p]);
        else break;
      }
      for(int p=mn; p<=P[i]; p++) key[p] = mn;
      assert(key[P[i]] != -1);
      ans[i] = key[P[i]];
    }
  }
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
  return 0;
}
