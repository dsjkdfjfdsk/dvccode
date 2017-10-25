#include <iomanip> 
#include <iostream> 
using namespace std; 
  
struct Tod 
{ 
  int hour; 
  int minute; 
  int second; 
}; // tod 
  
void outputTod(Tod& t) 
{ 
  cout.fill('0'); 
  cout << setw(2) << t.hour << ':' 
    << setw(2) << t.minute << ':' 
    << setw(2) << t.second << endl; 
  cout.fill(' '); // set back to a space 
} 
  

int main() 
{ 
  Tod noon = {12}; 
  outputTod(noon); 
} // main 