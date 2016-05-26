import qbs 1.0
import qbs.Probes as Probes

Product {
    type: "dynamiclibrary"
    name: "curlcpp"
    targetName: "curlcpp"
    destinationDirectory: "bin"
    qbsSearchPaths: "qbs"
    Depends {
        name: "cpp"
    }
    Depends {
        name: "libcurl"
    }

    cpp.includePaths: [
        "include"
    ]
    cpp.cppFlags: [
        "-std=c++11"
    ]
    cpp.warningLevel: "default"

    files: [
        "src/*.cpp",
        "include/*.h"
    ]
}
