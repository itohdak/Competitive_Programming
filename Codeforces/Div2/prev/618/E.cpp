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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> sum(n+1);
  rep(i, n) sum[i+1] = sum[i] + A[i];
  deque<pair<ll, int>> q;
  rep(i, n) {
    q.push_back({A[i], 1});
    while(q.size() >= 2) {
      auto p1 = *q.rbegin();
      auto p2 = *(++q.rbegin());
      if(p1.first * p2.second <= p2.first * p1.second) {
        q.pop_back(); q.pop_back();
        q.push_back({p1.first+p2.first, p1.second+p2.second});
      } else {
        break;
      }
    }
  }
  vector<ld> ans(n);
  {
    int i = 0;
    while(!q.empty()) {
      ll sum = q.front().first;
      int cnt = q.front().second;
      q.pop_front();
      rep(j, cnt) ans[i++] = (ld)sum / cnt;
    }
  }
  cout << fixed << setprecision(15);
  rep(i, n) cout << ans[i] << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
