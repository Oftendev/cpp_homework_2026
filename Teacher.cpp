#include "Teacher.h"

Teacher::Teacher() {}

void Teacher::addEmail(const QuadEquation& eq, Student* student){
    Email email(eq, student);
    emailQueue.push(email);
}

void Teacher::checkAllEmails(){
    while (!emailQueue.empty()){
        Email email = emailQueue.front();
        emailQueue.pop();
        Student* student = email.getStudent();
        if (email.check()){
            student->incrementSuccessfulTasks();
        }
        gradeTable[student->getName()] = student->getSuccessfulTasks();
    }
}

void Teacher::clearQueue(){
    while (!emailQueue.empty()){
        emailQueue.pop();
    }
}

int Teacher::getQueueSize() const{
    return emailQueue.size();
}

void Teacher::publishGradeTable() const{
    if (gradeTable.empty()){
        std::cout << "Таблица успеваемости пуста." << std::endl;
        return;
    }

    std::cout << "\n===Таблица успеваемости===" << std::endl;
    std::cout << "Имя студента\t\tКоличество успешно решённых задач" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    
    for (const auto& entry : gradeTable) {
        if (entry.first.length() < 31) { //Просто подобрал число байтов так, чтобы работало
            std::cout << entry.first << "\t\t" << entry.second << std::endl;
        } else {
            std::cout << entry.first << "\t" << entry.second << std::endl;
        }
    }
    std::cout << "========================================\n" << std::endl;
}