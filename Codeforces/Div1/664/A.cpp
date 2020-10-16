#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
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

void solve() {
  int n, d; ll m; cin >> n >> d >> m;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> vh, vl;
  rep(i, n) {
    if(A[i] > m) vh.push_back(A[i]);
    else vl.push_back(A[i]);
  }
  sort(all(vh), greater<ll>());
  sort(all(vl), greater<ll>());
  int nh = vh.size();
  int nl = vl.size();
  vector<ll> sumh(nh+1), suml(nl+1);
  rep(i, nh) sumh[i+1] = sumh[i] + vh[i];
  rep(i, nl) suml[i+1] = suml[i] + vl[i];
  ll ans = 0;
  rep(i, nh+1) { // use
    int rem = nh-i; // unuse
    ll need = max(max(i-1, 0)*(ll)d-rem, 0LL);
    rem = max(rem-max(i-1, 0)*(ll)d, 0LL);
    if(need > nl) continue;
    ll tmp = 0;
    tmp += suml[nl-need];
    if(rem-d < 0) tmp += sumh[i];
    else tmp += sumh[min(i+rem/(d+1), nh)];
    ans = max(tmp, ans);
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
