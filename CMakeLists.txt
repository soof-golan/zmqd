cmake_minimum_required( VERSION 3.19 )
project( 'ZMQD' )

include( FetchContent )

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)

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
        -DZMQ_BUILD_TESTS=OFF
)

FetchContent_Declare(
        cppzmq
        GIT_REPOSITORY https://github.com/zeromq/cppzmq.git
        GIT_TAG v4.8.1
        -DCPPZMQ_BUILD_TESTS=OFF
)

# After the following call, the CMake targets defined by googletest and
# Catch2 will be available to the rest of the build
FetchContent_MakeAvailable( googletest Catch2 json ZeroMQ cppzmq)


if (ZMQD_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
    if (CMAKE_CXX_STANDARD AND NOT CMAKE_CXX_STANDARD EQUAL 98 AND CMAKE_CXX_STANDARD GREATER_EQUAL 11)
        add_subdirectory(examples)
    endif()
endif()
