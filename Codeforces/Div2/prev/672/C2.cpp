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
  int n, q; cin >> n >> q;
  vector<int> A(n); rep(i, n) cin >> A[i];
  ll ans = 0;
  auto is_local_max = [&](int i) {
    return (A[i] > (i==0 ? -inf : A[i-1]) && A[i] > (i==n-1 ? -inf : A[i+1]));
  };
  auto is_local_min = [&](int i) {
    return (A[i] < (i==0 ? -inf : A[i-1]) && A[i] < (i==n-1 ? -inf : A[i+1]));
  };
  rep(i, n) {
    if(is_local_max(i)) ans += A[i];
    if(is_local_min(i)) ans -= A[i];
  }
  cout << ans << endk;
  rep(_, q) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    {
      set<int> st;
      for(int i=max(l-1, 0); i<=min(l+1, n-1); i++) st.insert(i);
      for(int i=max(r-1, 0); i<=min(r+1, n-1); i++) st.insert(i);
      for(int i: st) {
        if(is_local_max(i)) ans -= A[i];
        if(is_local_min(i)) ans += A[i];
      }
    }
    swap(A[l], A[r]);
    {
      set<int> st;
      for(int i=max(l-1, 0); i<=min(l+1, n-1); i++) st.insert(i);
      for(int i=max(r-1, 0); i<=min(r+1, n-1); i++) st.insert(i);
      for(int i: st) {
        if(is_local_max(i)) ans += A[i];
        if(is_local_min(i)) ans -= A[i];
      }
    }
    cout << ans << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
