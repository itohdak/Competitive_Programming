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
  vector<pair<string, int>> comms;
  bool prev_remove = false;
  int cnt = 0;
  rep(i, 2*n) {
    string comm; cin >> comm;
    if(comm == "add") {
      int a; cin >> a;
      if(prev_remove) {
        comms.push_back({"remove", cnt});
        cnt = 0;
      }
      comms.push_back({comm, a});
      prev_remove = false;
    } else {
      cnt++;
      prev_remove = true;
    }
  }
  if(prev_remove) comms.push_back({"remove", cnt});
  int next = 1;
  int ans = 0;
  deque<int> q;
  // cout << comms << endk;
  for(auto [comm, a]: comms) {
    if(comm == "add") {
      q.push_back(a);
    } else {
      bool ok = true;
      rep(i, a) {
        if(q.empty()) break;
        if(q.back() != next+i) ok = false;
        q.pop_back();
      }
      if(!ok) {
        ans++;
        q.clear();
      }
      next += a;
    }
  }
  cout << ans << endk;
  return 0;
}
