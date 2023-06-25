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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

template<typename T>
vector<T> slide_min(const vector<T>& v, int k) {
  deque<int> deq;
  vector<T> ret;
  for(int i=0; i<v.size(); i++) {
    while(!deq.empty() && v[deq.back()] >= v[i]) deq.pop_back();
    deq.push_back(i);
    if(i-k+1 >= 0) {
      ret.push_back(v[deq.front()]);
      if(deq.front() == i-k+1) deq.pop_front();
    }
  }
  return ret;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, a, b; cin >> n >> m >> a >> b;
  ll g0, x, y, z; cin >> g0 >> x >> y >> z;
  int tmp = g0;
  vector<vector<int>> H(n, vector<int>(m));
  rep(i, n) rep(j, m) {
    H[i][j] = tmp;
    tmp = (tmp * x + y) % z;
  }
  vector<vector<int>> mins;
  rep(i, n) {
    mins.push_back(slide_min(H[i], b));
  }
  // cout << mins << endl;
  ll ans = 0;
  rep(j, mins[0].size()) {
    vector<int> tmp;
    rep(i, mins.size()) tmp.push_back(mins[i][j]);
    // cout << tmp << endl;
    auto ret = slide_min(tmp, a);
    // cout << ret << endl;
    ans += accumulate(all(ret), 0LL);
  }
  cout << ans << endk;
  return 0;
}
