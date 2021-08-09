#include <numeric>

std::string pig_it(std::string str)
{
  std::istringstream iss(str);
  std::vector<std::string> splits(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());
  std::string res = std::accumulate(splits.begin(), splits.end(), std::string(), [](std::string acc, std::string in){
    return std::move(acc) + in.substr(1,in.length()) + in[0] + (isalpha(in[0]) ? "ay " : " ");
  });
  
  return res.substr(0, res.length()-1);
}
