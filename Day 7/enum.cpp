#include <iostream>
#include <string>

using namespace std;

// 定义一个传统的枚举类型，用于表示一天的时间段
enum DayPeriod {
    MORNING,   // 早上
    AFTERNOON, // 下午
    EVENING,   // 晚上
    NIGHT      // 夜间
};

// 定义一个基于 C++11 的 `enum class`，用于表示星期几
enum class Weekday {
    MONDAY,    // 周一
    TUESDAY,   // 周二
    WEDNESDAY, // 周三
    THURSDAY,  // 周四
    FRIDAY,    // 周五
    SATURDAY,  // 周六
    SUNDAY     // 周日
};

// 函数：将 DayPeriod 枚举转换为描述字符串
string getDayPeriodDescription(DayPeriod period) {
    switch (period) {
        case MORNING:   return "Good Morning!";
        case AFTERNOON: return "Good Afternoon!";
        case EVENING:   return "Good Evening!";
        case NIGHT:     return "Good Night!";
        default:        return "Invalid period!";
    }
}

// 函数：将 Weekday 枚举转换为描述字符串
string getWeekdayDescription(Weekday day) {
    switch (day) {
        case Weekday::MONDAY:    return "It's Monday, back to work!";
        case Weekday::TUESDAY:   return "It's Tuesday, keep going!";
        case Weekday::WEDNESDAY: return "It's Wednesday, halfway through!";
        case Weekday::THURSDAY:  return "It's Thursday, almost there!";
        case Weekday::FRIDAY:    return "It's Friday, weekend is near!";
        case Weekday::SATURDAY:  return "It's Saturday, enjoy your day off!";
        case Weekday::SUNDAY:    return "It's Sunday, time to relax!";
        default:                 return "Invalid day!";
    }
}

int main() {
    // 使用 DayPeriod 枚举
    DayPeriod currentPeriod = AFTERNOON;

    cout << "Example using DayPeriod enum:" << endl;
    cout << "Current period description: " << getDayPeriodDescription(currentPeriod) << endl;

    // 使用 Weekday 枚举类
    Weekday today = Weekday::FRIDAY;

    cout << "\nExample using Weekday enum class:" << endl;
    cout << "Today's description: " << getWeekdayDescription(today) << endl;

    // 比较 DayPeriod 枚举的常量
    if (currentPeriod == MORNING) {
        cout << "\nIt's still morning." << endl;
    } else {
        cout << "\nIt's not morning." << endl;
    }

    // 比较 Weekday 枚举类的常量
    if (today == Weekday::FRIDAY) {
        cout << "\nYay! It's Friday!" << endl;
    }

    return 0;
}
