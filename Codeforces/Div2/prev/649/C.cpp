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
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  vector<ll> B(n);
  rep(i, n) {
    if(A[i] > i+1) {
      cout << -1 << endl;
      return 0;
    }
  }
  set<ll> se;
  vector<int> dontUse(n+1);
  rrep(i, n) dontUse[A[i]]++;
  rep(i, n+1) if(dontUse[i] == 0) se.insert(i);
  rep(i, n) {
    if(se.empty()) {
      cout << -1 << endl;
      return 0;
    }
    B[i] = *se.begin();
    se.erase(se.begin());
    // if(A[i] != *se.begin()) {
    //   cout << -1 << endl;
    //   return 0;
    // }
    dontUse[A[i]]--;
    if(dontUse[A[i]] == 0) se.insert(A[i]);
  }
  rep(i, n) cout << B[i] << ' ';
  cout << endl;
  return 0;
}
