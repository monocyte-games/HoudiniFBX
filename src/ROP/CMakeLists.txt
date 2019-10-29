# Locate Houdini's libraries and header files.
# Registers an imported library target named 'Houdini'.
find_package(Houdini REQUIRED)

set(MUTED_ASSETS_WORKSPACE_ROOT $ENV{MUTED_ASSETS_WORKSPACE_ROOT} CACHE FILEPATH "Muted assets workspace root")
set(INSTDIR ${MUTED_ASSETS_WORKSPACE_ROOT}/packages/houdini_fbx/1.0/houdini-${Houdini_VERSION_MAJOR}.${Houdini_VERSION_MINOR}.${Houdini_VERSION_PATCH}/houdini/dso CACHE FILEPATH "DSO install path")

set(library_name ROP_FBX)

set(CXX_SOURCES
    ROP_FBX.C
    ROP_FBXExporter.C
    ROP_FBXExporterWrapper.C
    ROP_FBXActionManager.C
    ROP_FBXAnimVisitor.C
    ROP_FBXBaseAction.C
    ROP_FBXBaseVisitor.C
    ROP_FBXCommon.C
    ROP_FBXDerivedActions.C
    ROP_FBXErrorManager.C
    ROP_FBXMainVisitor.C
    ROP_FBXUtil.C
)

set(HEADERS
    ROP_FBX.h
    ROP_FBXExporter.h
    ROP_FBXExporterWrapper.h
    ROP_FBXHeaderWrapper.h
    ROP_FBXActionManager.h
    ROP_FBXAnimVisitor.h
    ROP_FBXBaseAction.h
    ROP_FBXBaseVisitor.h
    ROP_FBXCommon.h
    ROP_FBXDerivedActions.h
    ROP_FBXErrorManager.h
    ROP_FBXMainVisitor.h
    ROP_FBXUtil.h
)

include_directories(${HOUDINI_ROOT}/toolkit/include/fbx)

add_definitions("-DK_PLUGIN -DK_FBXSDK -DK_NODLL -DEXPORT_FBX -DFBX_EXPORTS")
add_definitions(-DCUSTOM_FBX_TOKEN_PREFIX="M::" -DCUSTOM_FBX_LABEL_PREFIX="M ")

# Code generation for the embedded DS files
# houdini_generate_proto_headers(FILES ROP_FBX.C)

# Add a library and its source files.
add_library(${library_name} SHARED ${CXX_SOURCES} ${HEADERS})

# Link against the Houdini libraries, and add required include directories and
# compile definitions.
target_link_libraries(${library_name} Houdini ${HOUDINI_ROOT}/custom/houdini/dsolib/fbxsdk_md.lib)

# # Include ${CMAKE_CURRENT_BINARY_DIR} for the generated header.
# target_include_directories( ${library_name} PRIVATE
#     ${CMAKE_CURRENT_BINARY_DIR}
# )

# Sets several common target properties, such as the library's output directory.
houdini_configure_target(${library_name} INSTDIR ${INSTDIR})
