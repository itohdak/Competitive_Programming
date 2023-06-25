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
  vector<int> K(n); rep(i, n) cin >> K[i];
  vector<int> H(n); rep(i, n) cin >> H[i];
  vector<tuple<int, int, int>> A;
  rep(i, n) {
    A.push_back({K[i]-H[i], 1, i});
    A.push_back({K[i], -1, i});
  }
  sort(all(A));
  set<int> st;
  ll ans = 0;
  int prev = 0;
  rep(i, 2*n) {
    auto [a, b, c] = A[i];
    if(b == -1) {
      st.erase(c);
      if(st.empty()) {
        ans += 1LL*(a-prev)*(a-prev+1)/2;
      }
    } else {
      if(st.empty()) {
        prev = a;
      }
      st.insert(c);
    }
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
