#include <iostream>
#include <typeinfo>
#include <cxxabi.h>  // For __cxa_demangle
using std::cout;
using std::cin;
//please note that passing tie() a null ptr ties it to nothing/removes ties.
int main() {
  //here we are tying an input stream to an output stream. You may either tie an istream or an ostream to another ostream
  cin.tie(&cout);
  //by default, cin is tied to cout. Note that the tie exists in cin, not cout. If you checked couts ties it would have none.
  std::ostream* tiedStream = cin.tie();
  //the type here is an ostream, since we expect cin to be tied to an ostream (cout) it is also a pointer, since the tie function.
  //returns a pointer by defualt.
  if (tiedStream) {
    //the above if checks if the pointer is a nullptr, if it is it returns false. If it points to a valid object it returns true.
    int status;
    //here we demangle the name, which is mangled by the compiler for lower level use, the two null ptrs just tell
    //the function we are specifying an output buffer or storing the length of the demangled name.
    //status stores the status of demangling the name
    char* demangledName = abi::__cxa_demangle(typeid(*tiedStream).name(), nullptr, nullptr, &status);

    if (status == 0) {
      std::cout << "Currently tied to: " << demangledName << std::endl;
      free(demangledName);  // Free the memory allocated by __cxa_demangle
    } else {
      std::cerr << "Error in demangling type name." << std::endl;
    }
  } else {
    std::cout << "Not tied to any stream." << std::endl;
  }

  return 0;
}