#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
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
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<int> ans(n);
  vector<bool> used(n);
  {
    int mxi = max_element(all(A)) - begin(A);
    used[mxi] = true;
    ans[0] = A[mxi];
  }
  ll g = ans[0];
  rep(i, n) {
    if(i) {
      ll gmx = 1;
      int idx = -1;
      rep(j, n) {
        int tmp = __gcd(g, A[j]);
        if(!used[j] && gmx <= tmp) {
          idx = j;
          gmx = tmp;
        }
      }
      assert(idx != -1);
      used[idx] = true;
      ans[i] = A[idx];
      g = gmx;
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
  while(T--) solve();
  return 0;
}
