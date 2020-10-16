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
  vector<ll> A(n);
  set<pair<int, int>> se;
  rep(i, n) {
    cin >> A[i];
    se.emplace(A[i], i);
  }
  vector<ll> Acomp(n);
  auto itr = se.begin();
  rep(i, n) {
    Acomp[itr->second] = i;
    itr++;
  }
  // cout << Acomp << endl;
  vector<int> Q(n);
  rep(i, n) Q[Acomp[i]] = i;
  int mx = 1;
  int tmp = 1;
  rep(i, n) {
    if(i) {
      if(Q[i] > Q[i-1]) {
        tmp++;
      } else {
        mx = max(tmp, mx);
        tmp = 1;
      }
    }
  }
  mx = max(tmp, mx);
  cout << n - mx << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
