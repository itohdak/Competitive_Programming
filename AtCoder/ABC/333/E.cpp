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
  vector<int> T(n), X(n);
  map<int, set<int>> portion;
  map<int, set<int>> enemy;
  rep(i, n) {
    int t, x; cin >> t >> x;
    T[i] = t, X[i] = x;
    if(t == 1) {
      portion[x].insert(i);
    } else {
      enemy[x].insert(i);
    }
  }
  set<int> st;
  bool ok = true;
  for(auto& [k, v]: enemy) {
    if(!portion.count(k)) {
      ok = false;
      break;
    }
    for(int p: v) {
      auto itr = portion[k].upper_bound(p);
      if(itr == portion[k].begin()) {
        ok = false;
        break;
      } else {
        --itr;
        st.insert(*itr);
        portion[k].erase(itr);
      }
    };
    if(!ok) {
      break;
    }
  }
  if(!ok) {
    cout << -1 << endk;
  } else {
    int ans = 0;
    int tmp = 0;
    vector<int> A;
    rep(i, n) {
      if(T[i] == 1) {
        if(st.count(i)) {
          tmp++;
          A.push_back(1);
        } else {
          A.push_back(0);
        }
      } else {
        tmp--;
      }
      chmax(ans, tmp);
    }
    cout << ans << endk;
    rep(i, A.size()) cout << A[i] << ' ';
    cout << endk;
  }
  return 0;
}
