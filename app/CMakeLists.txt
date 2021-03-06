cmake_minimum_required(VERSION 3.4.1)
add_library( native_ffmpeg
             SHARED
             src/main/cpp/native_ffmpeg.cpp )
find_library( log-lib
              log )
find_library( android-lib
              android )
set(distribution_DIR ${CMAKE_SOURCE_DIR}/src/main/jniLibs/armeabi-v7a)
add_library( avutil
             SHARED
             IMPORTED )
set_target_properties( avutil
                       PROPERTIES IMPORTED_LOCATION
                       ${distribution_DIR}/libavutil.so)
add_library( swresample
             SHARED
             IMPORTED )
set_target_properties( swresample
                       PROPERTIES IMPORTED_LOCATION
                       ${distribution_DIR}/libswresample.so)
add_library( avcodec
             SHARED
             IMPORTED )
set_target_properties( avcodec
                       PROPERTIES IMPORTED_LOCATION
                       ${distribution_DIR}/libavcodec.so)
add_library( avfilter
             SHARED
             IMPORTED )
set_target_properties( avfilter
                       PROPERTIES IMPORTED_LOCATION
                       ${distribution_DIR}/libavfilter.so)
add_library( swscale
             SHARED
             IMPORTED )
set_target_properties( swscale
                       PROPERTIES IMPORTED_LOCATION
                       ${distribution_DIR}/libswscale.so)
add_library( avformat
             SHARED
             IMPORTED )
set_target_properties( avformat
                       PROPERTIES IMPORTED_LOCATION
                       ${distribution_DIR}/libavformat.so)
set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
include_directories(src/main/cpp)
include_directories(src/main/jniLibs/include)

target_link_libraries(native_ffmpeg
                      avutil       #工具库(大部分需要)
                      swresample    #音频采样数据格式转换
                      avcodec      #编解码(重要)
                      avfilter      #滤镜特效处理
                      swscale       #视频像素数据格式转换
                      avformat     #封装格式处理
                      ${log-lib}
                      ${android-lib})