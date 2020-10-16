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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  map<int, int> posA, posB;
  rep(i, n) {
    cin >> A[i];
    posA[A[i]] = i;
  }
  rep(i, n) {
    cin >> B[i];
    posB[B[i]] = i;
  }
  map<int, int> mp;
  for(int i=1; i<=n; i++) {
    mp[(posB[i] + n - posA[i]) % n]++;
  }
  int ans = 0;
  for(auto m: mp) {
    ans = max(m.second, ans);
  }
  cout << ans << endl;
  return 0;
}
