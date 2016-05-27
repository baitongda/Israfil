TEMPLATE = subdirs
SUBDIRS += \
    ext/curlcpp \
    IsrafilNetwork \
    IsrafilCore \
    IsrafilBase \
    IsrafilMusic

IsrafilNetwork.depends = curlcpp
IsrafilNetwork.depends = IsrafilBase
