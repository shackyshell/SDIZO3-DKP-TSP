cmake_minimum_required(VERSION 3.8)
project(projekt3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp PlecakPrzegladZupelny.cpp PlecakPrzegladZupelny.h PlecakAlgZachlanny.cpp PlecakAlgZachlanny.h Element.h KomiwojazerPrzegladZupelny.cpp KomiwojazerPrzegladZupelny.h KomiwojazerAlgZachlanny.cpp KomiwojazerAlgZachlanny.h Testy.cpp Testy.h)
add_executable(projekt3 ${SOURCE_FILES})