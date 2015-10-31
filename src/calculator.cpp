#include "calculator.hpp"
#include <numeric>
#include <functional>

calculator::calculator() :req()
{}

double calculator::get_result(std::string request) {
    double res = 0.0f, init = 0.0f;
    try
    {
        req.json_unpack(request.c_str(), request.length());
        if(req.ops.size() == 0) {
            return 0.0f;
        }

        init = *req.ops.begin();
        if(req.op == "-") {
            res = std::accumulate(++req.ops.begin(),
                            req.ops.end(),
                            init,
                            std::minus<double>());
        } else if(req.op == "+") {
            res = std::accumulate(++req.ops.begin(),
                                  req.ops.end(),
                                  init);

        } else if(req.op == "*") {
            res = std::accumulate(++req.ops.begin(),
                                  req.ops.end(),
                                  init,
                                  std::multiplies<double>());

        } else if(req.op == "/") {
            res = std::accumulate(++req.ops.begin(),
                                  req.ops.end(),
                                  init,
                                  std::divides<double>());
        }
    }
    catch(const jsonpack::invalid_json &e) {
        printf("[Invalid JSON][Error] %s (request=\"%s\")\n",e.what(), request.c_str());
    }
    catch(const jsonpack::type_error &e) {
        printf("[Type][Error] %s (request=\"%s\")\n",e.what(), request.c_str());
    }

    return res;
}
