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
  int n, m; cin >> n >> m;
  vector<int> K(n); rep(i, n) cin >> K[i];
  vector<int> D(m), T(m);
  vector<vector<int>> sale(n);
  rep(i, m) {
    cin >> D[i] >> T[i];
    D[i]--; T[i]--;
    sale[T[i]].push_back(D[i]);
  }
  rep(i, n) sort(all(sale[i]));
  auto bsearch = [&]() {
    auto test = [&](int t) {
      vector<int> k = K;
      vector<int> id(n), s(n);
      rep(i, n) {
        auto itr = upper_bound(all(sale[i]), t-1);
        if(itr == sale[i].begin()) s[i] = -1;
        else s[i] = *(--itr);
        id[i] = i;
      }
      sort(all(id), [&](int i, int j) {
        return s[i] < s[j];
      });
      int spent = 0;
      for(int i: id) {
        if(s[i] == -1) continue;
        int d = s[i];
        int buy = min(d+1-spent, k[i]);
        k[i] -= buy;
        spent += buy;
      }
      int rem = t-spent;
      return rem/2 >= accumulate(all(k), 0);
    };
    int ok = accumulate(all(K), 0) * 2, ng = 0;
    while(ok-ng>1) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
