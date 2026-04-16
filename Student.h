#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "QuadEquation.h"

class Student{
protected:
    std::string name;
    int successfulTasks;
public:
    Student(const std::string& name);
    virtual ~Student() = default;
    
    virtual std::vector<double> solveEquation(const QuadEquation& eq) = 0;
    
    void incrementSuccessfulTasks(){
        successfulTasks++;
    }

    std::string getName() const{
        return name;
    }

    int getSuccessfulTasks() const{
        return successfulTasks;
    }
};

class GoodStudent : public Student {
public:
    GoodStudent(const std::string& name);
    std::vector<double> solveEquation(const QuadEquation& eq) override;
};

class AverageStudent : public Student {
private:
    double successProbability;
public:
    AverageStudent(const std::string& name, double probability = 0.5);
    std::vector<double> solveEquation(const QuadEquation& eq) override;
};

class BadStudent : public Student {
public:
    BadStudent(const std::string& name);
    std::vector<double> solveEquation(const QuadEquation& eq) override;
};
#endif
