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

void solve() {
  int n, a, b; cin >> n >> a >> b;
  vector<int> U(n+1); rep(i, n) cin >> U[i+1];
  {
    int g = __gcd(a, b);
    int first = -1;
    bool ok = true;
    rep(i, n) {
      if(U[i]) {
        if(first == -1) first = i;
        else if((i-first)%g) ok = false;
      }
    }
    if(!ok) {
      cout << "IMPOSSIBLE" << endk;
      return;
    }
  }
  int lcm = a * b / __gcd(a, b);
  auto bsearch = [&]() {
    auto test = [&](int i) -> bool {
      if(i < n) return false;
      vector<int> cnt(i+1);
      cnt[i] = 1;
      bool ok = true;
      rrep(j, i+1) {
        if(j < n+1) {
          if(U[j] > cnt[j]) {
            ok = false;
            break;
          }
          cnt[j] -= U[j];
        }
        if(j-a > 0) {
          cnt[j-a] += cnt[j];
          chmin(cnt[j-a], 500);
        }
        if(j-b > 0) {
          cnt[j-b] += cnt[j];
          chmin(cnt[j-b], 500);
        }
      }
      return ok;
    };
    int ans = inf;
    rep(i, lcm) {
      int ok = 1000000 / lcm, ng = n / lcm;
      while(abs(ok-ng) > 1) {
        int mid = (ok+ng)/2;
        (test(mid*lcm+i) ? ok : ng) = mid;
      }
      chmin(ans, ok*lcm+i);
    }
    return ans;
  };
  cout << bsearch() << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(i, t) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
