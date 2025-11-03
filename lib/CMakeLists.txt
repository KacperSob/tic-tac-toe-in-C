add_library(logic_lib SHARED tictactoe.c tests.c)

target_include_directories(logic_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
