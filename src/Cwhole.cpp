#include "Cwhole.h"
#include <iostream>
using namespace std;
CPack::CPack():m_n(0){}
CPack::~CPack()
{
    for (int i=0; i<m_n; i++) delete m_arr[i];
}
int CPack::getm_n(){ return m_n;}
int CPack::searchcard(value_card vc, suit_card sc)
{
    for (int i=0; i < m_n; i++) {
            if(m_arr[i]->getsuit()==sc&&m_arr[i]->getvalue()==vc) return i;
    }
    return -1;
}

bool CPack::add(value_card vc, suit_card sc)
{
   int k = searchcard(vc, sc);
    if (k<0)
    {         m_arr[m_n++]= new CCard(vc, sc);
         return true;
    }
    return false;
}
bool CPack::del(value_card vc, suit_card sc)
{
    int k=searchcard(vc, sc);
    if (k<0) return false;
    delete m_arr[k];
    for(int i=k; k<m_n-1; k++) m_arr[i]=m_arr[i+1];
    m_n--;
    return true;
}
CCard CPack::pop()
{

    // if ( m_n!=0)
    //{
        CCard bufcard =  *m_arr[m_n-1];
        delete m_arr[m_n-1];
        m_n--;
        return bufcard;
   // }
}
