#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Time
{
private:
    int hour;
    int minute;

public:
    Time(int h, int m);
    Time(int h);
    void change(int h, int m);
    int get_hour();
    int get_minute();

    int compare(Time t);
    string tell_time();
};

bool check(int h, int m)
{
    bool ch = false;
    if (h < 24 && h >= 0 && m < 60 && m >= 0)
    {
        ch = true;
    }
    return ch;
}

Time::Time(int h, int m)
{
    if (check(h, m))
    {
        hour = h;
        minute = m;
    }
    else
    {
        exit(0);
    }
}

Time::Time(int h)
{
    if (check(h, 0))
    {
        hour = h;
        minute = 0;
    }
    else
    {
        exit(0);
    }
}

void Time::change(int h, int m)
{
    if (check(h, m))
    {
        hour = h;
        minute = m;
    }
    else
    {
        exit(0);
    }
}

int Time ::get_hour()
{
    return hour;
}

int Time ::get_minute()
{
    return minute;
}

int Time::compare(Time t)
{
    if (hour < t.hour)
    {
        return -1;
    }
    else if (hour > t.hour)
    {
        return 1;
    }
    else if (hour == t.hour)
    {
        if (minute < t.minute)
        {
            return -1;
        }
        else if (minute > t.minute)
        {
            return 1;
        }
        else if (minute == t.minute)
        {
            return 0;
        }
    }
    abort();
}

string Time::tell_time()
{
    string x;
    if (hour < 12)
    {
        x = "morning";
    }
    else if (hour == 12 && minute == 0)
    {
        x = "noon";
    }
    else if (hour > 11 && hour < 17 && !(hour == 12 && minute == 0))
    {
        x = "afternoon";
    }
    else if (hour > 16 && hour < 20)
    {
        x = "evening";
    }
    else if (hour > 19)
    {
        x = "night";
    }

    return x;
}

int main()
{
    Time t(2, 0);
    cout << t.get_hour() << endl
         << t.get_minute() << endl;

    t.change(6, 6);
    cout << t.get_hour() << endl
         << t.get_minute() << endl;

    // compare
    Time t2(3, 3);
    int x;
    x = t.compare(t2);
    if (x == -1)
    {
        cout << "The first time is lower.\n";
    }
    else if (x == 1)
    {
        cout << "The second time is higher.\n";
    }
    else if (x == 0)
    {
        cout << "They are equal. \n";
    }

    // che vaghti az rooz ast
    Time t3(21,50);
    cout << t3.tell_time() << endl;

    system("pause");
    return 0;
}