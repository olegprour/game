#include "CGame.h"
CGame::CGame():m_pack(new CPack), m_distr1(new CPack), m_distr2(new CPack)
{
 srand(time(0));
    while(true)
    {
      int v= rand()%9;
      int s= rand()%4;
      m_pack->add((value_card)v,(suit_card) s);
      if (m_pack->getm_n() == 36)  break;
    }

}
CGame::~CGame(){delete m_pack; delete m_distr1; delete m_distr2; }
void CGame::randdistr(){
    CCard buf;
     for(int i=0; i<6; i++)
     {
        m_pack->pop(buf);
        m_distr1->add(buf.getvalue(), buf.getsuit());
        m_pack->del(buf.getvalue(), buf.getsuit());
        m_pack->pop(buf);
         m_distr2->add(buf.getvalue(), buf.getsuit());
         m_pack->del(buf.getvalue(), buf.getsuit());
     }
     m_pack->pop(m_trump);
     m_pack->del(m_trump.getvalue(), m_trump.getsuit());
     m_distr1->sortcards();
     m_distr2->sortcards();
     m_trumppack=true;;
}
void CGame::viewdist1(){for (int i=0; i<m_distr1->getm_n(); i++) cout<<i<<" "<<* m_distr1->m_arr[i] <<endl;}
void CGame::viewdist2(){for (int i=0; i<m_distr2->getm_n(); i++) cout<<i<<" "<<* m_distr2->m_arr[i] <<endl;}
void CGame::viewpack(){for (int i=0; i<m_pack->getm_n(); i++) cout<<* m_pack->m_arr[i] <<endl;}
//void CGame::randcard(int k){ if (k>-1 and k<=36) cout<<*m_pack->m_arr[k] << endl; else cout<< "wrong  number of card"<< endl;}
/*
void CGame::menu()
{
    cout<<endl;
    cout  << m_pack->getm_n() <<  endl;
    randdistr();
    cout  << m_pack->getm_n() <<  endl;
    while (true)
    {
      cout<< "Select a menu item: "<< endl;
      cout<<"1 - view all card;" <<endl;
      cout<<" 2- distribution of cards ;" <<endl;
      cout<<" 3 - computers move;" <<endl;
      cout<<" 4 - your move;" <<endl;
      cout<<" 5 - of delete randomize card;" << endl;
       cout<<"6 - recovery distr; " << endl;
      cout<<"7 - exit; " << endl;
      int c,k;
      cin >> c;
        switch(c){
        case 1:  viewpack(); break;
          case 2:
              viewdist1();
              cout << endl;
              viewdist2();
              cout << endl;
              cout << m_trump << endl;
               cout << m_pack->getm_n() << endl;
               break;
           case 3:
               compturn();
               cout <<"Enter the value from 0 to " << m_distr1->getm_n()-1 << endl;
                cin >> k;
           if (myretaliatory())
                cout << m_beat << endl;
            else
           //
           break;
           case 4:
            cout <<"Enter the value from 0 to " << m_distr1->getm_n()-1 << endl;
            cin >> k;
            myturn(k);
            if (compretaliatory()) cout << m_beat << endl;
            else cout << "comp can't beat your card "<< endl;
            break;

          case 5:
              int m,n;
              cout << "Choose number card you wish to delete" << endl;
              cin>> m >> n;
              m_pack->del((value_card)m, (suit_card) n);
              cout<<m_pack->getm_n();
               break;

          case 6:
              recoverydist1();
           break;
          case 7: exit(1);

        }
    }
}
*/
void CGame::recoverydist1()
{
  CCard buf;
    while(m_distr1->getm_n()<6&&m_pack->getm_n())
     {
        m_pack->pop(buf);
        m_distr1->add(buf.getvalue(), buf.getsuit());
        m_pack->del(buf.getvalue(), buf.getsuit());
     }
     if (m_trumppack==true&&m_pack->getm_n()==0&&m_distr1->getm_n()<6)
     {
        m_distr1->add(m_trump.getvalue(), m_trump.getsuit());
        m_trumppack = false;
     }
     m_distr1->sortcards();
}
void CGame::recoverydist2()
{
  CCard buf;
   while(m_distr2->getm_n()<6&&m_pack->getm_n())
     {
         m_pack->pop(buf);
         m_distr2->add(buf.getvalue(), buf.getsuit());
         m_pack->del(buf.getvalue(), buf.getsuit());
     }
     if (m_trumppack==true&&m_pack->getm_n()==0&&m_distr2->getm_n()<6)
     {
        m_distr2->add(m_trump.getvalue(), m_trump.getsuit());
        m_trumppack = false;
     }
     m_distr2->sortcards();
}

