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
  vector<int> A(n), B(n);
  rep(i, n) cin >> A[i];
  int one = 0, zero = 0;
  rep(i, n) {
    cin >> B[i];
    if(B[i]) one++;
    else     zero++;
  }
  if(one && zero) cout << "Yes" << endl;
  else {
    bool sorted = true;
    rep(i, n-1) if(A[i+1] < A[i]) sorted = false;
    cout << (sorted ? "Yes" : "No") << endl;
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
