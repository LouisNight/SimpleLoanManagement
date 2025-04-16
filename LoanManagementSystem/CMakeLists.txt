# CMakeList.txt : CMake project for LoanManagementSystem, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (LoanManagementSystem "src/LoanManagementSystem.cpp"  "include/Customer.h" "include/Loan.h" "src/Customer.cpp" "src/Loan.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LoanManagementSystem PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
