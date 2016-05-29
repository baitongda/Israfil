TEMPLATE = subdirs

#SUBDIRS += IsrafilCore plugins
#plugins.depends = IsrafilCore

qtHaveModule(quick) {
    SUBDIRS += quick
    #quick.depends = IsrafilCore
    plugins.depends = quick
}

#qtHaveModule(widgets) {
#    SUBDIRS += widgets
#    widgets.depends = IsrafilCore
#    plugins.depends = widgets
#}
