#include <iomanip> 
#include <iostream> 
using namespace std;
 
#ifdef _WIN32 
#include <windows.h> 
#else 
#include <unistd.h> 
#endif 
  
int main() 
{ 
  cout << "CTRL-C to exit...\n"; 
  cout.fill('0'); 
  
  for (int hr = 0; hr < 24; hr++) 
  { 
    for (int min = 0; min < 60; min++) 
    { 
      for (int sec = 0; sec < 60; sec++) 
      { 
        cout << setw(2) << hr << ':'; 
        cout << setw(2) << min << ':'; 
        cout << setw(2) << sec << ' '; 
        cout.flush(); 
  
        #ifdef _WIN32 
        Sleep(1000); // one thousand milliseconds
        #else 
        sleep(1); // one second 
        #endif 
  
        cout << '\r'; // CR 
      } 
    } 
  } 
} // main 