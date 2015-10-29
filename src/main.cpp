#include <lwan/lwan.h>

#include <cstdio>
#include <memory>
#include <cstring>

#include "calculator.hpp"

lwan_http_status_t view_calculator(lwan_request_t * req,
                                   lwan_response_t *response,
                                   void *data __attribute__((unused)))
{
    if (!(req->flags & REQUEST_METHOD_POST))
    {
        static const char message[] = "USE:  curl --data-urlencode \"query={\"op\": \"-\", \"ops\": [3, 1]}\" http://localhost:8888";
        response->mime_type = "text/plain";
        strbuf_set_static(response->buffer, message, sizeof(message) - 1);
    } else {
        response->mime_type = "text/plain";
        lwan_key_value_t *qs;
        for (qs = req->post_data.base; qs->key; qs++) {
            if(strcmp(qs->key, "query") == 0) {
                calculator calc;
                strbuf_append_printf(response->buffer,
                               "\"%f\"\n", calc.get_result(std::string(qs->value)));
            }
        }
    }

    return HTTP_OK;
}



int main() {

    lwan_url_map_t url_root, url_empty;
    url_root.prefix = "/";
    url_root.handler = view_calculator;
    const lwan_url_map_t default_map[] = {url_root, url_empty};

    lwan_t l;
    lwan_config_t config;
    config = *lwan_get_default_config();

    config.listener = strdup("*:8888");

    lwan_init_with_config(&l, &config);

    lwan_set_url_map(&l, default_map);

    lwan_main_loop(&l);

    lwan_shutdown(&l);

    free(config.listener);

    return 0;
}
