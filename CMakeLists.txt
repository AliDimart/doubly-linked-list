cmake_minimum_required(VERSION 4.0.1 FATAL_ERROR)

project(DoublyLinkedList LANGUAGES CXX) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) #запрещает использовать нестандартные расширения, неработающие на всех компиляторах 

add_executable(DoublyLinkedList 
	src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/DLList.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/deque.h
)

target_include_directories(DoublyLinkedList PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
