#ifndef CGAME_H
#define CGAME_H
#include "CWhole.h"
#include <ctime>
class CGame{
        void viewpack(CPack *);
        void myturn(int);
        void compturn();
        void recoverydist(CPack *);
        bool myretaliatory();
        bool compretaliatory();
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

