/*Link: https://putka-upm.acm.si/tasks/t/abs-resnica/*/

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

typedef long long ll;

const int mx = 109;

const int mod = 1e9 + 7;

string term;

enum Types {

  TRUE,

  FALSE,

  NOT,

  OR,

  AND,

  XOR

};

int add(int a, int b) {

  return (a + b) % mod;

}

int multiply(int a, int b) {

  return ((1ll * a) * b) % mod;

}

Types getType(string num) {

  if (num == "true") {

    return Types::TRUE;

  }

  if (num == "false") {

    return Types::FALSE;

  }

  if (num == "AND") {

    return Types::AND;

  }

  if (num == "OR") {

    return Types::OR;

  }

  if (num == "XOR") {

    return Types::XOR;

  }

  if (num == "NOT") {

    return Types::NOT;

  }

}

bool isUnary(Types type) {

  return type == Types::NOT;

}

bool isBinary(Types type) {

  return type == Types::OR || type == Types::AND || type == Types::XOR;

}

bool isValue(Types type) {

  return type == Types::TRUE || type == Types::FALSE;

}

int dp[mx][mx][2];

vector<Types> arr;

int calc(int st, int en, bool result) {

  if (st > en) {

    return 0;

  }

  if (dp[st][en][result] != -1) {

    return dp[st][en][result];

  }

  int ans = 0;

  if (st == en) {

    ans = (arr[st] == Types::TRUE && result) || (arr[st] == Types::FALSE && !result);

  } else if (st + 1 == en) {

    ans = arr[st] == Types::NOT &&

      ((arr[en] == Types::FALSE && result) ||

        (arr[en] == Types::TRUE && !result));

  } else {

    if (arr[st] == Types::NOT) {

      ans = add(ans, calc(st + 1, en, !result));

    }

    for (int i = st + 1; i <= en - 1; ++i) {

      if (isBinary(arr[i])) {

        int LT = calc(st, i - 1, true);

        int LF = calc(st, i - 1, false);

        int RT = calc(i + 1, en, true);

        int RF = calc(i + 1, en, false);

 

        if (arr[i] == Types::AND) {

          if (result) {

            ans = add(ans, multiply(LT, RT));

          } else {

            ans = add(ans, multiply(LT, RF));

            ans = add(ans, multiply(LF, RT));

            ans = add(ans, multiply(LF, RF));

          }

        } else if (arr[i] == Types::OR) {

          if (result) {

            ans = add(ans, multiply(LT, RT));

            ans = add(ans, multiply(LT, RF));

            ans = add(ans, multiply(LF, RT));

          } else {

            ans = add(ans, multiply(LF, RF));

          }

        } else if (arr[i] == Types::XOR) {

          if (result) {

            ans = add(ans, multiply(LT, RF));

            ans = add(ans, multiply(LF, RT));

          } else {

            ans = add(ans, multiply(LT, RT));

            ans = add(ans, multiply(LF, RF));

          }

        }

      }

    }

  }

  dp[st][en][result] = ans;

  return ans;

}

void read(string input) {

  auto cnt = 0;

  string cur = "";

  arr.clear();

  int idx = 0;

  for (auto chr : input) {

    if (chr == ' ') {

      arr.push_back(getType(cur));

      cur = "";

    } else {

      cur += chr;

    }

  }

  arr.push_back(getType(cur));

}

int main() {

  string line;

  while (getline(cin, line)) {

    read(line);

    memset(dp, -1, sizeof(dp));

    bool valid = true;

    bool needExpression = true;

    for (Types o : arr) {

      if (isValue(o)) {

        if (needExpression) {

          needExpression = !needExpression;

        } else {

          valid = false;

          break;

        }

      } else if (isUnary(o)) {

        if (!needExpression) {

          valid = false;

          break;

        }

      } else if (isBinary(o)) {

        if (!needExpression) {

          needExpression = !needExpression;

        } else {

          valid = false;

          break;

        }

      }

    }

    if (!valid || needExpression) {

      cout << "napaka\n";

    } else {

      cout << calc(0, arr.size() - 1, true) << endl;

    }

 

  }

}
