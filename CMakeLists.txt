cmake_minimum_required(VERSION 3.13)
project(hangman)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)
include_directories(src)
include_directories(bin/Debug)

add_executable(hangman
    include/Character.h
    include/Dictionary.h
    include/Game.h
    include/Vector.h
    include/Word.h
    src/Character.cpp
    src/Dictionary.cpp
    src/Game.cpp
        src/Word.cpp
    input.txt
    main.cpp)
