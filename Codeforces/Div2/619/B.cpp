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
  ll ans = 0;
  ll val = 0;
  vector<ll> B;
  rep(i, n-1) {
    if(A[i] == -1 && A[i+1] == -1) {
      continue;
    } else if(A[i] != -1 && A[i+1] != -1) {
      if(ans < abs(A[i]-A[i+1])) {
        chmax(ans, abs(A[i]-A[i+1]));
      }
    } else if(A[i] == -1) {
      B.push_back(A[i+1]);
    } else if(A[i+1] == -1) {
      B.push_back(A[i]);
    }
  }
  sort(all(B));
  if(!B.empty()) {
    ll mn = *B.begin(), mx = *B.rbegin();
    chmax(ans, (mx-mn+1)/2);
    val = mn + abs(mx-mn) / 2;
  }
  cout << ans << ' ' << val << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
