#ifndef RELATION_H
#define RELATION_H


class relation
{
public:
    relation(int csId, int cId);
    int getCsId() const;
    int getCId() const;

private:
    int csId;
    int cId;
};

#endif // RELATION_H
