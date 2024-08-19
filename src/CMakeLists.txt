# Specify the source files for your framework
set(SOURCE_FILES
    service.cpp
)

# Create a library from the source files
add_library(AiAssistFramework STATIC ${SOURCE_FILES})

# Specify include directories
target_include_directories(AiAssistFramework PUBLIC ../include)
target_link_libraries(AiAssistFramework httplib::httplib)
target_link_libraries(AiAssistFramework nlohmann_json::nlohmann_json)

set(SOURCE_FILES_REGISTRY 
    registry.cpp
)

add_executable(Registry ${SOURCE_FILES_REGISTRY})

target_include_directories(Registry PUBLIC ../include)
target_link_libraries(Registry AiAssistFramework)
target_link_libraries(Registry nlohmann_json::nlohmann_json)