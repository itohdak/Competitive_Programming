#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int n, m, k;
  ll ta, tb;
  cin >> n >> m >> ta >> tb >> k;
  vector<ll> A(n), B(m), C(n);
  rep(i, n) cin >> A[i];
  rep(i, m) cin >> B[i];
  int j=0;
  while(j<m && B[j]<A[0]+ta) j++;
  if(j==m) { cout << -1 << endl; return 0; }
  if(n<=k || m-j<=k) { cout << -1 << endl; return 0; }
  rep(i, n) {
    while(j<m && B[j]<A[i]+ta)
      j++;
    C[i] = j;
  }
  ll ans = -1;
  rep(i, k+1) {
    ans = max(B[min(C[i]+k-i, (ll)m-1)]+tb, ans);
  }
  cout << ans << endl;
  return 0;
}

