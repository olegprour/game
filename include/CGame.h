#ifndef CGAME_H
#define CGAME_H
#include "CWhole.h"
#include <ctime>
class CGame{
        void viewpack(CPack *);
      //  void viewdist1();
     //   void viewdist2();
        void myturn(int);
        void compturn();
        void recoverydist1();
        void recoverydist2();
        bool myretaliatory();
        bool compretaliatory();
        //void randcard(int k);
        void randdistr();
        public:
        bool m_mymove;
        CCard m_turn[6];
        int m_numbermycard;
        CCard m_beat[6];
        int m_numberturn;
        CCard m_trump;
        bool m_trumppack;
        CPack *m_pack;
        CPack *m_distr1;
        CPack *m_distr2;
        CGame();
        virtual ~CGame();
        //void menu();
         void play();
};

#endif // CGAME_H

