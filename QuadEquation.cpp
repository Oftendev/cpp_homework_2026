#include "QuadEquation.h"
#define EPS 1e-12

QuadEquation::QuadEquation(double a, double b, double c) : a(a), b(b), c(c) {}

std::vector<double> QuadEquation::solve() const{
    std::vector<double> roots;
    if (a == 0.0){
        if (b != 0.0){
            roots.push_back(-c / b);
        }
        return roots;
    }
    
    double discriminant = b * b - 4 * a * c;
    
    if (discriminant > 0.0){
        double sqrt_disc = sqrt(discriminant);
        roots.push_back((-b + sqrt_disc) / (2 * a));
        roots.push_back((-b - sqrt_disc) / (2 * a));
    } else if (fabs(discriminant) < EPS){
        roots.push_back(-b / (2 * a));
    }

    return roots;
}

bool QuadEquation::checkSolution(const std::vector<double>& solution) const {
    std::vector<double> correct_roots = solve();
    std::vector<double> correct_copy = correct_roots;
    std::vector<double> solution_copy = solution;

    std::sort(solution_copy.begin(), solution_copy.end());
    std::sort(correct_copy.begin(), correct_copy.end());
    
    if (solution_copy.size() != correct_copy.size()){
        return false;
    }
    
    for (size_t i = 0; i < solution_copy.size(); i++){
        if (fabs(solution_copy[i] - correct_copy[i]) > EPS){
            return false;
        }
    }
    
    return true;
}

void QuadEquation::print() const {
    std::cout << a << "x^2" << "+";
    std::cout << b << "x" << "+";
    std::cout << c << "=0";
}