cmake_minimum_required(VERSION 3.15)
project(VeneriX LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 3.3 REQUIRED)
find_package(glad REQUIRED)
find_package(glm REQUIRED)
find_package(imgui CONFIG REQUIRED)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

# ==========================================
# 1.             (VeneriX_Core)
# ==========================================
file(GLOB ENGINE_SOURCES "src/*.cpp" "src/*.h")
list(REMOVE_ITEM ENGINE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

add_library(VeneriX_Core SHARED ${ENGINE_SOURCES})
set_target_properties(VeneriX_Core PROPERTIES OUTPUT_NAME "venerix")
target_compile_definitions(VeneriX_Core PRIVATE VENERIX_BUILD_DLL)

target_link_libraries(VeneriX_Core PUBLIC
    glfw
    glad::glad
    glm::glm
    imgui::imgui
)
target_include_directories(VeneriX_Core PUBLIC src)

# ==========================================
# 3.                   (VeneriX SDK)
# ==========================================
install(TARGETS VeneriX_Core
    RUNTIME DESTINATION "${CMAKE_SOURCE_DIR}/VeneriX_SDK/bin"
    ARCHIVE DESTINATION "${CMAKE_SOURCE_DIR}/VeneriX_SDK/lib"
    LIBRARY DESTINATION "${CMAKE_SOURCE_DIR}/VeneriX_SDK/lib"
)

install(DIRECTORY "src/"
    DESTINATION "${CMAKE_SOURCE_DIR}/VeneriX_SDK/include"
    FILES_MATCHING PATTERN "*.h"
)

# Флаг OPTIONAL должен стоять ДО фильтров
install(DIRECTORY "${CMAKE_BINARY_DIR}/bin/Release/"
    DESTINATION "${CMAKE_SOURCE_DIR}/VeneriX_SDK/bin"
    OPTIONAL
    FILES_MATCHING PATTERN "*.dll"
)