# Specify the source files for your framework
set(SOURCE_FILES
    service.cpp
)

# Create a library from the source files
add_library(AiAssistFramework STATIC ${SOURCE_FILES})

# Specify include directories
target_include_directories(AiAssistFramework PUBLIC ../include)
target_link_libraries(AiAssistFramework httplib::httplib)