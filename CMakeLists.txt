cmake_minimum_required(VERSION 3.10)
project(KokoroPixel)

set(CMAKE_CXX_STANDARD 17)

# Include vcpkg
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg.json")
    include("C:/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif()

# Set SFML_DIR for finding SFML (vcpkg automatically handles this, but keep it just in case)
set(SFML_DIR "C:/vcpkg/installed/x64-windows/share/SFML")        

# Find SFML package
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Find ImGui-SFML package
find_package(ImGui-SFML CONFIG REQUIRED)

# Specify the include directory
include_directories(include)

# Add executable
add_executable(KokoroPixel 
    src/main.cpp
    src/dockspace.cpp
)

# Link the libraries (SFML and ImGui-SFML)
target_link_libraries(KokoroPixel sfml-graphics sfml-window sfml-system ImGui-SFML::ImGui-SFML)

# Set icon for the application
set_target_properties(KokoroPixel PROPERTIES

    RESOURCE "${CMAKE_CURRENT_SOURCE_DIR}/assets/icons/kokoro.ico"
)

# Copy assets to the build directory
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
