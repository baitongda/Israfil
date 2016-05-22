
#pragma once


#include <string>

#include <IsrafilNetwork/IsrafilNetwork_api.h>

#include "curl_easy.h"
#include "curl_exception.h"
#include "curl_ios.h"
#include "curl_form.h"
#include "curl_header.h"

using std::string;

using curl::curl_form;
using curl::curl_easy;
using curl::curl_pair;
using curl::curl_ios;
using curl::curl_header;
using curl::curl_easy_exception;
using curl::curlcpp_traceback;

namespace Israfil{
namespace Network{

typedef postparam std::pair<string, string>;
typedef postparams std::vector<postparam>;

class ISRAFILNETWORK_API HttpClient
{
	public:

		void printInfo();
		void addHeader(string strHeader);
		//bool addCookie(string strCookie);
		void clearHeader();
		//void initClient();
		string HttpGet(string url);
		string HttpPost(string url, string data);

		//curl_easy curleasy;
	private:
		curl_header header;

};
/**
*  @brief
*    Print information about the library to the console
*/
//ISRAFILNETWORK_API void printInfo();


} // namespace Network
} // namespace Israfil
