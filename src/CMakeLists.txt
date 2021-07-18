# GREETINGS_BUILD_SHARED_LIBSというオプションを作成。デフォルトをOFFに設定。
option(GREETINGS_BUILD_SHARED_LIBS "build greetings as a shared library" OFF)

if (GREETINGS_BUILD_SHARED_LIBS)
  add_library(greetings
    SHARED
    hello.cpp 
    good_morning.cpp
    thread_test.cpp
    egg_cook_thread.cpp
    rice_cook_thread.cpp
    serve_thread.cpp
  )
else()
  add_library(greetings 
    STATIC 
    hello.cpp
    good_morning.cpp
    thread_test.cpp
    egg_cook_thread.cpp
    rice_cook_thread.cpp
    serve_thread.cpp
  )
endif()

target_include_directories(greetings
  PUBLIC ${PROJECT_SOURCE_DIR}/include
  )