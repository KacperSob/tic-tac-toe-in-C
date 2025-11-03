add_library(logic_lib SHARED tictactoe.c)

target_include_directories(logic_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
