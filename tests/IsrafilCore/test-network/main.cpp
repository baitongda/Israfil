#define CATCH_CONFIG_MAIN

#include "../test/catch.hpp"
#include <iostream>
#include "IsrafilNetwork.h"

using namespace Israfil::Network;
HttpClient *hc = new HttpClient();

TEST_CASE("Israfil::Network Basic Tests", "HttpClient") {
	//REQUIRE(hc.printInfo() == (void)0);
	hc->printInfo();
	std::cout << hc->HttpGet("http://music.163.com") << std::endl;

}
