
#include <iostream>

#define EXPECT(A) {  std::cout << (std::string("") + ((A) ? " OK " : "FAIL")) + " : " #A << std::endl; } 
#define EXPECT_EQ(A,B) EXPECT((A)==(B))
