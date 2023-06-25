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
  vector<int> X(m);
  for(auto& x: X) {
    cin >> x;
    x--;
  }
  auto bsearch = [&]() {
    auto test = [&](ll mid) {
      ll pos = 0;
      rep(i, m) {
        if(pos < X[i] && X[i]-pos > mid) return false;
        if(pos < X[i]) {
          ll mx = max(X[i]+max(0LL, mid-(X[i]-pos)*2), X[i]+max(0LL, (mid-(X[i]-pos))/2));
          chmax(pos, mx+1);
        } else {
          chmax(pos, X[i]+mid+1);
        }
      }
      return pos >= n;
    };
    ll ok = longinf, ng = -1;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
  return 0;
}
