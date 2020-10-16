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
  int n, k; cin >> n >> k;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<multiset<int>> cnt(200005);
  rep(i, n) {
    int c = 0;
    ll a = A[i];
    while(a) {
      cnt[a].insert(c);
      a /= 2;
      c++;
    }
    cnt[a].insert(c);
  }
  ll ans = longinf;
  rep(i, 200005) {
    if(cnt[i].size() >= k) {
      ll tmp = 0;
      auto itr = cnt[i].begin();
      rep(i, k) {
        tmp += *itr;
        itr++;
      }
      chmin(ans, tmp);
    }
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
