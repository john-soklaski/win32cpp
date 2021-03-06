set(header_list
    debug.h
    dynamic_library.h
    error.h
    handle.h
    lock_guard.h
    map_view_deleter.h
    module_info.h
    pch.h
    performance.h
    privilege_guard.h
    memory.h
    service.h
    string_extensions.h
    windows_constants.h
    winhttp_handle.h
)

set(source_list
    debug.cpp
    error.cpp
    module_info.cpp
    performance.cpp
    privilege_guard.cpp
    service.cpp
    string_extensions.cpp
)

set(CMAKE_DEBUG_POSTFIX  "")

ADD_MSVC_PRECOMPILED_HEADER("pch.h" "pch.cpp" source_list)
add_definitions("/analyze")
add_library(win32cpp STATIC
    ${CMAKE_SOURCE_DIR}/README.md
    ${source_list}
    ${header_list}
)

assign_source_group("Source Files" ${source_list})
assign_source_group("Header Files" ${header_list})
