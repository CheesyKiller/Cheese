# D://Test/GLFW3.4/src/vulkan/CMakeLists.txt

include(GNUInstallDirs)
find_package(Vulkan REQUIRED)

# Create a STATIC library for VK
add_library(VK STATIC
    vulkan.ixx
    # Add other source files here
)

# Set the C++ standard
set_target_properties(VK PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

# Include directories
target_include_directories(VK PRIVATE
    ${Vulkan_INCLUDE_DIRS}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link Vulkan library
target_link_libraries(VK PRIVATE Vulkan::Vulkan)

# Install the VK target
install(TARGETS VK
    EXPORT glfwTargets
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)