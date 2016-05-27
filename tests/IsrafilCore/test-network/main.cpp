#define CATCH_CONFIG_MAIN

#include "../test/catch.hpp"
#include <iostream>
#include "IsrafilNetwork/IsrafilNetwork.h"

using namespace Israfil::Network;
HttpClient *hc = new HttpClient();

TEST_CASE("Israfil::Network Basic Tests", "HttpClient") {
	//REQUIRE(hc.printInfo() == (void)0);
    hc->addHeader("User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.103 Safari/537.36");
    hc->addHeader("Accept: */*");
    //hc->addHeader("Accept-Encoding: gzip,deflate,sdch");
    hc->addHeader("Accept-Language: en-us");
    hc->addHeader("Connection: keep-alive");
    hc->addHeader("Content-Type: application/x-www-form-urlencoded");
    hc->addHeader("Host: y.qq.com");
    hc->addHeader("Referer: y.qq.com");
	hc->printInfo();
    std::cout << hc->HttpGet("http://s.music.qq.com/fcgi-bin/music_search_new_platform?t=0&n=10&aggr=1&cr=1&loginUin=0&format=json&inCharset=GB2312&outCharset=utf-8&notice=0&platform=jqminiframe.json&needNewCode=0&p=0&catZhida=0&remoteplace=sizer.newclient.next_song&w=%E7%9B%9B%E4%B8%96%E5%9B%9E%E9%A6%96") << std::endl;

}
