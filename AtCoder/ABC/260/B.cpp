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
  int n, x, y, z; cin >> n >> x >> y >> z;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> B(n); rep(i, n) cin >> B[i];
  set<int> ans;
  vector<bool> done(n);
  vector<int> id;
  rep(i, n) if(!done[i]) id.push_back(i);
  sort(all(id), [&](int i, int j) {
    if(A[i] == A[j]) return i < j;
    else return A[i] > A[j];
  });
  rep(i, x) {
    ans.insert(id[i]);
    done[id[i]] = true;
  }

  id.clear();
  rep(i, n) if(!done[i]) id.push_back(i);
  sort(all(id), [&](int i, int j) {
    if(B[i] == B[j]) return i < j;
    else return B[i] > B[j];
  });
  rep(i, y) {
    ans.insert(id[i]);
    done[id[i]] = true;
  }

  id.clear();
  rep(i, n) if(!done[i]) id.push_back(i);
  sort(all(id), [&](int i, int j) {
    if(A[i]+B[i] == A[j]+B[j]) return i < j;
    else return A[i]+B[i] > A[j]+B[j];
  });
  rep(i, z) {
    ans.insert(id[i]);
    done[id[i]] = true;
  }

  for(auto i: ans) cout << i+1 << endk;
  return 0;
}
