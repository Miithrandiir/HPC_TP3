cmake_minimum_required (VERSION 3.1)
project (lr)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRCS
    ./Src/lr.cpp
    ./Src/Objet.cpp
    ./Src/Sphere.cpp
    ./Src/Materiau.cpp
    ./Src/Couleur.cpp
    ./Src/Plan.cpp
    ./Src/Scene.cpp
    ./Src/Point.cpp
    ./Src/Vecteur.cpp
    ./Src/Intensite.cpp
    ./Src/Source.cpp
    ./Src/Image.cpp
    ./Src/Camera.cpp
    ./Src/Rayon.cpp
    ./Src/Intersection.cpp
    ./Src/Triangle.cpp
    )
    
set(HEADERS
    ./Src/Objet.hpp
    ./Src/Sphere.hpp
    ./Src/Materiau.hpp
    ./Src/Couleur.hpp
    ./Src/Plan.hpp
    ./Src/Scene.hpp
    ./Src/Point.hpp
    ./Src/Vecteur.hpp
    ./Src/Intensite.hpp
    ./Src/Source.hpp
    ./Src/Image.hpp
    ./Src/Camera.hpp
    ./Src/Rayon.hpp
    ./Src/Intersection.hpp
    ./Src/Triangle.hpp
    )

#add_definitions(-std=c++11 -O2 -pthread -g)
add_compile_options(-std=c++11  -O2 -g)

find_package( Threads )

add_executable(lr ${SRCS} ${HEADERS})
target_link_libraries( lr ${CMAKE_THREAD_LIBS_INIT} )

