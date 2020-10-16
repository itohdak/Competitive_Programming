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
  vector<int> S(m), D(m), C(m);
  vector<int> ans(n);
  rep(i, m) {
    cin >> S[i] >> D[i] >> C[i];
    S[i]--; D[i]--;
    ans[D[i]] = m+1;
  }
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
  rep(i, n) {
    // cout << "Day " << i << endk;
    rep(j, m) if(S[j] == i) {
      // cout << "Add exam #" << j << endk;
      q.push(make_pair(D[j], make_pair(C[j], j)));
    }
    if(ans[i] == m+1) continue;
    if(q.empty()) {
      ans[i] = 0;
      continue;
    }
    int d = q.top().first;
    int rem = q.top().second.first;
    int j = q.top().second.second;
    q.pop();
    if(i > d) {
      cout << -1 << endk;
      return;
    }
    ans[i] = j+1;
    if(rem-1>0) q.push(make_pair(d, make_pair(rem-1, j)));
    // cout << ans << endk;
  }
  if(!q.empty()) {
    cout << -1 << endk;
    return;
  }
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
