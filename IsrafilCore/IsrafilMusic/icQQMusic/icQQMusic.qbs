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

    cpp.includePaths: [
        "../../IsrafilPrefix",
        "../../ext/rapidjson/include"
    ]
    cpp.cppFlags: [
        "-std=c++11"
    ]

    files: [
        "base.h"
    ]
}
