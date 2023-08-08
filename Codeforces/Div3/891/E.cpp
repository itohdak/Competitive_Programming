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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; cin >> n;
  vector<int> X(n); rep(i, n) cin >> X[i];
  vector<int> origX(n); copy(all(X), begin(origX));
  sort(all(X));
  int l = 0, r = 0;
  ll cnt = 0;
  while(l < n) {
    r = l;
    while(r < n && X[r] == X[l]) {
      r++;
    }
    if(l == 0) {
      cnt += n;
    } else {
      cnt += 1LL*(X[r-1]-X[l-1])*(n-l);
    }
    l = r;
  }
  map<int, ll> ans;
  l = 0, r = 0;
  while(l < n) {
    r = l;
    while(r < n && X[r] == X[l]) {
      r++;
    }
    if(l == 0) {
      ans[X[0]] = cnt;
    } else {
      cnt += (n-(n-l)) + 1LL*(X[r-1]-X[l-1]-1)*(l-(n-l)) + (l-n);
      ans[X[l]] = cnt;
    }
    l = r;
  }
  rep(i, n) {
    assert(ans.count(origX[i]));
    cout << ans[origX[i]] << ' ';
  }
  cout << endk;
  // cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
