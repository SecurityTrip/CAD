cmake_minimum_required(VERSION 3.16)
project(3D-Modeler VERSION 0.1 LANGUAGES CXX)

# Включаем автоматическую обработку moc, uic и rcc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Добавляем путь для поиска UI файлов
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

# Находим необходимые компоненты Qt (например, Qt6 Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Динамически ищем файлы исходного кода, заголовки и UI файлы
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE UI_FILES "${CMAKE_CURRENT_SOURCE_DIR}/ui/*.ui")

# Создаём исполняемый файл (цель называется Model3D, а имя выходного файла — "3D-Modeler")
add_executable(Model3D
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
)

set_target_properties(Model3D PROPERTIES OUTPUT_NAME "3D-Modeler")

# Добавляем путь к заголовочным файлам
target_include_directories(Model3D PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Линкуем с библиотекой Qt6 Widgets
target_link_libraries(Model3D PRIVATE Qt6::Widgets)
