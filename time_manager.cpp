#include <map>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

double end (int n, double d)
{
  int i = 0;
  time_t t2 = time(nullptr);
  tm* local2 = localtime(&t2);
  i = local2->tm_hour;
  d = difftime(i, n);
  if (n > i) d += 24;
  return d;
}

int main()
{
  int n = 0;
  double d = 0;
  bool ch1 = false, ch2 = false;
  string bfr, command;
  map<string, int> task;
  map<string,int>::iterator it;

  while (command != "exit")
  {
    cout << "Insert command:";
    cin >> command;
    if (command == "begin")
    {
      if(ch1 == true)
      {
        cout << bfr << " " << (d = end(n, d)) << "h" << endl;
        ch2 = true;
      }
      else
      {
        cin >> bfr;
        time_t t1 = time(nullptr);
        tm* local1 = localtime(&t1);
        n = local1->tm_hour;
        ch1 = true;
      }
    }
    if (command == "end" || ch2 == true)
    {
      d = end(n, d);
      task.insert(pair<string,int> (bfr, d));
      ch1 = false; ch2 = false;
    }
    if (command == "status")
    {
      if (ch1 == true)
        cout << bfr << " " << (d = end(n, d)) << "h" << endl;
      else
      {
        for(it = task.begin(); it != task.end(); ++it)
          cout << it->first << " " << it->second << "h" << endl;
      }
    }
  }
}
