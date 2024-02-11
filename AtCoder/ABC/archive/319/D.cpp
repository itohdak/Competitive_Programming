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
  vector<ll> L(n); rep(i, n) cin >> L[i];
  ll sum = accumulate(all(L), 0LL);
  ll mx = *max_element(all(L));
  auto bsearch = [&]() -> ll {
    auto test = [&](ll k) -> bool {
      ll row = 1;
      ll cur = 0;
      rep(i, n) {
	if(cur + L[i] + 1 > k) {
	  row++;
	  cur = L[i] + 1;
	} else {
	  cur = cur + L[i] + 1;
	}
      }
      return row <= m;
    };
    ll ok = sum+n, ng = mx;
    while(ok-ng > 1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch()-1 << endk;
  return 0;
}
