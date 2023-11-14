
#include "web_server/http_web_server.h"
int main(int argc, char*argv[])
{
    HTTPWebServer app;
    return app.run(argc, argv);
}

//#include "database/wall.h"
//
//using namespace database;
//
//int main()
//{
//    //Wall w = Wall();
//    long a = 1;
//    std::vector<Wall> v = Wall::get(a);
//    for (const Wall& w : v) {
//        Poco::JSON::Stringifier::stringify(w.toJSON(), std::cout);
//    }
//}