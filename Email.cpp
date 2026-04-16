#include "Email.h"

Email::Email(const QuadEquation& eq, Student* student) : equation(eq), student(student){
    solution = student->solveEquation(eq);
}

bool Email::check() const{
    return equation.checkSolution(solution);
}

void Email::print() const{
    std::cout << "Студент: " << student->getName() << "| Уравнение: ";
    equation.print();
    std::cout << "| Решение: [";
    for (size_t i = 0; i < solution.size(); i++) {
        std::cout << solution[i] << " ";
    }
    std::cout << "]|Результат: " << (check() ? "Верно" : "Неверно") << std::endl;
}
