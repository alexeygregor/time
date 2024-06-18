#include <map>
#include <ctime>
#include <string>
#include <limits>
#include <numeric>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
  time_t t = time(nullptr);
  time_t f = time(nullptr);
  tm local = *std::localtime(&t);
  tm* mktime = localtime(&f);
  multimap<string, string> friends;
  map<string,string>::iterator it;
    cout << asctime (mktime) << endl;
  while (true)
  {
      bool ch = false;
      string name, date;
      string next_date, today;
      int y = 0, m = 0, d = 0;
      int bfr1 = 0, bfr2 = 0, bfr3 = 12;
      int buf1 = 0, buf2 = 0, buf3 = 31;
    cout << "Input name: "; cin >> name;
    if (name == "end") break;
    else if (name == "show")
    {
      for (it = friends.begin(); it != friends.end(); ++it)
        cout << it->first << " " << it->second << endl;
      continue;
    }
    cout << "Input date: ";  cin >> get_time(&local, "%y/%m/%d");
    if (cin.fail() || cin.peek() != '\n')
    {
      cerr << "Incorrect input. Try again\n";
      cin.clear();
      cin.ignore(numeric_limits < streamsize > ::max(), '\n');
    }
    else
    {
      y = local.tm_year;
      m = local.tm_mon + 1;
      d = local.tm_mday;
      if (y < 10) date += "0";
      date += to_string(y) + "/";
      if (m < 10) date += "0";
      date += to_string(m) + "/";
      if (d < 10) date += "0";
      date += to_string(d);
      friends.insert(pair<string,string> (date, name));

      for (it = friends.begin(); it != friends.end(); ++it)
      {
        buf1 = mktime->tm_mday;
        bfr1 = mktime->tm_mon + 1;
        buf2 = stoi(it->first.substr(6,8));
        bfr2 = stoi(it->first.substr(3,6));
        if (buf2 == buf1 && bfr2 == bfr1)
        {
          ch = true;
          today = it->first;
        }
        if (bfr2 < bfr3) buf3 = 31;
        if (bfr2 > bfr1 && bfr2 <= bfr3 && buf2 < buf3)
        {
          bfr3 = bfr2;
          buf3 = buf2;
          next_date = it->first;
        }
        if (bfr2 == bfr1 && buf2 < buf3 && buf2 - buf1 > 0)
        {
          bfr3 = bfr2;
          buf3 = buf2;
          next_date = it->first;
        }
      }
      typedef multimap<string, string>::iterator itf;
      pair <itf, itf> pos;
      if (ch)
      {
        cout << "Today: " << endl;
        pos = friends.equal_range(today);
        for (; pos.first != pos.second; pos.first++)
          cout << "*" << pos.first->second << " " << pos.first->first << endl;
      }
      cout << "Next date: " << endl;
      pos = friends.equal_range(next_date);
      for (; pos.first != pos.second; pos.first++)
        cout << "#" << pos.first->second << " " << pos.first->first << endl;
    }
  }
}
