#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <random>
#include <drogon/drogon.h>
#include "../../network/source/network.h"

using namespace drogon;

typedef std::function<void(const HttpResponsePtr&)> Callback;
network* nn;

void log(std::string s)
{
    std::cout << s << std::endl;
}

void root_handler(const HttpRequestPtr& request, Callback&& callback) {
    log("");
    log("/ request");
    std::ofstream outf("request.bmp", std::ios::out | std::ios::binary);
    outf << request->getBody();
    outf.close();

    Json::Value jsonBody;
    int result = nn->recognize(std::ifstream("request.bmp", std::ios::in | std::ios::binary), "bmp");
    jsonBody["result"] = result;
    log("returned " + std::to_string(result));

    auto response = HttpResponse::newHttpJsonResponse(jsonBody);
    callback(response);
}

bool ask_YN(std::string q)
{
    std::string inp;
    std::cout << q << " (Y/N) ";

    if (!(std::cin >> inp))
    {
        return ask_YN(q);
    }

    if (inp == "Y" || inp == "y" || inp == "")
    {
        return true;
    }
    else if (inp == "N" || inp == "n")
    {
        return false;
    }
    else
    {
        return ask_YN(q);
    }
}

int main()
{
    const int APP_PORT = 8000;
    const std::string APP_HOST = "127.0.0.1";

    bool do_train = ask_YN("Train network?");
    nn = new network(std::vector<size_t>{784, 32, 32, 10}, do_train);

    log("Started on port " + std::to_string(APP_PORT));
    app()
        .registerHandler("/", &root_handler, { Get })
        .addListener(APP_HOST, APP_PORT)
        .setThreadNum(1)
        .enableServerHeader(false)
        .run();
    return EXIT_SUCCESS;
}