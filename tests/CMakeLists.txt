add_executable(
        mesTests
        ${PROJECT_SOURCE_DIR}/Vecteur.cpp
        mesTests.cpp
)

target_include_directories(mesTests PRIVATE ${PROJECT_SOURCE_DIR} )

target_link_libraries(
        mesTests
        gtest_main
        gtest
        pthread
)

include(GoogleTest)

gtest_discover_tests(mesTests)
