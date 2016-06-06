TEMPLATE = subdirs
SUBDIRS += IsrafilCore IsrafilApp doc tests
CONFIG += C++11

OTHER_FILES += README.md \
    LICENSE.md \
    .appveyor.yml \
    .travis.yml \
    uncrustify.cfg
