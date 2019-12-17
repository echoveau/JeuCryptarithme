project(JeuCryptarithme)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} "main.cpp" "domaine.h" "domaine.cpp" "variable.h" "variable.cpp" "contrainte.h" "contrainte.cpp")
