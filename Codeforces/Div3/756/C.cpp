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
  deque<int> A(n); rep(i, n) cin >> A[i];
  auto make = [&](deque<int> q, int t) -> deque<int> {
    deque<int> a;
    while(q.size() > 1) {
      if(q.front() > q.back()) {
        a.push_front(q.front());
        q.pop_front();
      } else {
        a.push_back(q.back());
        q.pop_back();
      }
    }
    if(t) {
      a.push_front(q.front());
      q.pop_front();
    } else {
      a.push_back(q.back());
      q.pop_back();
    }
    return a;
  };
  auto check = [&](deque<int> q, int t) -> bool {
    deque<int> a;
    while(q.size() > 1) {
      if(q.front() < q.back()) {
        a.push_front(q.front());
        q.pop_front();
      } else {
        a.push_back(q.back());
        q.pop_back();
      }
    }
    if(t) {
      a.push_front(q.front());
      q.pop_front();
    } else {
      a.push_back(q.back());
      q.pop_back();
    }
    rep(i, n) if(a[i] != A[i]) return false;
    return true;
  };
  rep(i, 2) {
    auto q = make(A, i);
    if(check(q, 0) || check(q, 1)) {
      rep(i, n) cout << q[i] << ' '; cout << endk;
      return;
    }
  }
  cout << -1 << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
