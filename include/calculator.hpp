#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <jsonpack.hpp>
#include <vector>

/**
 * Request format
 *
 * {"op": "-", "ops": [1,3,4,5]}
 */
struct request_op {
    std::string op = "";
    std::vector<double> ops = std::vector<double>();

    DEFINE_JSON_ATTRIBUTES(op, ops)
};


class calculator {
public:
    calculator();

    double get_result(std::string request);

private:
    request_op req;
};


#endif // CALCULATOR_HPP

