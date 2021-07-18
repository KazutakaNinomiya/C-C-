# a.outという実行ファイルをmain.cppから作成
add_executable(a.out main.cpp)

# set(THREADS_PREFER_PTHREAD_FLAG ON)
# find_package(Threads REQUIRED)
# target_link_libraries(a.out PRIVATE Threads::Threads)

# 最適化・警告等のオプション
target_compile_options(a.out PUBLIC 
  -O2
  -Wall
  $<$<CONFIG:Release>:-O3>             # Release
  $<$<CONFIG:Debug>:-O0 -g>            # Debug
  $<$<CONFIG:RelWithDebgInfo>:-O3 -g>  # RelWithDebInfo
)
# C++11/14/17
target_compile_features(a.out PUBLIC cxx_std_14)
# マクロ
target_compile_definitions(a.out PUBLIC
  NDEBUG _USE_MATH_DEFINES
  $<$<NOT:$<CONFIG:Debug>>:NDEBUG>     # Debug以外
)
# a.outを作成する際にlibgreetings.aをリンク
target_link_libraries(a.out greetings)