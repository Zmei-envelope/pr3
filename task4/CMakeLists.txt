cmake_minimum_required(VERSION 3.10)
project(Task4)

# Добавляем математическую библиотеку
add_executable(Task4 main.c)
target_link_libraries(Task4 m)
