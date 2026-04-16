#ifndef EMAIL_H
#define EMAIL_H
#include <string>
#include <vector>
#include "QuadEquation.h"
#include "Student.h"

class Email{
private:
    QuadEquation equation;
    std::vector<double> solution;
    Student* student; 
public:
    Email(const QuadEquation& eq, Student* student);
    
    bool check() const;
    
    void print() const;

    QuadEquation getEquation() const{
        return equation;
    }

    std::vector<double> getSolution() const{
        return solution;
    }

    Student* getStudent() const{
        return student;
    }
};
#endif
