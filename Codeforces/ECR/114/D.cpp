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
  vector<vector<int>> A(n);
  rep(i, n) {
    int c; cin >> c;
    A[i] = vector<int>(c);
    rep(j, c) {
      cin >> A[i][j];
    }
  }
  int m; cin >> m;
  vector<vector<int>> B(m, vector<int>(n));
  set<vector<int>> stB;
  rep(i, m) {
    vector<int> v;
    rep(j, n) {
      cin >> B[i][j];
      B[i][j]--;
      v.push_back(B[i][j]);
    }
    stB.insert(v);
  }
  using P = pair<ll, vector<int>>;
  priority_queue<P, vector<P>, greater<P>> q;
  q.push({0, vector<int>()});
  rep(i, n) {
    vector<P> tmp;
    while(q.size()) {
      auto top = q.top(); q.pop();
      tmp.push_back(top);
    }
    reverse(all(tmp));
    priority_queue<P, vector<P>, greater<P>> next;
    for(int j=A[i].size()-1; j>=0; j--) {
      for(auto [sum, v]: tmp) {
        if(next.size() > m+1) {
          if(sum+A[i][j] <= next.top().first) break;
          next.pop();
        }
        v.push_back(j);
        P ne = {sum+A[i][j], v};
        next.push(ne);
      }
    }
    q = next;
  }
  vector<P> tmp;
  while(q.size()) {
    auto top = q.top(); q.pop();
    tmp.push_back(top);
  }
  reverse(all(tmp));
  for(auto [_, v]: tmp) {
    if(!stB.count(v)) {
      for(int i: v) {
        cout << i+1 << ' ';
      }
      cout << endk;
      return;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
