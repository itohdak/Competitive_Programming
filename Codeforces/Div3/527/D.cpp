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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  int l = 0, r = 0;
  deque<int> p;
  while(l < n) {
    while(r < n && A[l]%2 == A[r]%2) r++;
    p.push_back(r-l);
    l = r;
  }
  deque<int> q;
  while(!p.empty()) {
    q.push_back(p.front());
    p.pop_front();
    while(q.back()%2 == 0) {
      int tmp = q.back(); q.pop_back();
      if(q.size()) {
        tmp += q.back();
        q.pop_back();
      }
      if(p.size()) {
        tmp += p.front();
        p.pop_front();
      }
      q.push_back(tmp);
      if(p.empty()) break;
    }
    // cout << q << endk;
  }
  if(q.size() == 1) cout << "YES" << endk;
  else cout << "NO" << endk;
  return 0;
}
