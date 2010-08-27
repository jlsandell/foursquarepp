#ifndef _COMMON_HEADERS_H
#define _COMMON_HEADERS_H

// Intended to be used as a precompiled header, because boost takes a heck of a long time to compile.
#include <boost/asio.hpp>
#include <boost/utility.hpp> // for noncopyable

#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/transform_width.hpp>
//#include <boost/iostreams/filtering_streambuf.hpp>
//#include <boost/iostreams/copy.hpp>

//#include <boost/regex.hpp>
#include <boost/network/protocol/http.hpp>
#include <boost/network/include/http/client.hpp>
#include <boost/cast.hpp>

#include <boost/format.hpp> // make C++ output suck less.

#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <map>
#include <vector>
#include <stdexcept>
#include <cstdlib> // EXIT_SUCCESS, EXIT_FAILURE, etc.

#endif

