#pragma once

namespace writerNamespace
{
int const arrMaxSize = 100;

//! Interface class
class Writer
{
public:
    //! Construcor saves link to array
    Writer(int *array[], int size);

    //! virtual destructor
    /*! allows inherited classes to have and run own destructor
    */
    virtual ~Writer();

    //! public function to use this class
    /*!
      it makes spiral way and
      print it with same virtual function
    */
    void work();

protected:
    //! simple Point struct to not need to use setters
    struct Point
    {
        int x;
        int y;
    };

    //! checks that Point is inside matrix
    bool isCorrectPos(Point a, int size);
    void nextStep(int &i, int &j, Point aim);
    void changeWay (int &way);
    void makeNextPos(Point &p1, int length, int way);

    //! main function you must override in inherited class
    /*!
      pure function prints straight line
      @param array subject matrix
      @param current start of line
      @param next end of line
    */
    virtual void print(int *array[arrMaxSize], Point current, Point next) = 0;

    int **insideArray;
    int arrSize;
};
}

