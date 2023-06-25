#include "header.hpp"

template<typename T>
vector<int> longest_increasing_subsequence(const vector<T>& a, bool strict=true) {
  vector<int> ret(a.size());
  vector<T> lis;
  rep(i, a.size()) {
    auto it = (strict ? lower_bound(all(lis), a[i]) : upper_bound(all(lis), a[i]));
    if(it == lis.end()) {
      lis.emplace_back(a[i]);
      ret[i] = lis.size();
    } else {
      *it = a[i];
      ret[i] = it - lis.begin() + 1;
    }
  }
  return ret;
}

int main() {
  int a[] = {1, 2, 5, 3, 4};
  vector<int> ve(a, a+5);
  auto ret = longest_increasing_subsequence(ve);
  cout << ret << endl; // {1, 2, 3, 3, 4}
  cout << *max_element(all(ret)) << endk; // 4
  return 0;
}
