#include "Point.h"
#include <cmath>

// static 靜態變數(資料) - 從main()開始之前就存在一直到main()結束
const string Point::comment = "This is a Point class with multi dimensions.";
int  Point::count = 0;

void Point::setDim(int dim)
{
    this->dim = dim;
}
Point::Point()
{
    count++;
    this->dim = 2; // set dimension
    this->val = new double[2]; // dynamic build up array
    this->val[0] = 0.0;
    this->val[1] = 0.0;
}
Point::Point(int dim)
{
    count++;
    this->dim = dim;
    this->val = new double[dim]; // dynamic build up array
    for(int i = 0;i<dim;i++)
    {
        this->val[i] = 0.0;
    }
}
Point::Point(int dim, double v[])
{
    count++;
    this->dim = dim;
    this->val = new double[dim]; // dynamic build up array
    for(int i = 0;i<dim;i++)
    {
        this->val[i] = v[i]; // copy
    }
}
Point::Point(const Point& p)
{
    count++;
    this->dim = p.dim;
    this->val = new double[this->dim];
    for(int i = 0;i<dim;i++)
    {
        this->val[i] = p.val[i]; // copy
    }
}
Point::~Point()
{
    count--;
}

int Point::getDim() const
{
    return this->dim;
}
void Point::setVal(int d, double v)
{
    this->val[d] = v;
}
double Point::getVal(int d) const
{
    return this->val[d];
}
int Point::getCount()
{
    return count;
}
// overload operators
ostream &operator<<(ostream &o, const Point &p)
{
    o << "(";
    for(int i = 0;i<p.dim-1;i++)
    {
        o<<p.val[i] << ",";
    }
    o << p.val[p.dim-1] << ")";
    return o;
}
istream &operator>>(istream &i, Point &p)
{
    i >> p.dim;
    delete[] p.val; // free the ramin memory
    p.val = new double[p.dim];
    for(int j=0;j<p.dim;j++)
    {
        i >> p.val[j];
    }
    return i;
}
const Point& Point::operator=(const Point& other)
{
    this->dim = other.dim;
    delete[] this->val;
    this->val = new double[this->dim];
    for(int j=0;j<this->dim;j++)
    {
        this->val[j] = other.val[j];
    }
    return *this;
}
Point  Point::operator+(const Point& other)
{
    if(this->dim != other.dim)
    {
        Point result(2); // dim = 2
        return result;
    }
    else
    {
        Point result(this->dim);
        for(int i =0;i< dim;i++)
        {
            result.val[i] = this->val[i] + other.val[i];
        }
        return result;
    }
}
const Point&  Point::operator+=(const Point& other)
{
    if(this->dim != other.dim)
    {
        return *this;
    }
    else
    {
        for(int i =0;i< dim;i++)
        {
            this->val[i] += other.val[i];
        }
        return *this;
    }
}
Point Point::operator++(int i)
{
    for(int i =0;i< this->dim;i++)
    {
        this->val[i] += 1.0;
    }
    return *this;
}
Point  Point::operator*(double d)
{
    for(int i =0;i< dim;i++)
    {
        this->val[i] *= d;
    }
    return *this;
}
double  Point::operator-(const Point& other)
{
    if(this->dim != other.dim)
    {
        return 0.0;
    }
    else
    {
        double s=0; // sum
        double d; 
        for(int i =0;i< dim;i++)
        {
            d =  this->val[i] - other.val[i];
            s += d*d;
        }
        return sqrt(s);
    }

}
bool  Point::operator==(const Point& other)
{
    if(this->dim != other.dim)
    {
        return false;
    }
    for(int i =0;i< dim;i++)
    {
        if(this->val[i]!=other.val[i])
        {
            return false;
        }
    }
    return true;
}
Point  Point::operator!()
{
    for(int i =0;i< dim;i++)
    {
        this->val[i] *= -1;
    }

    return *this;
}