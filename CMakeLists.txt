# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("hello_imgui_glfw_implot")

set(CMAKE_CXX_EXTENSIONS False) # Use -std=c++20 instead of -std=gnu++20

if (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
    add_compile_definitions(UNICODE _UNICODE)

    # https://stackoverflow.com/a/56490614
    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded") # Instead of MultiThreadedReleaseDLL
    elseif (CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebug") # Instead of MultiThreadedDebugDLL
    else()
        message(FATAL_ERROR "Must be either Debug or Release")
    endif()

    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        # Visual Studio performance profiler for Release builds
        # add_link_options("/PROFILE")
        # add_compile_options("/Z7")
    endif()
elseif (CMAKE_CXX_COMPILER_ID MATCHES GNU)
    add_compile_options(-Wall)
 
    # add_compile_options(-ftest-coverage -fprofile-arcs) # gcov

    # MinGW
    if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
        add_link_options(-static -static-libgcc -static-libstdc++)
    elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
        # ./valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=output_file.txt ./executable_name
        # add_compile_options(-ggdb3 -fno-omit-frame-pointer) # g++ Linux valgrind
        # add_compile_options(-gdwarf-5 -fno-omit-frame-pointer) # clang++ Linux valgrind
    else()
        message(FATAL_ERROR "Not Windows or Linux")
    endif()

endif()

##########################################################
# Prepare hello_imgui during configure time
##########################################################
# Select your backend
set(HELLOIMGUI_WITH_SDL OFF CACHE BOOL "" FORCE)
set(HELLOIMGUI_WITH_GLFW ON CACHE BOOL "" FORCE)
# Download hello_imgui
include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)
FetchContent_Declare(
    hello_imgui
    GIT_REPOSITORY https://github.com/pthom/hello_imgui.git
    GIT_PROGRESS TRUE
    # Enter the desired git tag below
    # GIT_TAG 0.8.0
)
FetchContent_MakeAvailable(hello_imgui)
# Make cmake function `hello_imgui_add_app` available
list(APPEND CMAKE_MODULE_PATH ${HELLOIMGUI_CMAKE_PATH})
include(hello_imgui_add_app)

add_subdirectory ("hello_imgui_glfw_implot")
