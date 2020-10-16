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
  int a, b, c, d; cin >> a >> b >> c >> d;
  auto no = []() {
    cout << "NO" << endk;
    exit(0);
  };
  if(a == 0 && b == 0) {
    if(abs(c-d) > 1) no();
    deque<int> q;
    rep(i, min(c, d)) {
      q.push_back(3);
      q.push_back(4);
    }
    if(d > c) q.push_front(4);
    if(c > d) q.push_back(3);
    assert((int)q.size() == a+b+c+d);
    cout << "YES" << endk;
    rep(i, a+b+c+d) cout << q[i]-1 << ' ';
    cout << endk;
    return;
  }
  if(c == 0 && d == 0) {
    if(abs(a-b) > 1) no();
    deque<int> q;
    rep(i, min(a, b)) {
      q.push_back(1);
      q.push_back(2);
    }
    if(b > a) q.push_front(2);
    if(a > b) q.push_back(1);
    assert((int)q.size() == a+b+c+d);
    cout << "YES" << endk;
    rep(i, a+b+c+d) cout << q[i]-1 << ' ';
    cout << endk;
    return;
  }
  if(b < a) no();
  if(c < d) no();
  if(abs((b-a)-(c-d)) > 1) no();
  deque<int> q;
  rep(i, a) {
    q.push_back(1);
    q.push_back(2);
  }
  rep(i, min(b-a, c-d)) {
    q.push_back(3);
    q.push_back(2);
  }
  rep(i, d) {
    q.push_back(3);
    q.push_back(4);
  }
  if(b-a > c-d) {
    q.push_front(2);
  }
  if(b-a < c-d) {
    q.push_back(3);
  }
  assert((int)q.size() == a+b+c+d);
  cout << "YES" << endk;
  rep(i, a+b+c+d) cout << q[i]-1 << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
