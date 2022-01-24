cmake_minimum_required( VERSION 3.16 )
project( zmqd )

include(cmake/FetchDeps.cmake)

add_executable( zmqd src/main.cpp )
target_link_libraries( zmqd PRIVATE nlohmann_json::nlohmann_json )
target_link_libraries( zmqd PRIVATE cppzmq )
set_property(TARGET zmqd PROPERTY CXX_STANDARD 20)