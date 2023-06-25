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
  vector<ll> X(n), Y(n);
  vector<ll> Xc(n+1), Yc(n+1);
  rep(i, n) cin >> X[i] >> Y[i];
  rep(i, n+1) cin >> Xc[i] >> Yc[i];
  if(n > 10) {
    cout << "IMPOSSIBLE" << endk;
    return;
  }
  vector<vector<pair<ll, int>>> A(n);
  rep(i, n) {
    rep(j, n+1) {
      ll d = (X[i]-Xc[j])*(X[i]-Xc[j]) + (Y[i]-Yc[j])*(Y[i]-Yc[j]);
      A[i].push_back({d, -j});
    }
    sort(all(A[i]));
  }
  vector<int> id(n);
  iota(all(id), 1);
  do {
    vector<ll> need(n);
    bool ok = true;
    rep(i, n) {
      int j = id[i];
      ll d = (X[i]-Xc[j])*(X[i]-Xc[j]) + (Y[i]-Yc[j])*(Y[i]-Yc[j]);
      rep(j, n+1) {
        if(A[i][j].first >= d) {
          break;
        } else {
          if(A[i][j].second == 0) {
            ok = false;
            break;
          }
          need[i] |= 1LL<<(-A[i][j].second);
        }
      }
      if(!ok) break;
    }
    if(!ok) continue;
    vector<int> done2(n);
    int cnt = 0;
    vector<int> ans;
    ll done = (1LL<<(n+1))-1-1;
    rep(_, n) {
      int prev = cnt;
      rep(i, n) {
        if(!done2[i] && (need[i] & done) == 0) {
          ans.push_back(i);
          cnt++;
          done ^= 1LL<<id[i];
          done2[i] = true;
        }
      }
      if(cnt == prev) break;
      if(cnt == n) break;
    }
    if(cnt == n) {
      assert(ans.size() == n);
      cout << "POSSIBLE" << endk;
      rep(i, n) {
        cout << ans[i]+1 << ' ' << id[i]+1 << endk;
      }
      return;
    }
  } while(next_permutation(all(id)));
  cout << "IMPOSSIBLE" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(i, t) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
