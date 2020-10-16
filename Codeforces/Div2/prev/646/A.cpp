#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
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
  int n, x;
  cin >> n >> x;
  vector<int> A(n);
  int odd = 0, even = 0;
  rep(i, n) {
    cin >> A[i];
    if(A[i]%2) odd++;
    else even++;
  }
  for(int i=1; i<=odd; i+=2) {
    if(x-i < 0) break;
    if(even >= x-i) {
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
