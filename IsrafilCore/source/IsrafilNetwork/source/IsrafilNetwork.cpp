
#include <iostream>
#include <fstream>
#include <ostream>

#include <IsrafilCore/IsrafilCore-version.h>

#include <IsrafilNetwork/IsrafilNetwork.h>


namespace Israfil {
namespace Network {


void HttpClient::printInfo()
{
    // Library name
    std::cout << "Library Israfil::Network::HttpClient" << std::endl;
    std::cout << "========================================" << std::endl;

    // Library version
    std::cout << "Version: " << ISRAFILCORE_VERSION << std::endl;

    // Library type (static or dynamic)
    #ifdef ISRAFILNETWORK_STATIC_DEFINE
        std::cout << "Library type: STATIC" << std::endl;
    #else
        std::cout << "Library type: SHARED" << std::endl;
    #endif

    std::cout << std::endl;
}

void HttpClient::addHeader(string strHeader)
{
    header.add(strHeader);
}

void HttpClient::clearHeader()
{
    curl_header newheader;
    header = newheader;
}

string HttpClient::HttpGet(string url)
{
    std::ostringstream strret;
    curl_ios<std::ostringstream> writer(strret);
    curl_easy curleasy(writer);

    // init headers to client
    curleasy.add<CURLOPT_HTTPHEADER>(header.get());
    curleasy.add<CURLOPT_URL>(url.data());
    curleasy.add<CURLOPT_FOLLOWLOCATION>(1L);
    //curleasy.add<CURLOPT_HTTPGET>
    try {
        curleasy.perform();
    } catch (curl_easy_exception error) {
        curlcpp_traceback errors = error.get_traceback();
        error.print_traceback();
    }
    return strret.str();
}

string HttpClient::HttpPost(string url, postparams data)
{
    std::ostringstream strret;
    curl_ios<std::ostringstream> writer(strret);
    curl_easy curleasy(writer);

    curleasy.add<CURLOPT_HTTPHEADER>(header.get());
    curleasy.add<CURLOPT_URL>(url.data());
    //curleasy.add<CURLOPT_HTTPPOST>
    //
    //TODO: add vector processing here
}

} // namespace Network
} // namespace Israfil
