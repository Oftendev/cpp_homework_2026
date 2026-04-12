#include "Student.h"

Student::Student(const std::string& name): name(name), successfulTasks(0) {}


GoodStudent::GoodStudent(const std::string& name): Student(name) {}

std::vector<double> GoodStudent::solveEquation(const QuadEquation& eq) {
    return eq.solve();
}


AverageStudent::AverageStudent(const std::string& name, double probability): Student(name), successProbability(probability) {}

std::vector<double> AverageStudent::solveEquation(const QuadEquation& eq) {
    double rand_val = static_cast<double>(rand()) / RAND_MAX;

    if (rand_val < successProbability){
        return eq.solve();
    } else {
        std::vector<double> wrong_answer;
        wrong_answer.push_back(0);
        return wrong_answer;
    }    
}


BadStudent::BadStudent(const std::string& name) : Student(name) {}

std::vector<double> BadStudent::solveEquation(const QuadEquation& eq) {
    std::vector<double> answer;
    answer.push_back(0);
    return answer;
}