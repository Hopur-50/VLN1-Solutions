#include "relation.h"

relation::relation(int csId, int cId)
{
    this->csId=csId;
    this->cId=cId;
}

int relation::getCsId() const
{
    return csId;
}
int relation::getCId() const
{
    return cId;
}

