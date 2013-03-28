#include "comp.h"


Comp::Comp(bool ordre, QString critereTri)
    : mOrdre(ordre),mCritereTri(critereTri)
{}

bool Comp::operator()(Contact * a,Contact * b)
{
//    if(a==NULL || b==NULL) exit(1);
    const Champ * c=(*a)[mCritereTri];
    if(c==NULL) return mOrdre;
    const Champ * d=(*b)[mCritereTri];
    if(d==NULL) return !mOrdre;
    return mOrdre ? c->toString()<d->toString() : c->toString()>=d->toString();
}
