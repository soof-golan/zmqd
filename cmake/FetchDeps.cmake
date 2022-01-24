include( FetchContent )

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.8
)

FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_TAG v3.10.5
)

FetchContent_Declare(
        ZeroMQ
        GIT_REPOSITORY https://github.com/zeromq/libzmq.git
        GIT_TAG v4.3.4
)

set(ZMQ_BUILD_TESTS OFF CACHE BOOL "")
set(WITH_PERF_TOOL OFF CACHE BOOL "")
set(ENABLE_CPACK OFF CACHE BOOL "")

FetchContent_Declare(
        cppzmq
        GIT_REPOSITORY https://github.com/zeromq/cppzmq.git
        GIT_TAG v4.8.1
)

set(CPPZMQ_BUILD_TESTS OFF CACHE BOOL "")


# After the following call, the CMake targets defined by googletest and
# Catch2 will be available to the rest of the build
FetchContent_MakeAvailable( Catch2 json ZeroMQ cppzmq )
