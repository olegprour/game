#include "CPart.h"
#include <iostream>
#include <cstring>
using namespace std;
CCard::CCard():m_valuecard(six), m_suitcard(spades)
{
}
CCard::~CCard()
{
    //dtor
}
CCard::CCard(value_card c, suit_card s):m_valuecard(c), m_suitcard(s){}
value_card CCard::getvalue(){return m_valuecard;}
suit_card CCard::getsuit(){return m_suitcard;}
void CCard::setvalue(value_card c){ m_valuecard= c;}
void CCard::setsuit(suit_card s){ m_suitcard= s;}
ostream& operator<<( ostream& out, CCard& p){
    switch(p.m_valuecard){
      case 6:  out << "six"<< " "; break;
      case 7: out << "seven"<< " ";  break;
      case 8: out << "eight"<< " ";  break;
      case 9: out << "nine"<< " "; break;
      case 10: out << "ten"<< " ";  break;
      case 11: out << "jack"<< " ";  break;
      case 12: out << "queen"<< " "; break;
      case 13: out << "king"<< " "; break;
      case 14: out << "ace"<< " "; break;
    }
     switch(p.m_suitcard){
      case 0:  out << "spades"; break;
      case 1: out << "club";  break;
      case 2: out << "hearts";  break;
      case 3: out << "diamonds"; break;
    }
    return out;
    }
