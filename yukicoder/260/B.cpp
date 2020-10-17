#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  int s, t; cin >> s >> t;
  s--; t--;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> sumR(n+1), sumL(n+1);
  rep(i, n) sumR[i+1] = sumR[i]+A[i];
  rep(i, n) sumL[n-i-1] = sumL[n-i]+A[n-i-1];
  cout << sumR << sumL << endk;
  return 0;
}
