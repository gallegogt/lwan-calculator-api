#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <vector>
#include <string>

class calculator {
public:
    calculator();
    double get_result(const char* expresion);
private:
    void fill_ops(const char* expresion);

    std::string m_op;
    std::vector<double> m_ops;
};


#endif // CALCULATOR_HPP

