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

  std::string input;
  std::vector<vector<int>> result;

  bool end = false;
  while (!end && std::getline(std::cin, input)) {
    if (input.empty()) continue;

    if (input[input.size()-1] == ',') {
      input.erase(0, 1);
      input.erase(input.size() - 2 , 2);
    } else {
      input.erase(0, 1);
      input.erase(input.size() - 1 , 1);
      end = true;
    }

    std::stringstream ss(input);
    vector<int> v;
    rep(i, 75) {
      string numStr;
      std::getline(ss, numStr, ',');
      int val = std::stoi(numStr);
      v.push_back(val);
    }
    result.push_back(v);
  }

  bool first = true;
  for (const auto v: result) {
    vector<vector<int>> g(5, vector<int>(5));
    rep(i, 25) {
      g[i/5][i%5] = v[i];
    }
    vector<int> num;
    REP(i, 25, v.size()) num.push_back(v[i]);

    vector<int> C(5), R(5); // 各行・各列にいくつ丸があるか
    int d1 = 0, d2 = 0; // 斜めにいくつ丸があるか
    map<int, pair<int, int>> mp; // 残っている数
    int free = 0; // 自由における丸の数
    int ans = 0;
    int sum = 0;

    rep(i, 5) rep(j, 5) {
      mp[g[i][j]] = {i, j};
      sum += g[i][j];
    }

    auto check = [&]() {
      rep(i, 5) {
        if(C[i] + free >= 5) {
          int tmp = sum;
          int tmpFree = free;
          auto tmpMp = mp;
          rep(j, 5) {
            if(tmpMp.count(g[j][i])) {
              tmp -= g[j][i];
              tmpFree--;
              tmpMp.erase(g[j][i]);
            }
          }
          assert(tmpFree >= 0);
          if(tmpMp.size() >= tmpFree) {
            while(tmpFree) {
              tmpFree--;
              tmp -= tmpMp.begin()->first;
              tmpMp.erase(tmpMp.begin());
            }
            chmax(ans, tmp);
          }
        }
        if(R[i] + free >= 5) {
          int tmp = sum;
          int tmpFree = free;
          auto tmpMp = mp;
          rep(j, 5) {
            if(tmpMp.count(g[i][j])) {
              tmp -= g[i][j];
              tmpFree--;
              tmpMp.erase(g[i][j]);
            }
          }
          assert(tmpFree >= 0);
          if(tmpMp.size() >= tmpFree) {
            while(tmpFree) {
              tmpFree--;
              tmp -= tmpMp.begin()->first;
              tmpMp.erase(tmpMp.begin());
            }
            chmax(ans, tmp);
          }
        }
      }
      if(d1 + free >= 5) {
          int tmp = sum;
          int tmpFree = free;
          auto tmpMp = mp;
          rep(i, 5) {
            if(tmpMp.count(g[i][i])) {
              tmp -= g[i][i];
              tmpFree--;
              tmpMp.erase(g[i][i]);
            }
          }
          assert(tmpFree >= 0);
          if(tmpMp.size() >= tmpFree) {
            while(tmpFree) {
              tmpFree--;
              tmp -= tmpMp.begin()->first;
              tmpMp.erase(tmpMp.begin());
            }
            chmax(ans, tmp);
          }
      }
      if(d2 + free >= 5) {
        int tmp = sum;
        int tmpFree = free;
        auto tmpMp = mp;
        rep(i, 5) {
          if(tmpMp.count(g[i][4-i])) {
            tmp -= g[i][4-i];
            tmpFree--;
            tmpMp.erase(g[i][4-i]);
          }
        }
        assert(tmpFree >= 0);
        if(tmpMp.size() >= tmpFree) {
          while(tmpFree) {
            tmpFree--;
            tmp -= tmpMp.begin()->first;
            tmpMp.erase(tmpMp.begin());
          }
          chmax(ans, tmp);
        }
      }
    };

    int sleep = 0;
    for(int n: num) {
      if(mp.count(n)) {
        auto [r, c] = mp[n];
        R[r]++;
        C[c]++;
        if(r == c) d1++;
        if(r + c == 4) d2++;
        mp.erase(n);
        sum -= n;
        sleep = 0;
      } else {
        sleep++;
        if(sleep == 3) {
          free++;
          sleep = 0;
        }
      }
      check();
    }

    if(!first) {
      cout << ",";
    }
    cout << ans;
    first = false;
  }
  cout << endk;

  return 0;
}
