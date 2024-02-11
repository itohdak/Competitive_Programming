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
  int h, w, n; cin >> h >> w >> n;
  vector<int> R(n), C(n), A(n);
  map<pair<int, int>, int> mp;
  priority_queue<pair<int, pair<int, int>>> q;
  rep(i, n) {
    cin >> R[i] >> C[i] >> A[i];
    R[i]--; C[i]--;
    mp[{R[i], C[i]}] = A[i];
    q.push({A[i], {R[i], C[i]}});
  }
  map<pair<int, int>, int> ans;
  vector<int> cntR(h), cntC(w);
  while(q.size()) {
    int tmpA = q.top().first;
    vector<pair<int, int>> tmp;
    while(q.size() && q.top().first == tmpA) {
      auto [a, p] = q.top(); q.pop();
      auto [r, c] = p;
      ans[{r, c}] = max(cntR[r], cntC[c]);
      tmp.push_back({r, c});
    }
    for(auto [r, c]: tmp) {
      chmax(cntR[r], ans[{r, c}]+1);
      chmax(cntC[c], ans[{r, c}]+1);
    }
  }
  rep(i, n) {
    cout << ans[{R[i], C[i]}] << endk;
  }
  return 0;
}
