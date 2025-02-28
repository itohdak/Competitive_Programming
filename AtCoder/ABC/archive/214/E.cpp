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

void solve() {
  int n; cin >> n;
  vector<pair<int, int>> P(n);
  for(auto& [l, r]: P) {
    cin >> l >> r;
    l--;
  }
  // sort(all(P));
  vector<tuple<int, int, int>> A(2*n);
  rep(i, n) {
    A[2*i] = {P[i].first, 1, i};
    A[2*i+1] = {P[i].second, -1, i};
  }
  sort(all(A));
  priority_queue<int, vector<int>, greater<int>> q;
  int prev = 0;
  rep(i, 2*n) {
    auto [p, t, id] = A[i];
    int rem = p-prev;
    while(q.size() && rem) {
      q.pop(); rem--;
    }
    if(t == 1) q.push(P[id].second);
    else if(q.size() && q.top() <= p) {
      cout << "No" << endk;
      return;
    }
    prev = p;
  }
  cout << "Yes" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
