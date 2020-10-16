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
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  sort(all(A));
  vector<ll> small, large;
  rep(i, n/2) small.push_back(A[i]);
  REP(i, n/2, n) large.push_back(A[i]);
  vector<ll> ans(n);
  for(int i=1; i<n; i+=2) ans[i] = small[i/2];
  int j = (n%2 ? n-1 : n-2);
  int tmp = 0;
  rep(i, n/2) {
    if(2*i > j) break;
    int ne = lower_bound(begin(large)+tmp, end(large), small[i]+1) - begin(large);
    ans[2*i] = large[ne];
    REP(k, tmp, ne) {
      ans[j] = large[k];
      j -= 2;
    }
    tmp = ne+1;
  }
  if(n%2 && ans[n-1] == 0) ans[n-1] = large[tmp];
  // cout << small << endk;
  // cout << large << endk;
  // cout << ans << endk;
  int cnt = 0;
  REP(i, 1, n-1) if(ans[i-1] > ans[i] && ans[i] < ans[i+1]) cnt++;
  cout << cnt << endk;
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
