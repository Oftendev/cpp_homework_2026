#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "QuadEquation.h"
#include "Student.h"
#include "Email.h"
#include "Teacher.h"

std::vector<QuadEquation> readEquationsFromFile(const std::string& filename) {
    std::vector<QuadEquation> equations;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
        return equations;
    }
    
    double a, b, c;
    while (file >> a >> b >> c) {
        equations.push_back(QuadEquation(a, b, c));
    }
    
    file.close();
    return equations;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand(static_cast<unsigned>(time(nullptr)));
    std::vector<Student*> students;
    students.push_back(new GoodStudent("Касимов Александр"));
    students.push_back(new GoodStudent("Марченко Виктория"));
    students.push_back(new AverageStudent("Селивестров Иван", 0.5));
    students.push_back(new AverageStudent("Мухамадиев Карим", 0.3));
    students.push_back(new BadStudent("Васильев Дмитрий"));
    students.push_back(new BadStudent("Морозова Анна"));
    std::vector<QuadEquation> equations = readEquationsFromFile("equations.txt");
    
    if (equations.empty()) {
        std::cout << "Нет уравнений" << std::endl;
        for (Student* s : students){
            delete s;
        }
        return 1;
    }
    
    Teacher teacher;
    for (Student* student : students) {
        for (const auto& eq : equations) {
            teacher.addEmail(eq, student);
        }
    }
    
    std::cout << "Количество писем: " << teacher.getQueueSize() << std::endl;
    teacher.checkAllEmails();
    teacher.publishGradeTable();
    for (Student* s : students){
        delete s;
    }
    return 0;
}