cmake_minimum_required(VERSION 3.10)


#project name and language
set(PACKAGE_NAME IMAGEOVERLAY_CMAKE) # 이 부분이 문제였음
project( "imageoverlay" )

#project will use the C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set dir for header and library


# opencv 디렉토리 찾기
#find_package(OpenCV REQUIRED)
#find_package(OpenCV REQUIRED gapi stitching aruco alphamat bgsegm bioinspired ccalib)
set(OpenCV_DIR "/usr/local/include/opencv4/opencv2")

message(STATUS "OpenCV version: ${OpenCV_VERSION}")

# include directories
#include_directories( ${OpenCV_INCLUDE_DIRS} )
#include_directories("${PROJECT_SOURCE_DIR}/include")
#set(OpenCV_DIR "/usr/local/include/opencv4/opencv2")

# Specify the cross-compilers
#set(CMAKE_C_COMPILER /usr//bin/gcc)        # Replace with your GCC path
#set(CMAKE_CXX_COMPILER /mnt/c/Windows/System32/mingw64/bin/g++)


#실행파일 추가
add_executable(imageoverlay src/main.cpp src/Imageoverlay.c) #check your file path
target_link_libraries(imageoverlay ${OpenCV_LIBS})


#크로스 컴파일 필요
set_target_properties(imageoverlay PROPERTIES SUFFIX ".exe")
