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
  int n;
  cin >> n;
  vector<ll> A(n), B(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  map<pair<ll, ll>, int> cntA, cntB;
  rep(i, (n-1)/2+1) {
    ll mn, mx;
    mn = min(A[i], A[n-1-i]);
    mx = max(A[i], A[n-1-i]);
    cntA[make_pair(mn, mx)]++;
    mn = min(B[i], B[n-1-i]);
    mx = max(B[i], B[n-1-i]);
    cntB[make_pair(mn, mx)]++;
  }
  for(auto ele: cntA) {
    if(cntB[ele.first] != ele.second) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
