#ifndef CPART_H
#define CPART_H
#include <iostream>
using namespace std;
    enum value_card{six, seven, eight, nine, ten, jack, queen, king, ace};
    enum suit_card{spades, clubs, hearts, diamonds};
class CCard{

     value_card m_valuecard;
     suit_card m_suitcard;
    public:

        CCard();
        CCard(value_card, suit_card);
        virtual ~CCard();
        suit_card getsuit();
         value_card getvalue();
        void setvalue(value_card);
         void setsuit(suit_card);
        friend bool operator < (const CCard&, const CCard&);
         friend bool operator == (const CCard&, const CCard&);
        friend ostream& operator<<( ostream&,const CCard&);
};

#endif // CPART_H
