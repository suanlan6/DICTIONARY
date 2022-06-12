cmake_minimum_required(VERSION 3.5) # CMake install : https://cmake.org/download/
project(dictionary LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "F:/QT5.14//5.14.2/mingw73_64") # Qt Kit Dir
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5 COMPONENTS Widgets REQUIRED) # Qt COMPONENTS
aux_source_directory(./src srcs)

include_directories(F:\\mysql\\mysql-8.0.28-winx64\\include)
link_directories(F:\\mysql\\mysql-8.0.28-winx64\\lib) #添加动态连接库的路径
link_libraries(libmysql)

include_directories(F:\\curl-7.76.1\\curl-curl-7_76_1\\builds\\libcurl-vc14-x64-release-dll-ipv6-sspi-schannel\\include)
link_directories(F:\\curl-7.76.1\\curl-curl-7_76_1\\builds\\libcurl-vc14-x64-release-dll-ipv6-sspi-schannel\\lib)
link_libraries(libcurl)

include_directories(F:\\openssl-3.0.3\\output\\include)
link_directories(F:\\openssl-3.0.3\\output\\lib)
link_libraries(libcrypto)
link_libraries(libssl)

include_directories(F:\\jsoncpp\\jsoncpp\\include)
link_directories(F:\\jsoncpp\\jsoncpp\\build\\lib)
link_libraries(libjsoncpp)
link_libraries(libjsoncpp.dll)

# Specify MSVC UTF-8 encoding   
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_executable(${PROJECT_NAME}
    WIN32 # If you need a terminal for debug, please comment this statement 
    ${srcs} 
) 
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets) # Qt5 Shared Library
target_link_libraries(dictionary PUBLIC ${PROTOBUF_LIBRARY})