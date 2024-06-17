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
int CPack::searchsuitcard(value_card vc, suit_card sc)
{
    for (int i=0; i < m_n; i++) {
            if(m_arr[i]->getsuit()==sc&&m_arr[i]->getvalue()>=vc) return i;
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
    while(k < m_n-1) { m_arr[k]=m_arr[k+1]; k++;}
    m_n--;
    return true;
}
bool CPack::pop(CCard& card)
{
    if ( m_n!=0) card = *m_arr[m_n-1];  return true;  return false;
}
int  CPack::mincard()
{
    int num_min(-1);
    value_card min_card(ace);
    for(int i=0; i < m_n; i++)
    {
        if (m_arr[i]->getvalue() < min_card)
        {
            min_card=m_arr[i]->getvalue();
            num_min = i;
        }
    }
    return num_min;
}
void CPack::sortcards()
{
    sort(m_arr, m_arr+m_n, [](CCard * a, CCard* b){return *a < *b;});
}
