cmake_minimum_required(VERSION 3.16)
project(CAD)

set(CMAKE_CXX_STANDARD 17)

# Пути к Qt6
set(Qt6_DIR "D:/Qt/6.8.2/msvc2022_64/lib/cmake/Qt6")
find_package(Qt6 COMPONENTS Widgets Gui REQUIRED)

# Добавляем Vulkan вручную
find_package(Vulkan REQUIRED)

# Включаем автоматическую генерацию MOC, UIC и RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Пути к заголовочным файлам
include_directories(${Vulkan_INCLUDE_DIRS} include)

# Собираем все исходники
file(GLOB SRC_FILES "src/*.cpp")
file(GLOB HEADER_FILES "include/*.h")

# Создаем исполняемый файл
add_executable(CAD ${SRC_FILES} ${HEADER_FILES})

# Линкуем необходимые библиотеки
target_link_libraries(CAD PRIVATE Qt6::Widgets Qt6::Gui ${Vulkan_LIBRARIES})

# Пути к Qt и windeployqt
set(Qt6_BIN_DIR "D:/Qt/6.8.2/msvc2022_64/bin")
set(WINDEPLOYQT "${Qt6_BIN_DIR}/windeployqt.exe")

# Добавляем кастомную команду для windeployqt с использованием генераторного выражения
add_custom_command(TARGET CAD POST_BUILD
    COMMAND ${WINDEPLOYQT} --no-translations --no-opengl-sw $<TARGET_FILE:CAD>
    COMMENT "Running windeployqt to deploy Qt dependencies..."
    VERBATIM
)

#TODO Исправить создание установщика
# # Правила установки
# install(TARGETS CAD
#     RUNTIME DESTINATION bin
# )

# # Устанавливаем дополнительные файлы (например, Qt-библиотеки)
# install(FILES "${Qt6_BIN_DIR}/Qt6Core.dll" DESTINATION bin)
# install(FILES "${Qt6_BIN_DIR}/Qt6Gui.dll" DESTINATION bin)
# install(FILES "${Qt6_BIN_DIR}/Qt6Widgets.dll" DESTINATION bin)

# # Настройки CPack для генерации установочного пакета (NSIS)
# set(CPACK_PACKAGE_NAME "CAD")
# set(CPACK_PACKAGE_VERSION "1.0.0")
# set(CPACK_GENERATOR "NSIS")
# set(CPACK_PACKAGE_INSTALL_DIRECTORY "CAD")

# include(CPack)
