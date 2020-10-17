#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

class StarsInTheSky {
public:
  int countPictures(int n, vector<int> X, vector<int> Y) {
    set<int> px, py;
    rep(i, n) px.insert(X[i]);
    rep(i, n) py.insert(Y[i]);
    vector<double> x, y;
    for(int X: px) {
      for(int Y: py) {
        for(int i=-1; i<=1; i++) {
          for(int j=-1; j<=1; j++) {
            x.push_back(X+i*0.5);
            y.push_back(Y+j*0.5);
          }
        }
      }
    }
    // rep(i, n) {
    //   for(int j=-1; j<=1; j++) {
    //     for(int k=-1; k<=1; k++) {
    //       x.push_back(X[i]+j*0.5);
    //       y.push_back(Y[i]+k*0.5);
    //     }
    //   }
    // }
    // x.push_back(-1); y.push_back(-1);
    // x.push_back(inf); y.push_back(inf);
    // cout << x << endl << y << endl;
    set<int> ans;
    int m = x.size();
    rep(i, m) REP(j, i, m) {
      int cur = 0;
      rep(k, n) {
        if(min(x[i], x[j])<=X[k] && X[k]<=max(x[i], x[j]) &&
           min(y[i], y[j])<=Y[k] && Y[k]<=max(y[i], y[j])) cur += (1<<k);
      }
      ans.insert(cur);
    }
    // cout << ans << "\n";
    return ans.size()-ans.count(0);
  }
};

int main() {
  cout << StarsInTheSky().countPictures(7,
                                      {0, 6, 2, 3, 4, 0, 6},
                                      {0, 0, 4, 5, 6, 10, 10}) << endl;
  return 0;
}
