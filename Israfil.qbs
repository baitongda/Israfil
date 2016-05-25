// Temporarily using Qt Build Suite
// Waiting for LER0ever Project HydroDev
import qbs 1.0

Project {
    references: [
        "IsrafilCore/IsrafilCore.qbs",
        "src/src.qbs",
        "tests/tests.qbs"
    ]

    qbsSearchPaths: "qbs"
}
