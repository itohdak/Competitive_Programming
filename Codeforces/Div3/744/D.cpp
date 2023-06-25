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
  priority_queue<pair<int, int>> q;
  vector<int> A(n);
  rep(i, n) {
    cin >> A[i];
    if(A[i]) q.push({A[i], i});
  }
  vector<pair<int, int>> ans;
  while(q.size() >= 2) {
    auto [a1, i] = q.top(); q.pop();
    auto [a2, j] = q.top(); q.pop();
    ans.push_back({i, j});
    if(a1-1) q.push({a1-1, i});
    if(a2-1) q.push({a2-1, j});
  }
  cout << ans.size() << endk;
  for(auto [u, v]: ans) cout << u+1 << ' ' << v+1 << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
