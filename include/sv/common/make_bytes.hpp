#ifndef __SV_COMMON_MAKE_BYTES_HPP__
#define __SV_COMMON_MAKE_BYTES_HPP__

namespace sv
{

template<typename T, typename...Elems>
T make_bytes(Elems&&...elements)
{
  T result = {0};

  result = (result << (8 * sizeof(Elems))) | std::forward<Elems>(elements);
}

} // namespace sv

#endif // __SV_COMMON_MAKE_BYTES_HPP__