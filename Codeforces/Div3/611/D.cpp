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
  vector<ll> X(n);
  set<ll> st;
  priority_queue<pair<ll, ll>> q;
  rep(i, n) {
    cin >> X[i];
    st.insert(X[i]);
  }
  rep(i, n) {
    if(!st.count(X[i]-1)) q.push({-1, X[i]-1});
    if(!st.count(X[i]+1)) q.push({-1, X[i]+1});
  }
  vector<ll> ans;
  ll sum = 0;
  while((int)ans.size() < m) {
    auto top = q.top(); q.pop();
    if(st.count(top.second)) continue;
    sum += -top.first;
    ans.push_back(top.second);
    st.insert(top.second);
    if(!st.count(top.second-1)) q.push({top.first-1, top.second-1});
    if(!st.count(top.second+1)) q.push({top.first-1, top.second+1});
  }
  cout << sum << endk;
  rep(i, m) cout << ans[i] << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
