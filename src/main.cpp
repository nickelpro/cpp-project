#include <fmt/format.h>
#include <ztd/text.hpp>

namespace txt = ztd::text;
using namespace std::literals;

int main() {
  auto text {
      u8"The closing lines of the Strugatky Brothers' novel \"Roadside Picnic\""
      " are: \"Счастье для всех, даром, и пусть никто не уйдет обиженн!\"\n"
      "Or translated: \"Happiness for everybody, free, and no one will go away "
      "unsatisfied!\"\n"sv};

  // Note: We want to do:
  // fmt::print(txt::transcode(text, txt::literal))
  // but can't due to lack of support for constexpr std::string in libstdc++
  // prior to GCC 12
  fmt::print("{}", txt::transcode(text, txt::literal));
}
