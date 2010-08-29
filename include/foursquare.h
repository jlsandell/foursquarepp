#ifndef _FOURSQUARE_H
#define _FOURSQUARE_H

#include "common.h"


class FourSquare : boost::noncopyable {

    std::string m_username;
    std::string m_password;
    std::string m_useragent;
    std::string m_apihost;

    std::string m_credentials;

    boost::network::http::client::request build_request(const std::string &uri,
                                        const std::map<std::string, std::string> &data,
                                        const bool authenticate = true);

    // get request
    boost::network::http::client::request build_request(const std::string &uri,
                                                        const bool authenticate = true);


public:
    FourSquare(const std::string &apihost = "http://api.foursquare.com",
               const std::string &useragent = "Mozilla/5.0 (iPhone; U; CPU like Mac OS X; en) AppleWebKit/420 (KHTML, like Gecko) Version/3.0 Mobile/1C10 Safari/419.3+");

    ~FourSquare();


    /*boost::network::http::client::response*/ std::string checkin(const std::string &latitude,
                                                   const std::string &longitude,
                                                   const std::string &vid);

    //boost::network::http::client::response get_checkins();
    std::string get_checkins();

    std::string urlencode_str(const std::string &input);
    std::string urlencode(const std::map<std::string, std::string> &argmap);

    std::string get_content_length(std::string const &content);
    std::string b64encode(const std::string &text);

    void set_credentials(const std::string &username,
                         const std::string &password);

    void set_useragent(const std::string &useragent);
};
#endif
