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
  int n, k; cin >> n >> k;
  vector<int> A(n); rep(i, n) cin >> A[i];
  map<int, vector<int>> pos;
  rep(i, n) pos[A[i]].push_back(i);
  vector<int> ans(n);
  vector<int> rem;
  for(auto& [a, v]: pos) {
    if((int)v.size() >= k) {
      rep(i, k) {
        ans[v.back()] = i+1;
        v.pop_back();
      }
    } else {
      for(auto p: v) rem.push_back(p);
    }
  }
  int i = 0;
  while(i+k <= (int)rem.size()) {
    rep(j, k) {
      ans[rem[i]] = i%k+1;
      i++;
    }
  }
  // cout << A << endk;
  // cout << ans << endk;
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
