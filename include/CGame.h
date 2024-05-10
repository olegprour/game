#ifndef CGAME_H
#define CGAME_H
#include "CWhole.h"
#include <ctime>
class CGame
{
        void viewpack();
        void viewdist1();
        void viewdist2();
        void randcard(int k);
      //  void randpack();
          void randdistr();
        public:
        CPack *m_pack;
        CPack *m_distr1;
        CPack *m_distr2;

        CGame();
        virtual ~CGame();
        void menu();
};

#endif // CGAME_H

