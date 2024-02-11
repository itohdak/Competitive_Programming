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
  int n, k; cin >> n >> k;
  vector<int> T(n), Y(n);
  vector<int> pos;
  pos.push_back(-1);
  rep(i, n) {
    cin >> T[i] >> Y[i];
    if(T[i] == 1) pos.push_back(i);
  }
  reverse(all(pos));
  priority_queue<int> q;
  int l = n;
  int sz = k;
  ll sum = 0;
  ll ans = 0;
  {
    ll tmp = 0;
    rep(i, n) {
      if(T[i] == 1) tmp = Y[i];
      else tmp += Y[i];
    }
    ans = tmp;
  }
  if(k > 0) {
    for(int p: pos) {
      while(l-1 > p) {
        l--;
        if(Y[l] >= 0) {
          sum += Y[l];
        } else {
          if(q.size() == sz) {
            if(sz > 0 && Y[l] < q.top()) {
              sum += q.top();
              q.pop();
              q.push(Y[l]);
            } else {
              sum += Y[l];
            }
          } else {
            q.push(Y[l]);
          }
        }
      }
      chmax(ans, (p == -1 ? 0 : Y[p])+sum);
      l--;
      if(sz == 0) break;
      if(q.size() == sz) {
        sum += q.top();
        q.pop();
      }
      sz--;
    }
  }
  cout << ans << endk;
  return 0;
}
