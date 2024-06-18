#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
  int a = 0, b = 0, c = 0, d = 0;
  time_t t = time(nullptr);
  tm* local1 = localtime(&t);
  cout << asctime(local1) << endl;
  cout << "Enter timer: ";
  cin >> get_time(local1, "%M:%S");
  cout << endl;
  b = ((local1->tm_min)*60) + (local1->tm_sec);
  while(b != 0)
  {
    time_t f = time(nullptr);
    tm local2 = *std::localtime(&f);
    a = ((local2.tm_min)*60) + (local2.tm_sec);
    if (c != a)
    {
      d = b / 60;
      c = a; b--;
      cout << "*";
      if (b % 60 == 0) cout << " " << d << ":00" << endl;
      else if (b % 10 == 0) cout << " " << d << ":" << b - d * 60 << endl;
    }
  }
}
