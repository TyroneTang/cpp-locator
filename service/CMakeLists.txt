#The root CMakeLists.txt file.
cmake_minimum_required(VERSION 3.28)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

#The project name is set here. In this case it's Locator, but you can change it to whatever you want.
project(locator VERSION 1.0.0 LANGUAGES CXX)

#Require C++23
set(CXX_STANDARD_REQUIRED ON) #Make C++23 a hard requirement
set(CMAKE_CXX_STANDARD 23) # Default C++ standard for targets
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

include(FetchContent)
FetchContent_Declare(
    questdb_client
    GIT_REPOSITORY https://github.com/questdb/c-questdb-client.git
    GIT_TAG        main
)
FetchContent_MakeAvailable(questdb_client)


find_package(Drogon CONFIG REQUIRED)
find_package(redis++ CONFIG REQUIRED)

#We're using the project name as the target name, but you can change it to make them different.
#With this setup, the name of the executable will be the same as the project name.
add_executable(${PROJECT_NAME} main.cpp)

target_sources(${PROJECT_NAME}
        PUBLIC
        FILE_SET CXX_MODULES FILES
        src/configurations/configuration.cppm
        src/configurations/models.cppm
        # src/redis/redis.cppm
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
        Drogon::Drogon
        redis++::redis++
        questdb_client   # ILP writes
        pq               # libpq for reads (apt install libpq-dev)
)

target_compile_options(${PROJECT_NAME} PRIVATE
        -Werror
        -Wall
        -Wextra
        -Wconversion
        -Wshadow
        -pedantic-errors
)