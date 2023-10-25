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
  vector<vector<int>> C(3, vector<int>(3));
  rep(i, 3) rep(j, 3) cin >> C[i][j];
  set<int> st;
  rep(i, 9) st.insert(i);
  vector<int> memo(9, -1);
  auto get = [&](int i, int j) {
    return memo[i*3+j];
  };
  auto check = [&](int cur) {
    auto check_sub = [](vector<int>& A) {
      assert(A.size() == 2);
      if(A[0] == -1 || A[1] == -1) return true;
      else return A[0] != A[1];
    };
    int x = cur/3, y = cur%3;
    {
      vector<int> tmp;
      rep(j, 3) {
	if(y != j) tmp.push_back(get(x, j));
      }
      if(!check_sub(tmp) && get(x, y) != tmp[0]) return false;
    }
    {
      vector<int> tmp;
      rep(i, 3) {
	if(x != i) tmp.push_back(get(i, y));
      }
      if(!check_sub(tmp) && get(x, y) != tmp[0]) return false;
    }
    if(x == y) {
      vector<int> tmp;
      rep(i, 3) {
	if(x != i) tmp.push_back(get(i, i));
      }
      if(!check_sub(tmp) && get(x, y) != tmp[0]) return false;
    }
    if(x+y == 2) {
      vector<int> tmp;
      rep(i, 3) {
	if(x != i) tmp.push_back(get(i, 2-i));
      }
      if(!check_sub(tmp) && get(x, y) != tmp[0]) return false;
    }
    return true;
  };
  int cnt = 0;
  auto dfs = [&](auto dfs, int cur) -> void {
    if(cur != -1 && !check(cur)) return;
    if(st.empty()) {
      cnt++;
      return;
    }
    auto tmp = st;
    for(int i: tmp) {
      int tmp2 = memo[i];
      memo[i] = C[i/3][i%3];
      st.erase(i);
      dfs(dfs, i);
      st.insert(i);
      memo[i] = tmp2;
    }
  };
  dfs(dfs, -1);
  int bumbo = 1;
  rep(i, 9) bumbo *= i+1;
  cout << fixed << setprecision(10) << (ld)1 * cnt / bumbo << endk;
  return 0;
}
