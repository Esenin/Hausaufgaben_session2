#include "writer.h"

using namespace writerNamespace;

enum Directions
{
    left = 1,
    up,
    right,
    down
};

Writer::Writer(int *array[], int size)
{
    insideArray = array;
    arrSize = size;
}

Writer::~Writer()
{
    //! do nothing
}

bool Writer::isCorrectPos(Point a, int size)
{
    if (a.x == -1)
        a.x = 0;
    if (a.x == size + 1)
        a.x = size;
    return (a.x >= 0 && a.x < size) && (a.y >= 0 && a.y < size);
}

void Writer::changeWay (int &way)
{
    if (++way == 5)
        way = 1;
}

void Writer::nextStep(int &i, int &j, Point aim)
{
    if (i > aim.x)
        i--;
    if (i < aim.x)
        i++;
    if (j > aim.y)
        j--;
    if (j < aim.y)
        j++;
}

void Writer::makeNextPos(Point &p1, int length, int way)
{
    if (way == left)
        p1.x -= length;
    if (way == up)
        p1.y += length;
    if (way == right)
        p1.x += length;
    if (way == down)
        p1.y -= length;
}

void Writer::work()
{
    int vectorLength = 1;
    Directions goTo = left;
    Point current = {arrSize / 2, arrSize / 2};
    Point next = current;

    print(insideArray, current,current);
    makeNextPos(next, vectorLength, goTo);

    while (isCorrectPos(next, arrSize))
    {
        print(insideArray, current, next);

        current = next;
        changeWay((int &)(goTo));
        if (goTo == right || goTo == left)
            vectorLength++;
        makeNextPos(next, vectorLength, goTo);
    }


}
