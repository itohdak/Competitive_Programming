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

string to_bin(int n) {
  string ret;
  rep(i, 8) {
    ret += '0'+n%2;
    n /= 2;
  }
  reverse(all(ret));
  return ret;
}
int rot(int n, int r) {
  int ret = 0;
  rep(i, 8) {
    ret += ((n>>((i+r)%8))&1)<<i;
  }
  return ret;
}
void solve() {
  vector<ld> prob(1<<8);
  rep(i, 1<<8) {
    if(i) {
      prob[i] = (ld)1/((1<<8)-1);
    }
  }
  while(1) {
    int r = max_element(all(prob))-begin(prob);
    cout << to_bin(r) << endl;
    int in; cin >> in;
    if(in == 0) {
      break;
    } else if(in == -1) {
      exit(0);
    } else {
      vector<ld> next_prob(1<<8);
      rep(i, 1<<8) {
        rep(j, 8) {
          int _rot = rot(r, j);
          int tmp = i ^ _rot;
          if(__builtin_popcount(tmp) == in) {
            next_prob[tmp] += prob[i] / 8;
          }
        }
      }
      ld sum = 0;
      rep(i, 1<<8) sum += next_prob[i];
      rep(i, 1<<8) next_prob[i] /= sum;
      prob = next_prob;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(i, t) {
    solve();
  }
  return 0;
}
