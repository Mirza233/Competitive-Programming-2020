//Link: https://putka-upm.acm.si/results/36451/


#include <iostream>

#include <vector>

#include <algorithm>

#include <set>

#include <map>

#include <string>

using namespace std;

int arr[1009];

int dp[1009];

 

int main() {

 

  int a;

  string line;

  getline(cin, line);

  int cur = 0;

  int cnt = 0;

  for (int i = 0; i < line.length(); ++i) {

    if ((line[i] < 48 || line[i]>57) && cur > 0) {

      arr[cnt++] = cur;

      cur = 0;

    } else {

      cur = cur * 10 + line[i] - '0';

    }

  }

  if (cur > 0) {

    arr[cnt++] = cur;

  }

  int best = 0;

  for (int i = 0; i < cnt; ++i) {

    dp[i] = 1;

    for (int j = 0; j < i; ++j) {

      if (arr[i] >= arr[j]) {

        dp[i] = max(dp[i], 1 + dp[j]);

      }

    }

    best = max(best, dp[i]);

  }

  cout << best<< endl;

}
