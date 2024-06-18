#ifndef CGAME_H
#define CGAME_H
#include "CWhole.h"
#include <ctime>
class CGame
{

        void viewpack();
        void viewdist1();
        void viewdist2();
        void myturn(int);
        void compturn();
        void recoverydist1();
        void recoverydist2();
        bool myretaliatory();
        bool compretaliatory();
        void randcard(int k);
        void randdistr();
        public:
        bool m_mymove;
        CCard m_turn;
        int m_numbermycard;
        CCard m_beat;
        CCard m_trump;
        CPack *m_pack;
        CPack *m_distr1;
        CPack *m_distr2;
        CGame();
        virtual ~CGame();
        void menu();
         void play();
};

#endif // CGAME_H

