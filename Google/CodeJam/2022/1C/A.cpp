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
  vector<string> S(n); rep(i, n) cin >> S[i];
  vector<vector<vector<int>>> pos(n, vector<vector<int>>(26));
  bool ok = true;
  rep(i, n) {
    rep(j, S[i].size()) {
      pos[i][S[i][j]-'A'].push_back(j);
    }
    rep(k, 26) {
      rep(l, pos[i][k].size()-1) {
        if(pos[i][k][l]+1 != pos[i][k][l+1]) ok = false;
      }
    }
  }
  if(!ok) {
    cout << "IMPOSSIBLE" << endk;
    return;
  }
  vector<vector<vector<int>>> A(26, vector<vector<int>>(3));
  rep(i, n) {
    bool same = true;
    rep(j, S[i].size()-1) if(S[i][j] != S[i][j+1]) same = false;
    if(same) {
      A[S[i][0]-'A'][2].push_back(i); // all same
    } else {
      A[S[i][0]-'A'][0].push_back(i); // begin with
      A[S[i].back()-'A'][1].push_back(i); // end with
    }
  }
  rep(i, 26) {
    if(A[i][0].size() > 1 || A[i][1].size() > 1) {
      cout << "IMPOSSIBLE" << endk;
      return;
    }
  }
  vector<bool> done(n);
  vector<bool> done2(26);
  string ans;
  rep(i, 26) {
    if(A[i][0].size() + A[i][1].size() + A[i][2].size() == 0) {
      done2[i] = true;
      continue;
    }
    if(!done2[i] && A[i][1].size() == 0) {
      for(int j: A[i][2]) {
        if(!done[j]) {
          ans += S[j];
          done[j] = true;
        }
      }
      for(int j: A[i][0]) {
        if(!done[j]) {
          ans += S[j];
          done[j] = true;
        }
      }
      done2[i] = true;
      int nx = ans.back()-'A';
      while(!done2[nx]) {
        for(int j: A[nx][1]) {
          if(!done[j]) {
            ans += S[j];
            done[j] = true;
          }
        }
        for(int j: A[nx][2]) {
          if(!done[j]) {
            ans += S[j];
            done[j] = true;
          }
        }
        for(int j: A[nx][0]) {
          if(!done[j]) {
            ans += S[j];
            done[j] = true;
          }
        }
        done2[nx] = true;
        nx = ans.back()-'A';
      }
    }
  }
  rep(i, n) {
    if(!done[i]) {
      cout << "IMPOSSIBLE" << endk;
      return;
    }
  }
  vector<bool> seen(26);
  rep(i, ans.size()) {
    if(i && ans[i] != ans[i-1] && seen[ans[i]-'A']) {
      cout << "IMPOSSIBLE" << endk;
      return;
    }
    seen[ans[i]-'A'] = true;
  }
  cout << ans << endk;
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
