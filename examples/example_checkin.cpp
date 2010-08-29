#include "common.h"
#include "foursquare.h"

int main(int argc, char* argv[])
{
    using namespace std;

    try
    {
        // for debugging
        //string apihost = "http://dev.local.lan/debug";

        string latitude = "21.385311175714428";
        string longitude = "-157.94172763824463";
        string venue_id = "713282";

        FourSquare foursquare;
        foursquare.set_credentials("user", "password");

        string response = foursquare.checkin(latitude, longitude, venue_id);
        cout << response << endl;
    }
    catch(std::runtime_error &e)
    {
        cerr << boost::format("Runtime error - \"%s\"\n") % e.what();
    }

    return 0;
}
