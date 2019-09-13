#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:

  bool isLeap(int year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 100));
  }

  int daysInMonth(int month, int year) {
    const int daysOfMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2)
      return isLeap(year) ? 29 : 28;
    return daysOfMonth[month - 1];
  }

  // January 1, 1971 -- Friday
  string dayOfTheWeek(int day, int month, int year) {
    const string weekday[]{"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
    int total = 0;
    for (int i = 1971; i < year; ++i) {
      total += isLeap(i) ? 366 : 365;
    }
    for (int i = 1; i < month; ++i) {
      total += daysInMonth(i, year);
    }
    total += day;
    total = total % 7;

    return weekday[total];
  }
};

void test1() {

  int day = 1, month = 1, year = 1971;

  cout << "Friday ? " << Solution().dayOfTheWeek(day, month, year) << endl;

  day = 1, month = 1, year = 1972;

  cout << "Saturday ? " << Solution().dayOfTheWeek(day, month, year) << endl;

  day = 31, month = 8, year = 2019;
  cout << "Saturday ? " << Solution().dayOfTheWeek(day, month, year) << endl;

  day = 15, month = 8, year = 1993;
  cout << "Sunday ? " << Solution().dayOfTheWeek(day, month, year) << endl;

  day = 22, month = 8, year = 1993;
  cout << "Sunday ? " << Solution().dayOfTheWeek(day, month, year) << endl;

  day = 29, month = 8, year = 1993;
  cout << "Sunday ? " << Solution().dayOfTheWeek(day, month, year) << endl;

  day = 24, month = 9, year = 1993;
  cout << "Friday ? " << Solution().dayOfTheWeek(day, month, year) << endl;

}

void test2() {

}

void test3() {

}