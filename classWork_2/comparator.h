#pragma once

//! Object to specific comparation different types for sorting
template <typename Type>
class Comparator
{
public:
    bool isLeftNext (Type const &left, Type const &right) const
    {
        return left < right;
    }

    bool isRightNext(Type const &left, Type const &right) const
    {
        return !isLeftNext(left, right);
    }
};
