#include "calculator.hpp"
#include <numeric>
#include <functional>

calculator::calculator() :req()
{}

double calculator::get_result(std::__cxx11::string request) {
    double res = 0.0f, init = 0.0f;

    req.json_unpack(request.c_str(), request.length());

    if(req.ops.size() == 0) {
        return 0.0f;
    }

    if(req.ops.size() == 1) {
        return *req.ops.begin();
    }

    if(req.op == "-") {
        init = *req.ops.begin();
        res = std::accumulate(++req.ops.begin(),
                        req.ops.end(),
                        init,
                        std::minus<double>());

    } else if(req.op == "+") {

        res = std::accumulate(req.ops.begin(),
                              req.ops.end(),
                              init);

    } else if(req.op == "*") {

        init = *req.ops.begin();
        res = std::accumulate(++req.ops.begin(),
                              req.ops.end(),
                              init,
                              std::multiplies<double>());

    } else if(req.op == "/") {

        init = *req.ops.begin();
        res = std::accumulate(++req.ops.begin(),
                              req.ops.end(),
                              init,
                              std::divides<double>());

    }

    return res;
}
