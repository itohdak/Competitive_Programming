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
  string s; cin >> s;
  deque<int> deq;
  auto getFront = [&](int pos) {
    if(pos > deq.size()) {
      cout << "ERROR" << endk;
    } else {
      vector<int> tmp;
      rep(i, pos) {
        tmp.push_back(deq.front());
        deq.pop_front();
      }
      int ret = tmp.back();
      tmp.pop_back();
      rep(i, pos-1) {
        deq.push_front(tmp.back());
        tmp.pop_back();
      }
      cout << ret << endk;
    }
  };
  auto getBack = [&](int pos) {
    if(pos > deq.size()) {
      cout << "ERROR" << endk;
    } else {
      vector<int> tmp;
      rep(i, pos) {
        tmp.push_back(deq.back());
        deq.pop_back();
      }
      int ret = tmp.back();
      tmp.pop_back();
      rep(i, pos-1) {
        deq.push_back(tmp.back());
        tmp.pop_back();
      }
      cout << ret << endk;
    }
  };
  rep(i, n) {
    if(s[i] == 'L') {
      deq.push_front(i+1);
    } else if(s[i] == 'R') {
      deq.push_back(i+1);
    } else if(s[i] == 'A') {
      getFront(1);
    } else if(s[i] == 'B') {
      getFront(2);
    } else if(s[i] == 'C') {
      getFront(3);
    } else if(s[i] == 'D') {
      getBack(1);
    } else if(s[i] == 'E') {
      getBack(2);
    } else if(s[i] == 'F') {
      getBack(3);
    } else {
      assert(false);
    }
  }
  return 0;
}
