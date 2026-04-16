#ifndef TEACHER_H
#define TEACHER_H
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include "Email.h"
#include "Student.h"

class Teacher{
private:
    std::queue<Email> emailQueue;
    std::map<std::string, int> gradeTable;
public:
    Teacher() = default;

    void addEmail(const QuadEquation& eq, Student* student);

    void checkAllEmails();
    
    void publishGradeTable() const;
    
    void clearQueue();
    
    int getQueueSize() const;
};
#endif
