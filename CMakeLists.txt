cmake_minimum_required(VERSION 3.16)
project(CAD)

set(CMAKE_CXX_STANDARD 17)

# Пути к Qt6
set(Qt6_DIR "D:/Qt/6.8.2/msvc2022_64/lib/cmake/Qt6")
find_package(Qt6 COMPONENTS Widgets Gui REQUIRED)  # Vulkan отдельно

# Добавляем Vulkan вручную
find_package(Vulkan REQUIRED)

# Включаем автоматическую генерацию MOC, UIC и RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Пути к заголовочным файлам
include_directories(${Vulkan_INCLUDE_DIRS} include)

# Собираем все файлы
file(GLOB SRC_FILES "src/*.cpp")
file(GLOB HEADER_FILES "include/*.h")  # Добавляем заголовки

# Создаем исполняемый файл
add_executable(CAD ${SRC_FILES} ${HEADER_FILES})  # Теперь CMake видит заголовки!

# Линкуем библиотеки
target_link_libraries(CAD PRIVATE Qt6::Widgets Qt6::Gui ${Vulkan_LIBRARIES})

# Пути к Qt и windeployqt
set(Qt6_BIN_DIR "D:/Qt/6.8.2/msvc2022_64/bin")  # Путь к папке bin
set(WINDEPLOYQT "${Qt6_BIN_DIR}/windeployqt.exe")

# Указываем путь к исполняемому файлу
set(TARGET_EXECUTABLE "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/CAD.exe")

# Добавляем кастомную команду для windeployqt
add_custom_command(TARGET CAD POST_BUILD
    COMMAND ${WINDEPLOYQT} --no-translations --no-opengl-sw $<TARGET_FILE:CAD>
    COMMENT "Running windeployqt to deploy Qt dependencies..."
    VERBATIM
)
