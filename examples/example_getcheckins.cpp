#include "common.h"
#include "foursquare.h"

int main(int argc, char* argv[])
{
    using namespace std;

    try
    {
        // for debugging
        //string apihost = "http://dev.local.lan/debug";

        FourSquare foursquare;
        foursquare.set_credentials("user", "password");

        string response = foursquare.get_checkins();
        cout << response << endl;
    }
    catch(std::runtime_error &e)
    {
        cerr << boost::format("Runtime error - \"%s\"\n") % e.what();
    }

    return 0;
}
