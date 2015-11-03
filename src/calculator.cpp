#include "calculator.hpp"
#include <numeric>
#include <functional>
#include <json.h>
#include <cstring>


calculator::calculator()
    : m_op("+"), m_ops()
{}

double calculator::get_result(const char * expresion) {
    double res = 0.0f, init = 0.0f;

    if(!json_validate(expresion)) {
        return 0.0f;
    }

    fill_ops(expresion);

    if(m_ops.size() == 0) {
        return 0.0f;
    }

    init = *m_ops.begin();
    if(m_op == "-") {
        res = std::accumulate(++m_ops.begin(),
                        m_ops.end(),
                        init,
                        std::minus<double>());
    } else if(m_op == "+") {
        res = std::accumulate(++m_ops.begin(),
                              m_ops.end(),
                              init);

    } else if(m_op == "*") {
        res = std::accumulate(++m_ops.begin(),
                              m_ops.end(),
                              init,
                              std::multiplies<double>());

    } else if(m_op == "/") {
        res = std::accumulate(++m_ops.begin(),
                              m_ops.end(),
                              init,
                              std::divides<double>());
    }

    return res;
}

void calculator::fill_ops(const char *expresion)
{
    JsonNode * node = json_decode(expresion);
    JsonNode * object = json_find_member(node, "op");
    JsonNode * it;

    if(object != nullptr) {
        m_op = std::string(object->string_);
    }
    object = nullptr;

    object = json_find_member(node, "ops");
    if(object != nullptr) {
        json_foreach(it, object)
            if(it->tag == JSON_NUMBER) {
                m_ops.push_back(it->number_);
            }
    }

    json_delete(node);
}
