execute_process(COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/generateGLMModules.py)

add_library(GLM ${GLFW_LIBRARY_TYPE})

add_definitions(-DGLM_FORCE_ALIGNED_GENTYPES)

# Set C++ standard and properties for the GLM target
set_target_properties(GLM PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    LINKER_LANGUAGE CXX
)

file(GLOB ROOT_SOURCE *.cpp)
file(GLOB ROOT_INLINE *.inl)
file(GLOB ROOT_HEADER *.hpp)
file(GLOB ROOT_TEXT ../*.txt)
file(GLOB ROOT_MD ../*.md)
file(GLOB ROOT_NAT ../util/glm.natvis)

file(GLOB_RECURSE CORE_SOURCE ./detail/*.cpp)
file(GLOB_RECURSE CORE_INLINE ./detail/*.inl)
file(GLOB_RECURSE CORE_HEADER ./detail/*.hpp)

file(GLOB_RECURSE EXT_SOURCE ./ext/*.cpp)
file(GLOB_RECURSE EXT_INLINE ./ext/*.inl)
file(GLOB_RECURSE EXT_HEADER ./ext/*.hpp)

file(GLOB_RECURSE GTC_SOURCE ./gtc/*.cpp)
file(GLOB_RECURSE GTC_INLINE ./gtc/*.inl)
file(GLOB_RECURSE GTC_HEADER ./gtc/*.hpp)

file(GLOB_RECURSE GTX_SOURCE ./gtx/*.cpp)
file(GLOB_RECURSE GTX_INLINE ./gtx/*.inl)
file(GLOB_RECURSE GTX_HEADER ./gtx/*.hpp)

file(GLOB_RECURSE SIMD_SOURCE ./simd/*.cpp)
file(GLOB_RECURSE SIMD_INLINE ./simd/*.inl)
file(GLOB_RECURSE SIMD_HEADER ./simd/*.h)

file(GLOB ALL_MODULES ./modules/*.ixx)

source_group("Modules" FILES ${ALL_MODULES})
source_group("Core Files" FILES ${CORE_SOURCE} ${CORE_INLINE} ${CORE_HEADER})
source_group("EXT Files" FILES ${EXT_SOURCE} ${EXT_INLINE} ${EXT_HEADER})
source_group("GTC Files" FILES ${GTC_SOURCE} ${GTC_INLINE} ${GTC_HEADER})
source_group("GTX Files" FILES ${GTX_SOURCE} ${GTX_INLINE} ${GTX_HEADER})
source_group("SIMD Files" FILES ${SIMD_SOURCE} ${SIMD_INLINE} ${SIMD_HEADER})

set_source_files_properties(${ALL_MODULES} PROPERTIES LANGUAGE CXX)

target_include_directories(GLM PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

target_sources(GLM PRIVATE ${ROOT_TEXT} ${ROOT_MD} ${ROOT_NAT}
	${ROOT_SOURCE}    ${ROOT_INLINE}    ${ROOT_HEADER} ${ALL_MODULES}
	${CORE_SOURCE}    ${CORE_INLINE}    ${CORE_HEADER}
	${EXT_SOURCE}     ${EXT_INLINE}     ${EXT_HEADER}
	${GTC_SOURCE}     ${GTC_INLINE}     ${GTC_HEADER}
	${GTX_SOURCE}     ${GTX_INLINE}     ${GTX_HEADER}
	${SIMD_SOURCE}    ${SIMD_INLINE}    ${SIMD_HEADER})

# Install the KHR target and add to the export set
if (GLFW_INSTALL)
    install(TARGETS GLM
        EXPORT glfwTargets
        ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    )
endif()
