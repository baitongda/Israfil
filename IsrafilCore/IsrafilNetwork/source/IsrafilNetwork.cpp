
#include <iostream>
#include <fstream>
#include <ostream>

#include <IsrafilCore-version.h>
#include <IsrafilBase/IsrafilBase.h>
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
    #else // ifdef ISRAFILNETWORK_STATIC_DEFINE
  std::cout << "Library type: SHARED" << std::endl;
    #endif // ifdef ISRAFILNETWORK_STATIC_DEFINE
  std::cout << "Headers: " << std::endl;
  std::cout << header.get() << std::endl;
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

  // curleasy.add<CURLOPT_HTTPGET>
  try {
    curleasy.perform();
  } catch (curl_easy_exception error) {
    curlcpp_traceback errors = error.get_traceback();
    error.print_traceback();
  }
  return strret.str();
}

string HttpClient::HttpPost(string url, postparams& data)
{
  std::ostringstream strret;

  curl_ios<std::ostringstream> writer(strret);
  curl_easy curleasy(writer);
  curl_form curlform;

  curleasy.add<CURLOPT_HTTPHEADER>(header.get());
  curleasy.add<CURLOPT_SSL_VERIFYPEER>(false);
  curleasy.add<CURLOPT_URL>(url.data());

  dbg(data.size());
  for (int i = 0; i < data.size(); i++) {
    dbg(data[i].first);
    curl_pair<CURLformoption, string> prform(CURLFORM_COPYNAME, data[i].first);
    curl_pair<CURLformoption, string> prvalue(CURLFORM_COPYCONTENTS, data[i].second);
    curlform.add(prform, prvalue);
  }

  try {
    curleasy.add<CURLOPT_HTTPPOST>(curlform.get());
    curleasy.perform();
  }
  catch (curl_easy_exception error) {
    // If you want to get the entire error stack we can do:
    curlcpp_traceback errors = error.get_traceback();
    error.print_traceback();
  }
  return strret.str();
}

string HttpClient::HttpPost(string url, string data)
{
  std::ostringstream strret;

  curl_ios<std::ostringstream> writer(strret);
  curl_easy curleasy(writer);
  curl_form curlform;

  curleasy.add<CURLOPT_HTTPHEADER>(header.get());
  curleasy.add<CURLOPT_SSL_VERIFYPEER>(false);
  curleasy.add(curl_pair<CURLoption, string>(CURLOPT_POSTFIELDS,data));
  curleasy.add<CURLOPT_URL>(url.data());



  try {
    curleasy.add(curl_pair<CURLoption, bool>(CURLOPT_POST,  true));
    curleasy.perform();
  }
  catch (curl_easy_exception error) {
    // If you want to get the entire error stack we can do:
    curlcpp_traceback errors = error.get_traceback();
    error.print_traceback();
  }
  return strret.str();
}

} // namespace Network
} // namespace Israfil
