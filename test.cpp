#include <iostream>
#include "CPart.h"
#include <set>
#include <ctime>
#include "CGame.h"
using namespace std;
int main()
{
    /*set <CCard> s1;
    int i(0), k;
     srand(time(0));
   while(true){
      int v= rand()%9+6;
      int s= rand()%4;
     s1.insert(CCard((value_card)v,(suit_card) s));
     i=s1.size();
    //    cout << v << "  " << s << endl;
     cout << i <<endl;
     //cin >> k;
     if(i==36) break;
   }
   for(auto p = s1.begin(); p!=s1.end(); ++p) cout<<*p<<endl;
   cout << "-------------------" << endl;
   CCard c1(six, clubs);
   auto p = s1.find(c1);
   cout << *p<< endl;
*/
   CGame g1;
   g1.play();
  // s1.erase(p);
    //for(auto p = s1.begin(); p!=s1.end(); ++p) cout<<*p<<endl;
   return 0;
}


