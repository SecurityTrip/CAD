cmake_minimum_required(VERSION 3.16)
project(QtVulkanApp)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)

set(Qt6_DIR "D:/Qt/6.8.2/msvc2022_64/lib/cmake/Qt6")
find_package(Qt6 COMPONENTS Widgets Gui REQUIRED)  # Убрали Vulkan

# Добавляем Vulkan вручную
find_package(Vulkan REQUIRED)
include_directories(${Vulkan_INCLUDE_DIRS})

add_executable(QtVulkanApp main.cpp vulkanwindow.cpp)

target_link_libraries(QtVulkanApp PRIVATE Qt6::Widgets Qt6::Gui ${Vulkan_LIBRARIES})
