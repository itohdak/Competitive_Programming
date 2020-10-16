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
  int n, k, z; cin >> n >> k >> z;
  vector<ll> A(n), sum(n+1), mx2(n);
  rep(i, n) {
    cin >> A[i];
    sum[i+1] = sum[i] + A[i];
    if(i) mx2[i] = max(A[i]+A[i-1], mx2[i-1]);
  }
  ll mx = 0;
  for(int i=max(k-2*z, 1); i<=k; i++) {
    // cout << i << ' ';
    ll tmp = 0;
    tmp += sum[i+1];
    // cout << tmp << ' ' << mx2[i] << ' ' << (k-i)/2 << ' ';
    tmp += mx2[i] * (ll)((k-i)/2);
    // cout << tmp << ' ';
    if((k-i)%2) tmp += A[i-1];
    // cout << tmp << endl;
    mx = max(tmp, mx);
  }
  cout << mx << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
