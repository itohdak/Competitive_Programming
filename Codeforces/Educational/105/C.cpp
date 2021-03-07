#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, m; cin >> n >> m;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> B(m); rep(i, m) cin >> B[i];
  vector<ll> C;
  rep(i, m) if(*lower_bound(all(A), B[i]) == B[i]) C.push_back(B[i]);
  int r = lower_bound(all(B), 0) - begin(B);
  int ans1 = 0;
  for(int i=r; i<m; i++) {
    auto bsearch = [&](ll p) {
      auto test = [&](ll mid) {
        int cnt = upper_bound(all(A), p+mid) - lower_bound(all(A), 0);
        return cnt >= mid;
      };
      ll ok = 0, ng = longinf;
      while(abs(ok-ng)>1) {
        ll mid = (ok+ng)/2;
        (test(mid) ? ok : ng) = mid;
      }
      return ok;
    };
    ll p = B[i]-1;
    ll ret = bsearch(p);
    int cnt = upper_bound(all(B), p+ret) - lower_bound(all(B), p+1) + upper_bound(all(C), longinf) - lower_bound(all(C), p+ret+1);
    chmax(ans1, cnt);
  }
  int ans2 = 0;
  for(int i=0; i<r; i++) {
    auto bsearch = [&](ll p) {
      auto test = [&](ll mid) {
        int cnt = upper_bound(all(A), 0) - lower_bound(all(A), p-mid);
        return cnt >= mid;
      };
      ll ok = 0, ng = longinf;
      while(abs(ok-ng)>1) {
        ll mid = (ok+ng)/2;
        (test(mid) ? ok : ng) = mid;
      }
      return ok;
    };
    ll p = B[i]+1;
    ll ret = bsearch(p);
    int cnt = upper_bound(all(B), p-1) - lower_bound(all(B), p-ret) + upper_bound(all(C), p-ret-1) - lower_bound(all(C), -longinf);
    chmax(ans2, cnt);
  }
  cout << ans1 + ans2 << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
