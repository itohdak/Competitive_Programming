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
  vector<int> A(n);
  set<int> st; rep(i, n) st.insert(i);
  rep(i, n-1) {
    cin >> A[i]; A[i]--;
    st.erase(A[i]);
  }
  int root = A[0];
  vector<pair<int, int>> ans;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  vector<int> mx(n); rep(i, n) mx[i] = i;
  for(int i: st) q.push({i, i});
  rrep(i, n-1) {
    auto top = q.top(); q.pop();
    while(top.first != mx[top.second] || top.second == A[i]) {
      top = q.top(); q.pop();
    }
    ans.push_back({A[i], top.second});
    chmax(mx[A[i]], top.first);
    if(A[i] != root) q.push({mx[A[i]], A[i]});
  }
  cout << root+1 << endk;
  rep(i, n-1) cout << ans[i].first+1 << ' ' << ans[i].second+1 << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
