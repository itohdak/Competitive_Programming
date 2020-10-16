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
  int n, p;
  cin >> n >> p;
  vector<ll> A(n);
  // map<ll, int> cnt;
  rep(i, n) {
    cin >> A[i];
    // cnt[A[i]]++;
  }
  // int prev = 0;
  // for(auto& ele: cnt) {
  //   ele.second += prev;
  //   prev = ele.second;
  // }
  sort(all(A));
  ll l, r;
  {
    ll ok = *max_element(all(A)), ng = 0;
    while(ok-ng>1) {
      auto test = [&](ll k) {
        bool ok = true;
        rep(i, n) {
          ok &= (upper_bound(all(A), k+i)-begin(A) >= i+1);
        }
        return ok;
      };
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    l = ok;
  }
  {
    ll ok = 0, ng = *max_element(all(A));
    while(ng-ok>1) {
      auto test = [&](ll k) {
        bool ok = true;
        rep(i, n) {
          ok &= (upper_bound(all(A), k+i)-begin(A) < p+i);
        }
        return ok;
      };
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    r = ok;
  }
  cout << max(r-l+1, 0LL) << "\n";
  for(ll i=l; i<=r; i++) cout << i << ' ';
  cout << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
