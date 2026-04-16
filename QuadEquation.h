#ifndef EQUATION_H
#define EQUATION_H
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class QuadEquation{
    private:
        double a, b, c;
    
    public:
        QuadEquation(double a, double b, double c);

        std::vector<double> solve() const;
        
        bool checkSolution(const std::vector<double>& solution) const;

        void print() const;
};
#endif
