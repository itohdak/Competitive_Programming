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
  vector<int> A(n); rep(i, n) cin >> A[i];
  ll sum = accumulate(all(A), 0LL);
  if(sum % n != 0) {
    cout << -1 << endk;
    return;
  }
  ll ave = sum / n;
  vector<tuple<int, int, ll>> ans;
  rep(i, n) {
    if(i) {
      ll cnt = (A[i]+i)/(i+1)*(i+1)-A[i];
      ans.push_back({0, i, cnt});
      A[i] += cnt;
      A[0] -= cnt;
      assert(A[0] >= 0);
      //
      cnt = A[i]/(i+1);
      ans.push_back({i, 0, cnt});
      A[i] -= (i+1)*cnt;
      A[0] += (i+1)*cnt;
      assert(A[i] == 0);
    }
  }
  rep(i, n) {
    if(i) {
      ll cnt = ave;
      ans.push_back({0, i, cnt});
      A[i] += cnt;
      A[0] -= cnt;
      assert(A[0] >= 0);
    }
  }
  rep(i, n) assert(A[i] == ave);
  assert(ans.size() <= 3*n);
  cout << ans.size() << endk;
  for(const auto [i, j, x]: ans) {
    cout << i+1 << ' ' << j+1 << ' ' << x << endk;
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
