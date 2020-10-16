#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> A(n), W(k);
  rep(i, n) cin >> A[i];
  rep(i, k) cin >> W[i];
  sort(all(A), greater<ll>());
  sort(all(W));
  ll ans = accumulate(A.begin(), A.begin()+k, 0LL);
  vector<ll> B(n);
  rep(i, k) B[i] = A[i];
  int tmp = k;
  rep(i, k) {
    if(W[i] == 1) ans += B[i];
    else ans += A[tmp+W[i]-2];
    tmp += W[i]-1;
  }
  cout << ans << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
