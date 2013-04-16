#include "mathVector.h"

MathVector::MathVector(const int &dimension)
    : mDimension(dimension)
{
    vector = new double[dimension];
}

MathVector::MathVector(const MathVector *other)
    : mDimension(other->mDimension)
{
    vector = new double[mDimension];
    for (int i = 0; i < mDimension; i++)
        vector[i] = other->vector[i];
}

MathVector::~MathVector()
{
    delete[] vector;
}

bool MathVector::isZeroVector() const
{
    for (int i = 0; i < mDimension; i++)
        if (vector[i])
            return false;
    return true;
}

void MathVector::setValueAt(const double &value, const int &pos) throw (VectorExceptions)
{
    if (pos < 0 || pos >= mDimension)
        throw VectorExceptions();
    vector[pos] = value;
}

double MathVector::valueAt(const int &pos) throw (VectorExceptions)
{
    if (pos < 0 || pos >= mDimension)
        throw VectorExceptions();
    return vector[pos];
}

void MathVector::operator +=(const MathVector &other)
{
    checkDimension(other);

    for (int i = 0; i < mDimension; i++)
        vector[i] += other.vector[i];
}

void MathVector::operator -=(const MathVector &other)
{
    (*this) += (-other);
}

MathVector MathVector::operator - () const
{
    MathVector result = this;
    for (int i = 0; i < mDimension; i++)
        result.vector[i] = -result.vector[i];
    return result;
}

double MathVector::operator *(const MathVector &other)
{
    checkDimension(other);

    double result = 0;
    for (int i = 0; i < mDimension; i++)
        result += vector[i] * other.vector[i];

    return result;
}

void MathVector::checkDimension(const MathVector &other)  throw (WrongDimensions)
{
    if (mDimension != other.mDimension)
        throw WrongDimensions();
}
