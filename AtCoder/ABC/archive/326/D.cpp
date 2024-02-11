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
  string r, c; cin >> r >> c;
  bool done = false;
  vector<string> A(n, string(n, '.'));
  map<char, pair<char, char>> mp = {
    {'A', {'B', 'C'}},
    {'B', {'A', 'C'}},
    {'C', {'A', 'B'}}
  };
  auto judge = [&]() -> bool {
    bool ok = true;
    rep(j, n) {
      char first = '.';
      map<char, int> cnt;
      rep(i, n) {
	if(first == '.' && A[i][j] != '.') {
	  first = A[i][j];
	}
	cnt[A[i][j]]++;
      }
      ok &= (cnt['A'] == 1 && cnt['B'] == 1 && cnt['C'] == 1);
      ok &= (first == c[j]);
    }
    return ok;
  };
  auto dfs = [&](auto dfs, int cur) -> void {
    // cout << cur << endl;
    // cout << A << endl;
    if(cur == n) {
      if(judge()) {
	done = true;
      }
      return;
    }
    rep(i, n) {
      REP(j, i+1, n) {
	REP(k, i+1, n) {
	  if(j == k) continue;
	  string tmp = A[cur];
	  A[cur][i] = r[cur];
	  A[cur][j] = mp[r[cur]].first;
	  A[cur][k] = mp[r[cur]].second;
	  dfs(dfs, cur+1);
	  if(done) return;
	  A[cur] = tmp;
	}
      }
    }
  };
  dfs(dfs, 0);
  if(done) {
    cout << "Yes" << endk;
    rep(i, n) {
      cout << A[i] << endk;
    }
  } else {
    cout << "No" << endk;
  }
  return 0;
}
