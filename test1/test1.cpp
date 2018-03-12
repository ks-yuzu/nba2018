#include <iostream>
#include <list>
#include <regex>

// S が[a-zA-Z0-9]+ であることを利用して,
// 数字部分で分割した部分文字列が大文字を含むかどうかで判定

std::list<std::string> split(const std::string& str, const std::regex& separator) {
  auto ite = std::sregex_token_iterator(std::begin(str), std::end(str), separator, -1);
  auto end = std::sregex_token_iterator();

  std::list<std::string> results = {};
  while (ite != end) { results.emplace_back(*ite++); }

  return results;
}


bool containsUppercase(const std::string& str) {
  for(const auto& c : str) {
    if ( std::isupper(c) ) { return true; }
  }
  return false;
}


int getMaxPassStringLength(const std::string& input, const std::regex& separator) {
  auto results = split(input, separator);
  int maxLength = -1;
  for ( const auto& res : results ) {
    if ( maxLength < static_cast<int>(res.length()) && containsUppercase(res) ) {
      // std::cerr << res << std::endl;
      maxLength = res.length();
    }
  }

  return maxLength;
}


int main(int argc, char *argv[])
{
  if (argc < 2) { exit(1); }
  std::string input = argv[1];
  std::regex separator("[0-9]+"); // 分割用のセパレータ

  std::cout << getMaxPassStringLength(input, separator) << std::endl;

  return 0;
}
