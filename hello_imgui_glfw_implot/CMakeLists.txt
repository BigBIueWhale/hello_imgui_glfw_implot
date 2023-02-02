hello_imgui_add_app (hello_imgui_glfw_implot "hello_imgui_glfw_implot.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET hello_imgui_glfw_implot PROPERTY CXX_STANDARD 20)
endif()

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    if (CMAKE_CXX_COMPILER_ID MATCHES GNU) # MinGW
        target_link_options(hello_imgui_glfw_implot PRIVATE -Wl,--subsystem,windows)
        # target_link_options(hello_imgui_glfw_implot PRIVATE -Wl,--subsystem,console)
    elseif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
        set_target_properties(hello_imgui_glfw_implot PROPERTIES LINK_FLAGS /SUBSYSTEM:WINDOWS)
        # set_target_properties(hello_imgui_glfw_implot PROPERTIES LINK_FLAGS /SUBSYSTEM:CONSOLE)
    endif()
endif()
