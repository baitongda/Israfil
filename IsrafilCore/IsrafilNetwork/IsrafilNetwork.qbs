import qbs 1.0

DynamicLibrary {
    name: "IsrafilNetwork"
    destinationDirectory: "bin"
    targetName: "IsrafilNetwork"
    Depends {
        name: "cpp"
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
        "include",
        "../IsrafilPrefix",
        "../ext/curlcpp/include"
    ]
    cpp.cppFlags: [
        "-std=c++11"
    ]

    files: [
        "source/*.cpp",
        "include/IsrafilCore/*.h",
        "../IsrafilPrefix/*.h"
    ]

}
