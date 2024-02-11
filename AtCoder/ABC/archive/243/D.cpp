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
  int n; ll x; cin >> n >> x;
  string s; cin >> s;
  deque<int> q;
  rep(i, n) {
    if(q.empty() && s[i] == 'U') x /= 2;
    else {
      if(s[i] == 'U') {
        q.pop_back();
      } else {
        q.push_back(s[i]);
      }
    }
  }
  while(q.size()) {
    if(q.front() == 'R') {
      x = x*2+1;
    } else {
      x = x*2;
    }
    q.pop_front();
  }
  cout << x << endk;
  return 0;
}
