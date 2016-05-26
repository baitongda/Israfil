import qbs 1.0

Product {
    type: "application"
    consoleApplication: true
    destinationDirectory: "bin"
    name : "test-network"
    files : [ "main.cpp" ]
    Depends { name: "cpp" }
    Depends { name: "IsrafilNetwork" }
    Depends {
        name: "curlcpp"
    }
    Depends {
        name: "libcurl"
    }

    cpp.includePaths: [
        "../../../IsrafilCore/IsrafilNetwork/include/IsrafilNetwork",
        "../../../IsrafilCore/IsrafilPrefix",
        "../../../IsrafilCore/ext/curlcpp/include"
    ]
}
