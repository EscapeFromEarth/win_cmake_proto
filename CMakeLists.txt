cmake_minimum_required(VERSION 3.10.0)

project(TestProto)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

aux_source_directory(./ SRC)

add_executable(test ${SRC})

find_package(Protobuf REQUIRED)
message(STATUS "Protobuf found: ${Protobuf_FOUND}")
message(STATUS "Protobuf version: ${Protobuf_VERSION}")
message(STATUS "Protobuf include dirs: ${Protobuf_INCLUDE_DIRS}")
message(STATUS "Protobuf libraries: ${Protobuf_LIBRARIES}")

target_link_libraries(test ${PROTOBUF_LIBRARIES})
target_include_directories(test PRIVATE ${PROTOBUF_INCLUDE_DIRS})
