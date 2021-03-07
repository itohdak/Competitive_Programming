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
  int n, r; cin >> n >> r;
  vector<int> A(n);
  set<int> st;
  rep(i, n) {
    cin >> A[i];
    if(A[i]) st.insert(i);
  }
  int l = 0;
  vector<bool> warm(n);
  int ans = 0;
  while(l < n) {
    while(l < n && warm[l]) l++;
    if(l == n) break;
    auto itr = st.upper_bound(l+r-1);
    if(itr == st.begin()) {
      cout << -1 << endk;
      return 0;
    }
    itr--;
    ans++;
    for(int i=max(0, *itr-r+1); i<=min(n-1, *itr+r-1); i++) {
      warm[i] = true;
    }
    if(!warm[l]) {
      cout << -1 << endk;
      return 0;
    }
    // cout << l << ' ' << warm << endk;
  }
  cout << ans << endk;
  return 0;
}
