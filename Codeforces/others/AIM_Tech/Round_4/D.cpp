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

int cnt = 0;
pair<ll, int> query(int p) {
  if(cnt == 2000) exit(0);
  cnt++;
  cout << "? " << p+1 << endl;
  ll val; int next; cin >> val >> next;
  if(val == -1) exit(0);
  if(next != -1) next--;
  return {val, next};
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, start; ll x; cin >> n >> start >> x;
  start--;
  random_device rnd;
  mt19937 mt(rnd());
  mt.seed(rand());
  uniform_int_distribution<> randn(0, inf);
  vector<pair<ll, int>> A;
  set<int> st;
  {
    auto ret = query(start);
    A.push_back(ret);
    st.insert(start);
  }
  rep(i, min(n-1, 1000)) {
    int r = randn(mt)%n;
    while(st.count(r)) r = randn(mt)%n;
    auto ret = query(r);
    A.push_back(ret);
    st.insert(r);
  }
  sort(all(A));
  int i = 0;
  while(i < (int)A.size() && A[i].first < x) i++;
  if(i == 0) {
    cout << "! " << A[0].first << endl;
    return 0;
  }
  i--;
  auto [tmp, next] = A[i];
  while(tmp < x) {
    if(next == -1) {
      cout << "! -1" << endl;
      return 0;
    }
    auto ret = query(next);
    tmp = ret.first;
    next = ret.second;
  }
  cout << "! " << tmp << endl;
  return 0;
}
