#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; cin >> n;
  vector<int> F(n);
  vector<int> from(n, -1);
  rep(i, n) {
    cin >> F[i];
    F[i]--;
    if(F[i] != -1) from[F[i]] = i;
  }
  vector<int> v0, vend, vstart;
  rep(i, n) {
    if(from[i] == -1 && F[i] == -1) v0.push_back(i);
    else if(F[i] == -1) vend.push_back(i);
    else if(from[i] == -1) vstart.push_back(i);
  }
  // cout << F << endk;
  // cout << from << endk;
  // cout << v0 << endk;
  // cout << vend << endk;
  // cout << vstart << endk;
  assert(vstart.size() == vend.size());
  rep(i, vstart.size()) {
    if(i) F[vend[i]] = vstart[i];
    else {
      int prev = vstart[i];
      for(int v: v0) {
        F[v] = prev;
        prev = v;
      }
      F[vend[i]] = prev;
    }
  }
  if(!vend.size()) {
    int prev = v0.back();
    for(int v: v0) {
      F[v] = prev;
      prev = v;
    }
  }
  rep(i, n) cout << F[i]+1 << ' '; cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
