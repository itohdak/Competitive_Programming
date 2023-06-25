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
  string x; cin >> x;
  int n = x.size();
  vector<int> D(n);
  rep(i, n) D[i] = x[i]-'0';
  int mx = *max_element(all(D));
  ll m; cin >> m;
  if(n == 1) {
    if(D[0] <= m) cout << 1 << endk;
    else cout << 0 << endk;
  } else {
    auto bsearch = [&]() {
      auto test = [&](ll k) -> bool {
        ll pw = 1;
        ll sum = 0;
        rrep(i, n) {
          if(D[i] > m / pw) return false;
          if(D[i] > (m - sum) / pw) return false;
          sum += pw * D[i];
          if(i && pw > m / k) return false;
          pw *= k;
        }
        return sum <= m;
      };
      ll ok = mx, ng = m+1;
      while(abs(ok-ng)>1) {
        ll mid = (ok+ng)/2;
        (test(mid) ? ok : ng) = mid;
      }
      return ok;
    };
    ll ret = bsearch();
    cout << max(0LL, ret-mx) << endk;
  }
  return 0;
}