void CGame:: myturn(int k)
{
    m_turn[0] = *m_distr1->m_arr[k];
    m_distr1->del(m_turn[0].getvalue(),m_turn[0].getsuit());
    cout << m_turn[0] << endl;
}
void CGame::compturn()
{
   int i(0);
   while(i < m_distr2->getm_n() )
    {
      if(m_trump.getsuit()!=m_distr2->m_arr[i]->getsuit())
       {
          m_turn[0] = *m_distr2->m_arr[i];
          break;
       }
       i++;
    }
   if (i==m_distr2->getm_n())  m_turn[0] = *m_distr2->m_arr[0];
   m_distr2->del(m_turn[0].getvalue(),m_turn[0].getsuit());
   cout << m_turn[0] << endl;

}
bool CGame::myretaliatory()
{
   int k = m_distr1->searchsuitcard(m_turn[0].getvalue(), m_turn[0].getsuit());
   if (k<0&&m_trump.getsuit()!=m_turn[0].getsuit())
        k = m_distr1->searchsuitcard(six, m_trump.getsuit());
   if(k<0)
    {
       m_distr1->add(m_turn[0].getvalue(), m_turn[0].getsuit());
       m_distr1->sortcards();
       return false;
    }
    else
    {

         do{
            cout <<"Enter the value from 0 to " << m_distr1->getm_n()-1 << endl;
            cin >> m_numbermycard;
           }while(!((m_turn[0].getsuit()== m_distr1->m_arr[m_numbermycard]->getsuit()&&
           m_distr1->m_arr[m_numbermycard]->getvalue()>=m_turn[0].getvalue())||
           (m_trump.getsuit()==m_distr1->m_arr[m_numbermycard]->getsuit()&&
           m_turn[0].getsuit()!=m_trump.getsuit())));

          m_beat[0]=*m_distr1->m_arr[m_numbermycard];
          m_distr1->del(m_beat[0].getvalue(),m_beat[0].getsuit());

       return true;
    }
}
bool CGame::compretaliatory()
{
    int k = m_distr2->searchsuitcard(m_turn[0].getvalue(), m_turn[0].getsuit());
    if (k<0&&m_trump.getsuit()!=m_turn[0].getsuit()){
        k = m_distr2->searchsuitcard(six, m_trump.getsuit());
    }
    if( k < 0)
        {
          m_distr2->add(m_turn[0].getvalue(), m_turn[0].getsuit());
          m_distr2->sortcards();
          return false;
        }
        else
        {
           m_beat[0]=*m_distr2->m_arr[k];
           m_distr2->del(m_beat[0].getvalue(), m_beat[0].getsuit());
           return true;
        }
}

void CGame::play()
{

    m_numberturn = 1;
    int k;
    char c;
    randdistr();
    m_mymove= true;
    while (true)
    {
      viewdist1();
      cout << endl;
      viewdist2();
      cout << endl;
      cout << m_trump << endl;
      cout << endl;

      if(m_mymove)
      {
        cout <<"Enter the value from 0 to " << m_distr1->getm_n()-1 << endl;
         cin >> k;
         myturn(k);
         if (compretaliatory())
         {
             cout << m_beat[0] << endl;
             cout << endl;
             m_mymove = false;
             recoverydist2();
         }
         else
           cout << "comp can't beat your card "<< endl;
           recoverydist1();
      }

       else
      {
          compturn();
          if (myretaliatory())
          {
                cout << m_beat[0] << endl;
                cout << endl;
                m_mymove = true;
                recoverydist1();
          }
            else
            {
             cout << "You have no such card to beat turncard."<< endl;
             cout<< "You have to take the turncard.  "<< endl;
             cout<< "Press any key to continue: "<< endl;
             cin >> c;
            }
            recoverydist2();
       }

       if(m_pack->getm_n()==0&&m_distr1->getm_n()==0&&m_distr2->getm_n()!=0)
       {
            cout<< " you win!!!!!!!!!!";
            break;
       }
       else if (m_pack->getm_n()==0&&m_distr2->getm_n()==0&&m_distr1->getm_n()!=0)
       {
            cout<< " comp win!!!!!!!!";
            break;
       }
       else if (m_pack->getm_n()==0&&m_distr2->getm_n()==0&&m_distr1->getm_n()==0)
       {
        cout<< " drawn game!!!!!!!!!!!!!!!!!!!!!!!1";
        break;
       }
    }
}
