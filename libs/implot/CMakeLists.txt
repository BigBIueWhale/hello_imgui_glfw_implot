add_library(implot STATIC
            implot/implot_internal.h
            implot/implot_items.cpp
            implot/implot.cpp
            implot/implot.h)

target_link_libraries(implot PUBLIC imgui)
