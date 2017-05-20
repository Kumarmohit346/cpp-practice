#include <iostream>

using namespace std;

class Test {
   public:
      int getVar( void );
      Test( int var );             // simple constructor
      Test( const Test &obj);  // copy constructor
      ~Test();                     // destructor

   private:
      int *ptr;
};

// Member functions definitions including constructor
Test::Test(int var) {
   cout << "Normal constructor allocating ptr" << endl;
	
   // allocate memory for the pointer;
   ptr = new int;
   *ptr = var;
}

Test::Test(const Test &obj) {
   cout << "Copy constructor allocating ptr." << endl;
   ptr = new int;
   *ptr = *obj.ptr; // copy the value
}

Test::~Test(void) {
   cout << "Freeing memory!" << endl;
   delete ptr;
}

int Test::getVar( void ) {
   return *ptr;
}

void display(Test obj) {
   cout << "Var of Test : " << obj.getVar() <<endl;
}

// Main function for the program
int main( ) {
   Test a(10);

   display(a);

   return 0;
}
