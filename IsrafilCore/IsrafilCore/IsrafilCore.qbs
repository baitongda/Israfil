import qbs 1.0

Product {
    type: "dynamiclibrary"
    name: "IsrafilCore"
    destinationDirectory: "bin"
    targetName: "IsrafilCore"
    Depends {
        name: "cpp"
    }

    Depends {
        name: "IsrafilBase"
    }
    Depends {
        name: "IsrafilNetwork"
    }

    cpp.includePaths: [
        "include",
        "../IsrafilPrefix"
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
