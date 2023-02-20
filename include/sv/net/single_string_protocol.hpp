#ifndef __SV_NET_SINGLE_STRING_PROTOCOL_HPP__
#define __SV_NET_SINGLE_STRING_PROTOCOL_HPP__

#include "sv/net/config.hpp"
#include "sv/common.hpp"

SV_NET_NS_BEGIN

class single_string_protocol
{
public:

#pragma pack(push, 1)
  struct header_t
  {
    std::uint32_t magic;
    std::uint16_t version;
    std::uint32_t flags;
    std::uint64_t size;
  };
#pragma pack(pop)

  struct body_t
  {
    std::string data;
  };

  struct packet_t
  {
    using self = packet_t;
    using ptr = std::shared_ptr<self>;

    header_t header;
    body_t body;
  };

public:
  // read part
  static std::size_t get_header_size()
  {
    return sizeof(header_t);
  }
  static std::size_t get_body_size(header_t const& header)
  {
    return header.size;
  }
  static void process_header(std::istream& is, header_t& header)
  {
    is.read((char*)&header, sizeof(header_t));
  }
  static void process_body(std::istream& is, header_t const& header, body_t& body)
  {
    body.resize(header.size);
    is.read((char*)&body[0], header.size);
  }

  // write part
  static packet_t::ptr make_packet(std::string const& data)
  {
    packet_t::ptr packet = std::make_shared<packet>();
    prepare_header(packet.header, data);
  }
private:
  static void prepare_header(header_t& header, std::string const& data)
  {
    header.magic = make_bytes<std::uint32_t>('S','S','P','1');
    header.version = make_bytes<std::uint16_t>(0x01,0x00);
    header.flags = make_bytes<std::uint32_t>();
    header.size = data.size();
  }
};

SV_NET_NS_END

#endif // __SV_NET_SINGLE_STRING_PROTOCOL_HPP__