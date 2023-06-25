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
  int n, a, b; cin >> n >> a >> b;
  if(b < a) {
    if(b == n/2 && a == n/2+1) {
      vector<int> ans(n);
      rep(i, n/2) ans[i] = n/2+1+i;
      rep(i, n/2) ans[n/2+i] = 1+i;
      assert(*min_element(begin(ans), begin(ans)+n/2) == a);
      assert(*max_element(begin(ans)+n/2, end(ans)) == b);
      rep(i, n) cout << ans[i] << ' ';
      cout << endk;
    } else {
      cout << -1 << endk;
    }
  } else {
    if(n-b <= n/2-1 && a-1 <= n/2-1) {
      vector<int> ans(n);
      int l = 0, r = n-1;
      ans[l++] = a;
      rep(i, n-b) ans[l++] = b+1+i;
      ans[r--] = b;
      rep(i, a-1) ans[r--] = 1+i;
      for(int i=l; i<=r; i++) {
        ans[i] = a+1+i-l;
      }
      assert(*min_element(begin(ans), begin(ans)+n/2) == a);
      assert(*max_element(begin(ans)+n/2, end(ans)) == b);
      rep(i, n) cout << ans[i] << ' ';
      cout << endk;
    } else {
      cout << -1 << endk;
    }
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
