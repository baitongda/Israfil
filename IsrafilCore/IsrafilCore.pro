TEMPLATE = subdirs
SUBDIRS += \
    ext/curlcpp \
    IsrafilNetwork \
    IsrafilBase \
    IsrafilMusic \
    IsrafilCore \

IsrafilNetwork.depends = curlcpp
IsrafilNetwork.depends = IsrafilBase

IsrafilCore.depends = icQQMusic
IsrafilCore.depends = IsrafilBase
IsrafilCore.depends = IsrafilNetwork


