#include "sv/common.hpp"
#include "sv/parser.hpp"

#include <fstream>

struct from_filelist
{
  template<class Path>
  from_filelist(Path& path)
    : path_(path)
    , filelist_()
  {
    filelist_.open(path_, std::ios::in);
    if (!filelist_.good()) throw std::runtime_error("file not found");

    // file_.seekg(0, std::ios::end);
    // auto length = file_.tellg();
    // file_.seekg(0, std::ios::beg);

    // buffer_.resize(length);
    // file_.read(&buffer[0], length);
  }

  bool operator()(std::string& buffer)
  {
    std::string filepath;
    if (!std::getline(filelist_, filepath))
    {
      return false;
    }

    std::fstream file(filepath, std::ios::in | std::ios::binary);
    if (!file.good())
    {
      buffer = filepath;
      return true;
    }

    file.seekg(0, std::ios::end);
    auto length = file.tellg();
    file.seekg(0, std::ios::beg);

    buffer.resize(length);
    file.read(&buffer[0], length);

    return true;
  }

private:
  std::string path_;
  std::fstream filelist_;
};

struct from_console
{
  bool operator()(std::string& buffer)
  {
    return bool(std::getline(std::cin, buffer));
  }
};

int main(int argc, const char **argv)
{
  try
  {
    sv::run_parser<sv::number_parser>(from_console());

    // sv::run_parser<sv::request_parser>(from_filelist("request.list"));
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}