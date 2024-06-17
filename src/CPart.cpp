#include "CPart.h"
#include <iostream>
#include <cstring>
using namespace std;
char* valcard[]={"six", "seven", "eight", "nine", "ten", "jack", "queen","king", "ace" };
char* suitcard[]={ "spades", "club", "hearts", "diamonds" };
CCard::CCard():m_valuecard(six), m_suitcard(spades){}
CCard::~CCard(){}
CCard::CCard(value_card c, suit_card s):m_valuecard(c), m_suitcard(s){}
value_card CCard::getvalue(){return m_valuecard;}
suit_card CCard::getsuit(){return m_suitcard;}
void CCard::setvalue(value_card c){ m_valuecard= c;}
void CCard::setsuit(suit_card s){ m_suitcard= s;}
bool operator < (const CCard& cl, const CCard& cr){
  //if (cl.m_suitcard < cr.m_suitcard) return true;
   //  else
   if (/*cl.m_suitcard == cr.m_suitcard&&*/cl.m_valuecard < cr.m_valuecard) return true;
          else return false;
}
bool operator == (const CCard& cl, const CCard& cr){
  if (cl.m_suitcard == cr.m_suitcard&&cl.m_valuecard == cr.m_valuecard) return true; else return false;
}
ostream& operator<<( ostream& out,const CCard& p){
    out << valcard[p.m_valuecard]<< " " << suitcard[p.m_suitcard];
    return out;
    }
