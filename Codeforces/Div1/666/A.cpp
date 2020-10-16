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
  if(n == 1) {
    ll a; cin >> a;
    cout << 1 << ' ' << 1 << endk;
    cout << -a << endk;
    cout << 1 << ' ' << 1 << endk;
    cout << 0 << endk;
    cout << 1 << ' ' << 1 << endk;
    cout << 0 << endk;
    return;
  }
  vector<ll> A(n); rep(i, n) cin >> A[i];
  cout << 1 << ' ' << n-1 << endk;
  rep(i, n-1) {
    ll a = abs(A[i]-A[i]/n*n) * (n-1);
    if(A[i] >= 0) {
      cout << a << ' ';
      A[i] += a;
    } else {
      cout << -a << ' ';
      A[i] -= a;
    }
  }
  cout << endk;
  // cout << A << endk;
  cout << 2 << ' ' << n << endk;
  REP(i, 1, n) {
    ll a = abs(A[i]-A[i]/n*n) * (n-1);
    if(A[i] >= 0) {
      cout << a << ' ';
      A[i] += a;
    } else {
      cout << -a << ' ';
      A[i] -= a;
    }
  }
  cout << endk;
  // cout << A << endk;
  cout << 1 << ' ' << n << endk;
  rep(i, n) {
    cout << -A[i]/n*n << ' ';
  }
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
