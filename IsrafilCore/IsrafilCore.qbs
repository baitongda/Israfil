 import qbs 1.0

Project {
    name: "IsrafilCore"
    //destinationDirectory: "bin"
    //targetName: "IsrafilCore"
    //Depends {
    //    name: "cpp"
    //}
    references: [
        "IsrafilBase/IsrafilBase.qbs",
        "IsrafilNetwork/IsrafilNetwork.qbs",
        "IsrafilCore/IsrafilCore.qbs",
        "ext/curlcpp/curlcpp.qbs"
    ]
}
