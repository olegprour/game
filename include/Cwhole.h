#ifndef CWHOLE_H
#define CWHOLE_H

#include "CPart.h"
class CPack
{
    int m_n;
    public:
      CCard *m_arr[36];
       CPack ();
        ~CPack();
         int getm_n();
          CCard pop();
          int searchcard(value_card, suit_card);
          bool add(value_card, suit_card);
          bool del(value_card, suit_card);

};
#endif // CWHOLE_H
