
include_directories(../headers)

set(SRCS
  matrix.c
  solvers.c
  triangulators.c
)

add_library(la ${SRCS})
target_link_libraries(la m)