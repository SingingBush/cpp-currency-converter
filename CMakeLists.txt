cmake_minimum_required(VERSION 3.16)
project(crypto_currency_converter LANGUAGES CXX VERSION 0.0.1 DESCRIPTION "Crypto Currency Converter")


# Note: by default ENABLE_DEVELOPER_MODE is True
# This means that all analysis (sanitizers, static analysis)
# is enabled and all warnings are treated as errors
# if you want to switch this behavior, change TRUE to FALSE
set(ENABLE_DEVELOPER_MODE
    TRUE
    CACHE BOOL "Enable 'developer mode'")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # turns off compiler specific extensions

set(SOURCE_FILES
    main.cpp
    currency.h)

add_executable(crypto_currency_converter ${SOURCE_FILES})