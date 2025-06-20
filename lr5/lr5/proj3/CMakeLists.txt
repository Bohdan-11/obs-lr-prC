cmake_minimum_required(VERSION 3.15)
project(proj3-html-parser C)
add_executable(htmlparser main.c htmlutils.c)
# Пытаемся найти libcurl
find_package(CURL)

if(CURL_FOUND)
	target_compile_definitions(htmlparser PRIVATE USE_CURL)
	target_include_directories(htmlparser PRIVATE ${CURL_INCLUDE_DIRS})
	target_link_libraries(htmlparser PRIVATE ${CURL_LIBRARIES})
else()
	message(WARNING "libcurl not found, building without network support.")
endif()