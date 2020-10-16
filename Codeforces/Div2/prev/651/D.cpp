#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  auto bsearch = [&]() {
    auto test = [&](ll t) {
      // try to make odd set <=k
      int cnt = 0;
      rep(i, n) {
        if(cnt%2==0) { // odd
          if(A[i] <= t) cnt++;
        } else { // even
          cnt++;
        }
      }
      if(cnt >= k) return true;
      // try to make even set <= k
      cnt = 0;
      rep(i, n) {
        if(cnt%2==0) { // odd
          cnt++;
        } else { // even
          if(A[i] <= t) cnt++;
        }
      }
      if(cnt >= k) return true;
      return false;
    };

    ll ok = longinf, ng = 0;
    while(abs(ok-ng) > 1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };

  cout << bsearch() << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
