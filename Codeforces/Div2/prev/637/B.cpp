#include <bits/stdc++.h>
// #include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int N, K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  int cnt = 0;
  REP(i, 1, K-1) if(A[i-1] < A[i] && A[i] > A[i+1]) cnt++;
  int mx = cnt;
  int ans = 0;
  REP(i, 1, N-K+1) {
    // cout << mx << ' ' << ans << endl;
    if(A[i-1] < A[i] && A[i] > A[i+1]) cnt--;
    if(A[i+K-3] < A[i+K-2] && A[i+K-2] > A[i+K-1]) cnt++;
    if(cnt > mx) {
      mx = cnt;
      ans = i;
    }
  }
  cout << mx+1 << ' ' << ans+1 << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
