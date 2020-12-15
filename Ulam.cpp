/*Link: https://putka-upm.acm.si/tasks/t/ulam/ */
#include <queue>

#include <vector>

#include <iostream>

#include <cstring>

#include <fstream>

#include <algorithm>

#include <set>

#include <string>

#include <map>

#include <vector>

using namespace std;

const int inf = 1e6 + 9;

int arr[inf], n, a, b;

vector<int> ans;

 

int main() {

  cin >> n >> a >> b;

  ans.push_back(a), ans.push_back(b);

  arr[a + b] = 1;

  int cur = b;

  while (true) {

    cur++;

    while (cur <= n && arr[cur] != 1)cur++;

    if (cur > n)

      break;

    for (auto o : ans)

      if (o + cur <= n)

        arr[o + cur] ++;

    ans.push_back(cur);

  }

  int res = ans.size();

  for (int i = 0; i < res; ++i) {

    cout << ans[i] << " \n"[i == res - 1];

  }

}
