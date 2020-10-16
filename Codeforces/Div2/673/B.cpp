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
  int n; ll t; cin >> n >> t;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  int mid = t/2;
  vector<int> ans(n);
  if(t%2) {
    rep(i, n) ans[i] = (A[i] <= mid ? 0 : 1);
  } else {
    vector<int> tmp;
    rep(i, n) {
      if(A[i] < mid) ans[i] = 0;
      else if(A[i] == mid) tmp.push_back(i);
      else ans[i] = 1;
    }
    rep(i, tmp.size()) ans[tmp[i]] = (i < (int)tmp.size()/2 ? 0 : 1);
  }
  rep(i, n) cout << ans[i] << ' '; cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
