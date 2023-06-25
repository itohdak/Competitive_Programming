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
  vector<int> R(n); rep(i, n) cin >> R[i];
  vector<int> S(n);
  copy(all(R), begin(S));
  sort(all(S));
  vector<int> ans(n);
  rep(i, n) {
    auto itr = upper_bound(all(S), R[i]*2);
    if(itr == begin(S)) {
      ans[i] = -1;
    } else {
      --itr;
      if(*itr == R[i]) {
        if(itr == begin(S)) ans[i] = -1;
        else {
          ans[i] = *(--itr);
        }
      } else {
        ans[i] = *itr;
      }
    }
  }
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(i, T) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
