#define CATCH_CONFIG_MAIN

#include "../test/catch.hpp"
#include <iostream>
#include "IsrafilBase/IsrafilBase.h"
#include "IsrafilNetwork/IsrafilNetwork.h"
#include "rapidjson/document.h"

#include <fstream>
#include <string>
#include <cassert>

#define psln(x) std::cout << #x " = " << (x) << std::endl

using namespace Israfil::Base;
using namespace Israfil::Network;

TEST_CASE("Israfil Json Tests - Simple", "Json") {
    using std::string;
    using std::ifstream;

    // read json content into string.
    string      stringFromStream;
    ifstream    in;
    in.open("testsimple.json", ifstream::in);
    if (!in.is_open())
        return;
    string line;
    while (getline(in, line)) {
        stringFromStream.append(line + "\n");
    }
    in.close();

    // parse json from string.
    using rapidjson::Document;
    Document doc;
    doc.Parse<0>(stringFromStream.c_str());
    if (doc.HasParseError()) {
        rapidjson::ParseErrorCode code = doc.GetParseError();
        psln(code);
        return;
    }

    // use values in parse result.
    using rapidjson::Value;
    Value & v = doc["dictVersion"];
    if (v.IsInt()) {
        psln(v.GetInt());
    }

    Value & contents = doc["content"];
    if (contents.IsArray()) {
        for (size_t i = 0; i < contents.Size(); ++i) {
            Value & v = contents[i];
            assert(v.IsObject());
            if (v.HasMember("key") && v["key"].IsString()) {
                psln(v["key"].GetString());
            }
            if (v.HasMember("value") && v["value"].IsString()) {
                psln(v["value"].GetString());
            }
        }
    }
}

TEST_CASE("Israfil::Base Json Tests", "Json") {
    //REQUIRE(hc.printInfo() == (void)0);
    HttpClient *hc = new HttpClient();
    hc->addHeader("User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.103 Safari/537.36");
    hc->addHeader("Accept: */*");
    //hc->addHeader("Accept-Encoding: gzip,deflate,sdch");
    hc->addHeader("Accept-Language: en-us");
    hc->addHeader("Connection: keep-alive");
    hc->addHeader("Content-Type: application/x-www-form-urlencoded");
    hc->addHeader("Host: y.qq.com");
    hc->addHeader("Referer: y.qq.com");
    hc->printInfo();
    string strret = hc->HttpGet("http://s.music.qq.com/fcgi-bin/music_search_new_platform?t=0&n=10&aggr=1&cr=1&loginUin=0&format=json&inCharset=GB2312&outCharset=utf-8&notice=0&platform=jqminiframe.json&needNewCode=0&p=0&catZhida=0&remoteplace=sizer.newclient.next_song&w=%E7%9B%9B%E4%B8%96%E5%9B%9E%E9%A6%96");

}
