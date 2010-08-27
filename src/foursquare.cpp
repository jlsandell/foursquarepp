#include "common.h"
#include "foursquare.h"

using namespace boost::network;

FourSquare::FourSquare(const std::string &apihost, const std::string &useragent): m_apihost(apihost),
                                                                                  m_useragent(useragent),
                                                                                  m_credentials("")
{
}

void FourSquare::set_useragent(const std::string &useragent)
{
    m_useragent = useragent;
}


FourSquare::~FourSquare()
{
}

void FourSquare::set_credentials(const std::string &username, const std::string &password)
{
    m_credentials = b64encode(username + ":" + password);
}

//modeled after Python's base64.b64encode
std::string FourSquare::b64encode(const std::string &text)
{
    typedef boost::archive::iterators::base64_from_binary<boost::archive::iterators::transform_width<std::string::const_iterator, 6, 8> > base64_t;

    std::string enc(base64_t(text.begin()), base64_t(text.end()));

    return enc;
}


std::string FourSquare::get_content_length(std::string const &content)
{
    return boost::lexical_cast<std::string>(content.length());
}   

std::string FourSquare::urlencode(const std::map<std::string, std::string> &argmap)
{
    std::string encoded;

    // XXX: Would a stringstream be faster?
    for (std::map<std::string, std::string>::const_iterator iter = argmap.begin(); iter != argmap.end(); iter++)
        encoded += urlencode_str(iter->first) + "=" + urlencode_str(iter->second) + "&";

    // Remove the last ampersand.
    return encoded.erase(encoded.size() -1, 1);
}

std::string FourSquare::urlencode_str(const std::string &input)
{
    char buffer[4];

    std::string encoded;

    // XXX: Would a stringstream be faster?
    for(std::string::const_iterator iter = input.begin(); iter != input.end(); iter++)
    {   
        unsigned short ascii = *iter;

        if((ascii > 47 && ascii < 58) || (ascii > 64 && ascii < 91) || (ascii > 96 && ascii < 123))
            encoded += *iter;

        else if (ascii == 32) 
            encoded += "+";

        else
        {   
            ::snprintf(buffer, 4, "%%%.2x", ascii);
            encoded += buffer;
        }
    }
    return encoded;
}

http::client::response FourSquare::checkin(const std::string &latitude,
                                           const std::string &longitude,
                                           const std::string &vid)
{
    http::client::request request;
    std::ostringstream uri;

    uri << boost::format("%s/v1/checkin.json") % m_apihost;

    std::map<std::string, std::string> params;

    params["vid"]     = vid;
    params["private"] = "0";
    params["geolat"]  = latitude;
    params["geolong"] = longitude;

    request = build_request(uri.str(), params);

    http::client client;
    http::client::response response;
    response = client.post(request);
    return response;
}


http::client::request FourSquare::build_request(const std::string &uri,
                                                const std::map<std::string, std::string> &data,
                                                const bool authenticate)
{
    /*
        urlencode our mapping into something postable, set an
        appropriate content-type and content-length, and return
        the initialized request object.
    */

    const std::string postdata = urlencode(data);
    const std::string content_length = get_content_length(postdata);
    const std::string content_type = "application/x-www-form-urlencoded";

    http::client::request request(uri);

    request << header("Content-Length", content_length);
    request << header("Content-Type", content_type);
    request << header("User-Agent", m_useragent);

    if (authenticate && (!m_credentials.empty()))
        request << header("Authorization", "Basic " + m_credentials);

    request << body(postdata);
    return request;
}
