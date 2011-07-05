#ifndef LIBBITCOIN_SHA256_H
#define LIBBITCOIN_SHA256_H

#include <openssl/sha.h>
#include <string>
#include <cstdint>

#include <bitcoin/types.hpp>

namespace libbitcoin {

class sha256
{
public:
    static const size_t length = SHA256_DIGEST_LENGTH;

    sha256();
    
    void push_byte(uint8_t v);
    void push_2_bytes(uint16_t v);
    void push_4_bytes(uint32_t v);
    void push_8_bytes(uint64_t v);
    void push_var_uint(uint64_t var_uint);
    void push_str(const std::string& val);
    void push_data(const data_chunk& data);

    SHA256_CTX& ctx() { return ctx_; }

    hash_digest finalize();
    // Deprecated
    void finalize(byte hash[length]);
private:
    SHA256_CTX ctx_;
    byte digest_[length];
};

uint32_t generate_sha256_checksum(const data_chunk& chunk);

} // libbitcoin

#endif

