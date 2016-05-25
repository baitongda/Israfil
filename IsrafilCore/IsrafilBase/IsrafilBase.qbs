import qbs 1.0

DynamicLibrary {
    name: "IsrafilBase"
    destinationDirectory: "bin"
    targetName: "IsrafilBase"
    Depends {
        name: "cpp"
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
        "include/IsrafilBase/*.h",
        "../IsrafilPrefix/*.h"
    ]
}
