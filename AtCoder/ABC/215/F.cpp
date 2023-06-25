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
  vector<pair<ll, ll>> P(n);
  for(auto& [x, y]: P) cin >> x >> y;
  sort(all(P));
  auto bsearch = [&]() {
    auto test = [&](ll mid) {
      int l = 0, r = 0;
      set<ll> st;
      while(r < n) {
        int r2 = r;
        while(l < r && P[r].first - P[l].first >= mid) {
          st.insert(P[l].second);
          l++;
        }
        while(r2 < n && P[r].first == P[r2].first) {
          if(st.lower_bound(P[r2].second+mid) != st.end()) return true;
          if(st.upper_bound(P[r2].second-mid) != st.begin()) return true;
          r2++;
        }
        r = r2;
      }
      return false;
    };
    ll ok = 0, ng = 1000000001;
    while(abs(ok-ng) > 1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
  return 0;
}
