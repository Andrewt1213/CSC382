cmake_minimum_required(VERSION 3.23)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 20)

include_directories(C:/Users/Lenovo/CLionProjects/CSC382)

add_executable(TicTacToe GUIview.cpp main.cpp)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# You may need to adjust this, especially if you picked a different install directory.
# Browse through the folders in case there is a slight difference.
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.5.0\\mingw_64\\lib\\cmake")

find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)
target_link_libraries(TicTacToe Qt6::Core)
target_link_libraries(TicTacToe Qt6::Widgets)