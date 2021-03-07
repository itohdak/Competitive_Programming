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
  int n, m; cin >> n >> m;
  vector<int> A(n), B(n), C(m);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  map<int, vector<int>> mp;
  rep(i, m) {
    cin >> C[i];
    mp[C[i]].push_back(i);
  }
  for(auto& ele: mp) reverse(all(ele.second));
  vector<int> ans(m, -1);
  rrep(i, n) {
    if(A[i] != B[i]) {
      if(!mp.count(B[i])) {
        cout << "NO" << endk;
        return;
      }
      ans[mp[B[i]].back()] = i;
      mp[B[i]].pop_back();
      if(mp[B[i]].empty()) {
        mp.erase(B[i]);
      }
    }
  }
  int prev = -1;
  map<int, int> mp2;
  rep(i, n) mp2[B[i]] = i;
  rrep(i, m) {
    if(ans[i] == -1) {
      if(prev != -1) {
        ans[i] = prev;
      } else if(mp2.count(C[i])) {
        ans[i] = mp2[C[i]];
      } else {
        cout << "NO" << endk;
        return;
      }
    }
    prev = ans[i];
  }
  cout << "YES" << endk;
  rep(i, m) cout << ans[i]+1 << ' ';
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
