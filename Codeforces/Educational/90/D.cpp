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
  vector<ll> A(n), even(n+1), odd(n+1);
  rep(i, n) {
    cin >> A[i];
    if(i%2) {
      odd[i+1] = odd[i] + A[i];
      even[i+1] = even[i];
    } else {
      even[i+1] = even[i] + A[i];
      odd[i+1] = odd[i];
    }
  }
  ll mx = 0;
  vector<ll> diffMax(n+1);
  rrep(i, n+1) {
    if(i+2 > n) diffMax[i] = odd[i]-even[i];
    else diffMax[i] = max(diffMax[i+2], odd[i]-even[i]);
  }
  rep(i, n) {
    if(i+2 < n) {
      mx = max(diffMax[i+2]-(odd[i]-even[i]), mx);
    }
  }
  cout << even[n]+mx << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}

