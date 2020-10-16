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
  int n, x;
  cin >> n >> x;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  ll sum = accumulate(all(A), 0LL);
  if(sum % x != 0) {
    cout << n << endl;
  } else {
    int l = 0, r = n-1;
    while(l < n && A[l] % x == 0) l++;
    while(r >= 0 && A[r] % x == 0) r--;
    if(l<=r) {
      cout << n-min(l, n-1-r)-1 << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
