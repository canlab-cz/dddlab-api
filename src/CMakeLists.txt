# Copyright (c) 2022 Canlab s.r.o,  All Rights Reserved

# Download automatically
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(REQUIRES 
		libcurl/7.80.0
        	BASIC_SETUP CMAKE_TARGETS
		GENERATORS cmake_find_package cmake_paths
		BUILD missing)

include(${CMAKE_BINARY_DIR}/libdddlabapi/conan_paths.cmake)

find_package( CURL REQUIRED )

set(src_files
	dddlabapi.cpp
)

set(header_files	
	dddlabapi.h
	${DDD_VERSION_H}
)
#set(CMAKE_C_FLAGS "... -Werror=implicit-function-declaration")
add_library(libdddlabapi STATIC ${src_files} ${header_files} )

target_include_directories(libdddlabapi PRIVATE ${PROJECT_BINARY_DIR} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(libdddlabapi CURL::libcurl)

set_property(TARGET libdddlabapi PROPERTY CXX_STANDARD 17)
