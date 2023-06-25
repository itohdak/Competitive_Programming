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
const ll mod = 998244353;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  vector<ll> B(m);
  rep(i, m) cin >> B[i];
  vector<int> mnl(m+1), mnr(m+1);
  mnr[m] = n;
  bool ok = true;
  int tmp = 0;
  rep(i, m) {
    while(tmp < n && A[tmp] != B[i]) {
      if(A[tmp] < B[i]) {
        if(i) {
          if(A[tmp] < B[i-1]) {
            ok = false;
          } else {
            mnl[i] = tmp;
          }
        } else {
          ok = false;
        }
      }
      tmp++;
    }
    if(tmp == n) {
      ok = false;
      break;
    }
    mnl[i+1] = tmp;
  }
  tmp = n-1;
  rrep(i, m) {
    while(tmp >= 0 && A[tmp] != B[i]) {
      if(A[tmp] < B[i]) {
        if(m-1-i) {
          if(A[tmp] < B[i+1]) {
            ok = false;
          } else {
            mnr[i+1] = tmp;
          }
        } else {
          ok = false;
        }
      }
      tmp--;
    }
    if(tmp == -1) {
      ok = false;
      break;
    }
    mnr[i] = tmp;
  }
  if(!ok) {
    cout << 0 << endl;
    return 0;
  }
  // cout << mnl << ' ' << mnr << endl;
  ll ans = 1;
  rep(i, m-1) (ans *= (mnr[i+1]-mnl[i+1])) %= mod;
  cout << ans << endl;
  return 0;
}
