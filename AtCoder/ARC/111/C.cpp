#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> A(n), B(n);
  vector<int> P(n), Pinv(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  rep(i, n) {
    cin >> P[i];
    P[i]--;
    Pinv[P[i]] = i;
  }
  rep(i, n) {
    if(P[i] != i && A[i] <= B[P[i]]) {
      cout << -1 << endk;
      return 0;
    }
  }
  priority_queue<pair<ll, int>> q;
  rep(i, n) q.push({-A[i], i});
  vector<pair<int, int>> ans;
  while(q.size()) {
    auto [_, i] = q.top(); q.pop();
    if(P[i] == i) continue;
    ans.push_back({i, Pinv[i]});
    Pinv[P[i]] = Pinv[i];
    swap(P[i], P[Pinv[i]]);
    Pinv[i] = i;
  }
  cout << ans.size() << endk;
  for(auto [p1, p2]: ans) cout << p1+1 << ' ' << p2+1 << endk;
  return 0;
}
