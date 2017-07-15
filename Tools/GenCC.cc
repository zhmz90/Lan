// copyright 2017 Lanting Guo
/** GenCC is to be used to generate a cc file which will be consistent
    with google-cpp-style guide.
 */

#include <ctime>
#include <iostream>
#include <string>
#include <fstream>


using string = std::string;

string getYear() {
  time_t t = time(0);
  struct tm now;
  localtime_r(&t, &now);
  return std::to_string(now.tm_year + 1900);
}

string getCopyright() {
  return "/* Copyright " + getYear() + " Lanting Guo" + " */\n"
      + "/**\n\n\n*/\n";
}

string getHeaders() {
  return R"(#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using string = std::string;

)";
}

string getMain() {
  return R"(int main(int argc, char *argv[]) {
Solution solu;
return 0;
})";
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Please input a file name" << "\n";
    exit(0);
  }
  if (argc > 2) {
    std::cout << "Do you want to generate multiple files?\n";
    std::cout << "Sorry, only one file one time.";
    exit(0);
  }
  std::ofstream cc;
  cc.open(argv[1]);
  cc << getCopyright();
  cc << "\n";
  cc << getHeaders();
  cc << "\n\n\n";
  cc << getMain();
  cc << '\n';
  cc.close();
  return 0;
}
