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
  int h, w, x; cin >> h >> w >> x;
  if((x-(h+w-2))%4) {
    cout << -1 << endk;
    return 0;
  }
  vector<string> ans(h, string(w, '#'));
  for(int i=0; i<h; i+=2) {
    for(int j=0; j<w; j+=2) {
      ans[i][j] = '.';
    }
  }
  rep(i, h) ans[i][0] = '.';
  rep(j, w) ans[h-1][j] = '.';
  auto add_up = [&](pair<int, int> right_down, int upper_limit, int rem) {
    auto [x, y] = right_down;
    while(rem && x-2 >= upper_limit) {
      // #.#    ...
      // ### -> .#.
      // ...    .#.
      ans[x-1][y] = ans[x-2][y] = ans[x-1][y-2] = ans[x-2][y-2] = ans[x-2][y-1] = '.';
      ans[x][y-1] = '#';
      rem--;
      x -= 2;
    }
    return rem;
  };
  auto add_right = [&](pair<int, int> left_up, int right_limit, int rem) {
    auto [x, y] = left_up;
    while(rem && y+2 < right_limit) {
      // .#.    ...
      // .## -> ##.
      // .#.    ...
      ans[x][y+1] = ans[x][y+2] = ans[x+2][y+1] = ans[x+2][y+2] = ans[x+1][y+2] = '.';
      ans[x+1][y] = '#';
      rem--;
      y += 2;
    }
    return rem;
  };
  auto answer = [&]() {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for(int i=0; i<h; i+=2) {
      for(int j=0; j<w; j+=2) {
        bool ok = false;
        rep(k, 4) {
          int nx = i+dx[k];
          int ny = j+dy[k];
          if(nx >= 0 && nx < h && ny >= 0 && ny < w && ans[nx][ny] == '.') ok = true;
        }
        if(!ok) {
          int tmpj = j-1;
          while(tmpj >= 0 && ans[i][tmpj] == '#') {
            ans[i][tmpj--] = '.';
          }
        }
      }
    }
    rep(i, h) cout << ans[i] << endk;
  };
  int rem = (x-(h+w-2))/4;
  int hh = (h-1)/2%2, ww = (w-1)/2%2;
  if(hh && ww) {
    for(int j=w-1; j-2>=2; j-=4) {
      rem = add_up({h-1, j}, 0, rem);
      if(rem == 0) break;
    }
    for(int i=0; i+2<h-2; i+=4) {
      rem = add_right({i, 0}, 3, rem);
      if(rem == 0) break;
    }
  } else if(hh) {
    for(int j=w-1; j-2>=2; j-=4) {
      rem = add_up({h-1, j}, 0, rem);
      if(rem == 0) break;
    }
  } else if(ww) {
    for(int i=0; i+2<h-2; i+=4) {
      rem = add_right({i, 0}, w, rem);
      if(rem == 0) break;
    }
  } else {
    for(int j=w-1; j-2>=2; j-=4) {
      rem = add_up({h-1, j}, 0, rem);
      if(rem == 0) break;
    }
  }
  if(rem) {
    cout << -1 << endk;
  } else {
    answer();
  }
  return 0;
}
