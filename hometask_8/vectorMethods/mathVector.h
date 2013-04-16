#pragma once


//! @class MathVector Provides R^N math vectors
class MathVector
{
public:
    class VectorExceptions{};
    class WrongDimensions : public VectorExceptions{};

    MathVector(const int &dimension);
    MathVector(const MathVector *other);
    ~MathVector();

    bool isZeroVector() const;

    void setValueAt(const double &value, const int &pos) throw (VectorExceptions);
    double valueAt(const int &pos) throw (VectorExceptions);

    void operator += (const MathVector &other);
    void operator -= (const MathVector &other);

    //! unary (-1)
    MathVector operator -() const;

    //! scalar multiplication
    double operator * (const MathVector &other);

protected:
    void checkDimension(const MathVector &other) throw (WrongDimensions);

private:
    double *vector;
    const int mDimension;
};

