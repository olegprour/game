#ifndef CWHOLE_H
#define CWHOLE_H
#include <algorithm>
#include "CPart.h"
class CPack
{
     int m_n;
    public:
      CCard *m_arr[36];
       CPack ();
        ~CPack();
         int getm_n();
          bool pop(CCard&);
          int searchcard(value_card, suit_card);
          int searchvalcard(value_card vc);
          int searchsuitcard(value_card vc, suit_card sc);
          bool add(value_card, suit_card);
          bool del(value_card, suit_card);
          int mincard();
          void sortcards();
};
#endif // CWHOLE_H
