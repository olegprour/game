#include "CGame.h"

CGame::CGame():m_pack(new CPack), m_distr1(new CPack), m_distr2(new CPack){
srand(time(0));
    while(true)
    {
      int v= rand()%9+6;
      int s= rand()%4;
      m_pack->add((value_card)v,(suit_card) s);
      if (m_pack->getm_n() ==36) break;
    }
}

CGame::~CGame(){delete m_pack; delete m_distr1; delete m_distr2; }
void CGame::randdistr(){
    CCard buf;
     for(int i=0; i<6; i++)
     {
         buf =m_pack->pop();
         m_distr1->add(buf.getvalue(), buf.getsuit());
         buf =m_pack->pop();
         m_distr2->add(buf.getvalue(), buf.getsuit());
     }
}
void CGame::viewdist1(){for (int i=0; i<m_distr1->getm_n(); i++) cout<<* m_distr1->m_arr[i] <<endl;}
void CGame::viewdist2(){for (int i=0; i<m_distr2->getm_n(); i++) cout<<* m_distr2->m_arr[i] <<endl;}
void CGame::viewpack(){for (int i=0; i<m_pack->getm_n(); i++) cout<<* m_pack->m_arr[i] <<endl;}
void CGame::randcard(int k){ if (k>-1 and k<=36) cout<<*m_pack->m_arr[k] << endl; else cout<< "wrong  number of card"<< endl;}
//void CGame::randpack(){}
void CGame::menu()
{
  //  randpack();
    while (true)
    {
      cout<< "Choose your action: 1 - view all pack; 2- ; 3 - pick randomize cardd; 3 - exit; " << endl;
      int c;
      cin>>c;
        switch(c){
          case 1: viewpack(); break;
          case 2:  randdistr(); viewdist1(); cout<< endl; viewdist2();  break;
          case 3: int m; cout << "Choose number card you wish to cut the deck" <<endl; cin>> m; randcard(m); break;
          case 4: exit(1);

        }
    }
}
