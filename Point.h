#include <string>
#include <iostream>
using namespace std;

class Point{
    private:
        int dim;
        double *val;
    
    public:
        static int count;
        static const string comment;

        void setDim(int);
        Point();
        Point(int);
        Point(int, double[]);
        Point(const Point&);
        ~Point();

        int getDim() const;
        void setVal(int, double);
        double getVal(int) const;
        static int getCount();
        void display(){
            cout << "(";
            for(int i = 0;i<dim-1;i++){
                cout<<val[i] << ",";
            }
            cout << val[dim-1] << ")" <<  endl;
        }

        // overload operators
        friend ostream &operator<<(ostream&, const Point &); // NOTE
        friend istream &operator>>(istream&, Point &); // NOTE
        const Point & operator=(const Point&);
        Point operator+(const Point&);
        Point operator+(double);  // val[] 全部都加上double值(.cpp 還沒實作)
        const Point & operator+=(const Point&);
        Point operator++(int);
        Point operator*(double);
        Point operator*(Point); // 多項式相乘(.cpp 還沒實作)
        double operator-(const Point&);
        bool operator==(const Point&);
        Point operator!();
        
};