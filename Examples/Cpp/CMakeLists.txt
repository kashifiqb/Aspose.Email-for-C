cmake_minimum_required(VERSION 3.5)
set (target SampleProject)
project(${target} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(DEFINED ASPOSE_ROOT)
    message(STATUS "Using ASPOSE_ROOT value from cmake: ${ASPOSE_ROOT}")
elseif(DEFINED ENV{ASPOSE_ROOT})
    set(ASPOSE_ROOT $ENV{ASPOSE_ROOT})
    message(STATUS "Using ASPOSE_ROOT value from environment: ${ASPOSE_ROOT}")
else()
    message(ERROR "ASPOSE_ROOT not set")
endif()
file(TO_CMAKE_PATH "${ASPOSE_ROOT}" ASPOSE_ROOT)

if(DEFINED ASPOSE_EMAIL_CPP_ROOT)
    message(STATUS "Using ASPOSE_EMAIL_CPP_ROOT value from cmake: ${ASPOSE_EMAIL_CPP_ROOT}")
elseif(DEFINED ENV{ASPOSE_EMAIL_CPP_ROOT})
    set(ASPOSE_EMAIL_CPP_ROOT $ENV{ASPOSE_EMAIL_CPP_ROOT})
    message(STATUS "ASPOSE_EMAIL_CPP_ROOT: ${ASPOSE_EMAIL_CPP_ROOT}")
else()
    message(ERROR "ASPOSE_EMAIL_CPP_ROOT is not set")
endif()

find_package(CodePorting.Native.Cs2Cpp REQUIRED CONFIG PATHS ${ASPOSE_ROOT})
find_package(Aspose.Email.Cpp REQUIRED CONFIG PATHS ${ASPOSE_EMAIL_CPP_ROOT})

file(GLOB_RECURSE srcs "source/*.cpp" "source/*.h")
file(GLOB_RECURSE hdrs "include/*.h")

add_executable(${target} ${srcs} ${hdrs})

target_include_directories(${target} PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/include  
		${CMAKE_CURRENT_SOURCE_DIR}/source  )


target_link_libraries(${target} PRIVATE Aspose.Email.Cpp)
target_link_libraries(${target} PRIVATE Aspose::CodePorting.Native.Cs2Cpp)
target_link_libraries(${target} PRIVATE CodePorting.Native.Cs2Cpp)


add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy 
        $<TARGET_FILE:Aspose.Email.Cpp>
        $<TARGET_FILE_DIR:${target}>)
add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:Aspose::CodePorting.Native.Cs2Cpp>
        $<TARGET_FILE_DIR:${target}>)  