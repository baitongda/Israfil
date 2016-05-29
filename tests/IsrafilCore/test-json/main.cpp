#define CATCH_CONFIG_MAIN

#include "../test/catch.hpp"
#include <iostream>
#include "IsrafilBase/IsrafilBase.h"
//#include "IsrafilNetwork/IsrafilNetwork.h"
#include "rapidjson/document.h"

#include <fstream>
#include <string>
#include <cassert>

#define psln(x) std::cout << #x " = " << (x) << std::endl

using namespace Israfil::Base;

const string qmsearchurl = "http://s.music.qq.com/fcgi-bin/music_search_new_platform?t=0&n={0}&aggr=1&cr=1&loginUin=0&format=json&inCharset=GB2312&outCharset=utf-8&notice=0&platform=jqminiframe.json&needNewCode=0&p=1&catZhida=0&remoteplace=sizer.newclient.next_song&w={1}";

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
        REQUIRE(v.GetInt() == 1);
    }

    Value & contents = doc["content"];
    if (contents.IsArray()) {
        for (size_t i = 0; i < contents.Size(); ++i) {
            Value & v = contents[i];
            assert(v.IsObject());
            REQUIRE(v.IsObject() ==true);

            std::stringstream ss;
            std::string str;
            ss<<i+1;
            ss>>str;

            if (v.HasMember("key") && v["key"].IsString()) {
                psln(v["key"].GetString());

                REQUIRE(v["key"].GetString() == "word"+str);
            }
            if (v.HasMember("value") && v["value"].IsString()) {
                psln(v["value"].GetString());
                REQUIRE(v["value"].GetString() == "单词"+str);
            }
        }
    }
}

TEST_CASE("Israfil Json Tests - Complex", "Json") {
    //REQUIRE(hc.printInfo() == (void)0);
    using std::string;
    using std::ifstream;

    // read json content into string.
    string      stringFromStream;
    ifstream    in;
    in.open("testcomplex.json", ifstream::in);
    if (!in.is_open())
        return;
    string line;
    while (getline(in, line)) {
        stringFromStream.append(line + "\n");
    }
    in.close();

    using rapidjson::Document;
    Document doc;
    doc.Parse<0>(stringFromStream.c_str());
    if (doc.HasParseError()) {
        rapidjson::ParseErrorCode code = doc.GetParseError();
        psln(code);
        return;
    }

    using rapidjson::Value;
    Value &retcode = doc["code"];
    if (retcode.IsInt()){
        psln(retcode.GetInt());
        REQUIRE(retcode.GetInt() == 0);
    }
    Value &data = doc["data"];
    psln(data["keyword"].GetString());
    //REQUIRE(data["keyword"].GetString() == "慕寒");
    Value &song = data["song"];
    Value &list = song["list"];
    REQUIRE(list.IsArray() == true);
    psln(list.Size());
    REQUIRE(list.Size()+1 == song["curnum"].GetInt());
    psln(Israfil::strfmt::Format(qmsearchurl,20,"SBA"));
}
