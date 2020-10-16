#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct seg {
  int l;
  int r;
  int n;
  int ret;
  seg(int l, int r, int n) : l(l), r(r), n(n), ret(0) {}
};

#define MAX_N 100000

int par[MAX_N]; // 親の番号
int depth[MAX_N];

// n要素で初期化
void init(int n){
  for(int i=0; i<n; i++){
    par[i] = i;
    depth[i] = 0;
  }
}
// 木の根を求める
int root(int x){
  if(par[x] == x){ // 根
    return x;
  } else {
    return par[x] = root(par[x]); // 経路圧縮
  }
}

// xとyが同じ集合に属するか否か
bool same(int x, int y){
  return root(x) == root(y);
}

// xとyの属する集合を併合
void unite(int x, int y){
  x = root(x);
  y = root(y);
  if(x == y) return;

  if(depth[x] < depth[y]){
    par[x] = y;
  } else {
    par[y] = x;
    if(depth[x] == depth[y])
      depth[x]++;
  }
}

bool comp(seg s1, seg s2) {
  if(s1.r == s2.r)
    return s1.l < s2.l;
  else
    return s1.r < s2.r;
}
bool comp2(seg s1, seg s2) {
  return s1.n < s2.n;
}

int main(){
  int T;
  cin >> T;
  for(int q=0; q<T; q++) {
    int n;
    cin >> n;
    init(n);

    vector<seg> S;
    for(int i=0; i<n; i++) {
      int l, r;
      cin >> l >> r;
      S.push_back(seg(l, r, i));
    }
    sort(S.begin(), S.end(), comp);
    bool ret = false;
    int ans = 0;
    int i = n-1;
    while(i >= 0) {
      int j=1;
      while(i >= j && S[i].l <= S[i-j].r) {
    	unite(i, i-j);
    	j++;
      }
      i = i-j;
    }
    // for(int i=1; i<n; i++) {
    //   int j=1;
    //   while(i >= j && S[i].l <= S[i-j].r) {
    // 	unite(i, i-j);
    // 	j++;
    //   }
    // }
    int first = root(0);
    S[0].ret = 1;
    bool all_same = true;
    for(int i=1; i<n; i++) {
      if(root(i) != first) {
	all_same = false;
	S[i].ret = 2;
      } else {
	S[i].ret = 1;
      }
    }
    if(all_same) {
      cout << -1 << endl;
    } else {
      sort(S.begin(), S.end(), comp2);
      for(int i=0; i<n; i++)
	cout << S[i].ret << ' ';
      cout << endl;
    }
  }
  return 0;
}
