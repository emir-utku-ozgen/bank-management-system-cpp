cmake_minimum_required(VERSION 3.20)
project(BankaSistemi)

set(CMAKE_CXX_STANDARD 20)

# Ana kütüphanemiz
add_library(banka_lib STATIC src/Banka.cpp)
target_include_directories(banka_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Konsol uygulamamız (main fonksiyonunun olacağı yer)
add_executable(banka_app src/main.cpp)
target_link_libraries(banka_app PRIVATE banka_lib)

# Test programımız (assert'leri çalıştıracağımız yer)
add_executable(banka_testleri tests/banka_tests.cpp)
target_link_libraries(banka_testleri PRIVATE banka_lib)