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
  int n; cin >> n;
  deque<int> A(n);
  rep(i, n) cin >> A[i];
  while(A.size() >= 2 && A.front() == A.back()) {
    A.pop_front();
    A.pop_back();
  }
  if(A.size() <= 1) cout << "YES" << endk;
  else {
    auto check = [&](int del) {
      deque<int> tmp;
      for(auto a: A) if(a != del) tmp.push_back(a);
      while(tmp.size() >= 2 && tmp.front() == tmp.back()) {
        tmp.pop_front();
        tmp.pop_back();
      }
      return tmp.size() <= 1;
    };
    cout << (check(A.front()) || check(A.back()) ? "YES" : "NO") << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
