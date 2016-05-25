import qbs
import qbs.Probes as Probes

Module
{
    Depends{name: "cpp"}
    Probes.PathProbe
    {
        id: curlIncludeProbe
        names: ["curl.h"]
        platformPaths: ["/usr/include/curl", "/usr/include", "D:/somewhere/curl"]
    }
    Probes.PkgConfigProbe {
        id: pkgConfig
        name: "curl"
    }
    cpp.cxxFlags: pkgConfig.cflags
    cpp.linkerFlags: pkgConfig.libs

    cpp.includePaths:
    {
        var paths = [curlIncludeProbe.path];
        return paths;
    }
    cpp.dynamicLibraries: ["curl"]

}
