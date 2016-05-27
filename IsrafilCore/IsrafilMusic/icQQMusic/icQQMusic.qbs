import qbs

Product {
    type: "dynamiclibrary"
    name: "icQQMusic"
    destinationDirectory: "bin"
    targetName: "icQQMusic"

    Depends {
        name: "cpp"
    }

    Depends {
        name: "IsrafilNetwork"
    }
    Depends {
        name: "IsrafilBase"
    }
    Depends {
        name: "curlcpp"
    }
    Depends {
        name: "libcurl"
    }

    cpp.includePaths: [
        "../../IsrafilPrefix",
        "../../IsrafilNetwork/include",
        "../../ext/curlcpp/include",
        "../../ext/rapidjson/include"
    ]
    cpp.cppFlags: [
        "-std=c++11"
    ]

    files: [
        "base.h",
        "qqmusic.cpp",
        "qqmusic.h",
    ]
}
