#include "foursquare.h"

int main(int argc, char* argv[])
{
    using namespace std;
    using namespace boost::network::http;

    try
    {
        // for debugging
        string apihost = "http://dev.local.lan/debug";

        string latitude = "21.385311175714428";
        string longitude = "-157.94172763824463";
        string venue_id = "713282";

        client::response response;

        FourSquare foursquare(apihost);
        foursquare.set_credentials("user", "password");

        response = foursquare.checkin(latitude, longitude, venue_id);
        cout << body(response) << endl;

    }
    catch(std::runtime_error &e)
    {
        cerr << format("Runtime error - \"%s\"\n") % e.what();
    }

    return 0;
}
