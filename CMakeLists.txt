cmake_minimum_required(VERSION 3.10)
project(sysdoctor)

set(CMAKE_CXX_STANDARD 17)

#find_package(onnxruntime REQUIRED)
include_directories(/usr/local/onnxruntime/include)
link_directories(/usr/local/onnxruntime/lib)


add_executable(sysdoctor
    src/main.cpp
    src/system_metrics.cpp
    src/ai_engine.cpp
    src/onnx_engine.cpp
    src/runtime_config.cpp
    src/simulator.cpp
    src/rules_config.cpp
)

target_link_libraries(sysdoctor onnxruntime)

