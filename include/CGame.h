#ifndef CGAME_H
#define CGAME_H
#include "CWhole.h"
#include <ctime>
class CGame
{
        void viewpack();
        void viewdist();
        void randcard(int k);
      //  void randpack();
          void randdistr();
        public:
        CPack *m_pack;
        CPack *m_distr;
        CGame();
        virtual ~CGame();
        void menu();
};

#endif // CGAME_H

