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
  ll sum = 0;
  vector<ll> diff(n);
  diff[0] = A[0];
  rep(i, n) {
    diff[i] = A[i] - (i ? A[i-1] : 0);
    if(i && diff[i]>0) sum += diff[i];
  }
  if(diff[0]+sum > 0) cout << (diff[0]+sum+1)/2 << endk;
  else cout << (diff[0]+sum)/2 << endk;
  // cout << sum << endk;
  // cout << diff << endk;
  int q; cin >> q;
  rep(_, q) {
    int l, r; ll x; cin >> l >> r >> x;
    l--; r--;
    if(x > 0) {
      if(l != 0) {
        if(diff[l] > 0) sum += x;
        else if(diff[l]+x > 0) sum += diff[l]+x;
      }
      diff[l] += x;
      if(r != n-1) {
        if(diff[r+1]-x > 0) sum -= x;
        else if(diff[r+1] > 0 && diff[r+1]-x <= 0) sum -= diff[r+1];
        diff[r+1] -= x;
      }
    } else if(x < 0) {
      if(l != 0) {
        if(diff[l]+x > 0) sum += x;
        else if(diff[l] > 0 && diff[l]+x <= 0) sum -= diff[l];
      }
      diff[l] += x;
      if(r != n-1) {
        if(diff[r+1] > 0) sum -= x;
        else if(diff[r+1]-x > 0) sum += diff[r+1]-x;
        diff[r+1] -= x;
      }
    }
    if(diff[0]+sum > 0) cout << (diff[0]+sum+1)/2 << endk;
    else cout << (diff[0]+sum)/2 << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
