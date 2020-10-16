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
  int n; cin >> n;
  vector<ll> A(n);
  string s[] = {"First", "Second"};
  rep(i, n) cin >> A[i];
  int flag = 0;
  int l = 0;
  rep(i, n) {
    if(A[i] == 1) {
      l++;
      flag = 1-flag;
    } else {
      break;
    }
  }
  if(l == n) {
    cout << s[1-flag] << "\n";
  } else {
    cout << s[flag] << "\n";
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
