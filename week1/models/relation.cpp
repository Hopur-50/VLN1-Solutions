#include "relation.h"

relation::relation(int csId, int cId)
{
    this->csId=csId;
    this->cId=cId;
}

int relation::getCsId() const
{
    return CsId;
}
int relation::getCId() const
{
    return CId;
}

