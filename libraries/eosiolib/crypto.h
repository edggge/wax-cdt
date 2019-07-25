/**
 *  @file
 *  @copyright defined in eos/LICENSE
 */
#pragma once
#include "types.h"

#warning "<eosiolib/crypto.h> is deprecated use <eosio/crypto.h>. If you are using C++ the .h header files will be removed from inclusion entirely in v1.7.0"

/**
 *  @addtogroup crypto Crypto
 *  @brief Defines %C API for calculating and checking hash
 *  @{
 */

extern "C" {

/**
 *  Tests if the sha256 hash generated from data matches the provided checksum.
 *
 *  @param data - Data you want to hash
 *  @param length - Data length
 *  @param hash - `capi_checksum256*` hash to compare to
 *
 *  @pre **assert256 hash** of `data` equals provided `hash` parameter.
 *  @post Executes next statement. If was not `true`, hard return.
 *
 *  @note This method is optimized to a NO-OP when in fast evaluation mode.
 *
 *  Example:
 *
 *  @code
 *  checksum hash;
 *  char data;
 *  uint32_t length;
 *  assert_sha256( data, length, hash )
 *  //If the sha256 hash generated from data does not equal provided hash, anything below will never fire.
 *  eosio::print("sha256 hash generated from data equals provided hash");
 *  @endcode
 */
__attribute__((eosio_wasm_import))
void assert_sha256( const char* data, uint32_t length, const capi_checksum256* hash );

/**
 *  Tests if the sha1 hash generated from data matches the provided checksum.
 *
 *  @note This method is optimized to a NO-OP when in fast evaluation mode.
 *  @param data - Data you want to hash
 *  @param length - Data length
 *  @param hash - `capi_checksum160*` hash to compare to
 *
 *  @pre **sha1 hash** of `data` equals provided `hash` parameter.
 *  @post Executes next statement. If was not `true`, hard return.
 *
 *  Example:
 *
 *  @code
 *  checksum hash;
 *  char data;
 *  uint32_t length;
 *  assert_sha1( data, length, hash )
 *  //If the sha1 hash generated from data does not equal provided hash, anything below will never fire.
 *  eosio::print("sha1 hash generated from data equals provided hash");
 *  @endcode
 */
__attribute__((eosio_wasm_import))
void assert_sha1( const char* data, uint32_t length, const capi_checksum160* hash );

/**
 *  Tests if the sha512 hash generated from data matches the provided checksum.
 *
 *  @note This method is optimized to a NO-OP when in fast evaluation mode.
 *  @param data - Data you want to hash
 *  @param length - Data length
 *  @param hash - `capi_checksum512*` hash to compare to
 *
 *  @pre **assert512 hash** of `data` equals provided `hash` parameter.
 *  @post Executes next statement. If was not `true`, hard return.
 *
 *  Example:
 *
 *  @code
 *  checksum hash;
 *  char data;
 *  uint32_t length;
 *  assert_sha512( data, length, hash )
 *  //If the sha512 hash generated from data does not equal provided hash, anything below will never fire.
 *  eosio::print("sha512 hash generated from data equals provided hash");
 *  @endcode
 */
__attribute__((eosio_wasm_import))
void assert_sha512( const char* data, uint32_t length, const capi_checksum512* hash );

/**
 *  Tests if the ripemod160 hash generated from data matches the provided checksum.
 *
 *  @param data - Data you want to hash
 *  @param length - Data length
 *  @param hash - `capi_checksum160*` hash to compare to
 *
 *  @pre **assert160 hash** of `data` equals provided `hash` parameter.
 *  @post Executes next statement. If was not `true`, hard return.
 *
 *  Example:
 *
 *  @code
 *  checksum hash;
 *  char data;
 *  uint32_t length;
 *  assert_ripemod160( data, length, hash )
 *  //If the ripemod160 hash generated from data does not equal provided hash, anything below will never fire.
 *  eosio::print("ripemod160 hash generated from data equals provided hash");
 *  @endcode
 */
__attribute__((eosio_wasm_import))
void assert_ripemd160( const char* data, uint32_t length, const capi_checksum160* hash );

/**
 *  Hashes `data` using `sha256` and stores result in memory pointed to by hash.
 *
 *  @param data - Data you want to hash
 *  @param length - Data length
 *  @param hash - Hash pointer
 *
 *  Example:
 *
 *  @code
 *  checksum calc_hash;
 *  sha256( data, length, &calc_hash );
 *  eos_assert( calc_hash == hash, "invalid hash" );
 *  @endcode
 */
__attribute__((eosio_wasm_import))
void sha256( const char* data, uint32_t length, capi_checksum256* hash );

/**
 *  Hashes `data` using `sha1` and stores result in memory pointed to by hash.
 *
 *  @param data - Data you want to hash
 *  @param length - Data length
 *  @param hash - Hash pointer
 *
 *  Example:
 *
 *  @code
 *  checksum calc_hash;
 *  sha1( data, length, &calc_hash );
 *  eos_assert( calc_hash == hash, "invalid hash" );
 *  @endcode
 */
__attribute__((eosio_wasm_import))
void sha1( const char* data, uint32_t length, capi_checksum160* hash );

/**
 *  Hashes `data` using `sha512` and stores result in memory pointed to by hash.
 *
 *  @param data - Data you want to hash
 *  @param length - Data length
 *  @param hash - Hash pointer
 *
 *  Example:
 *
 *  @code
 *  checksum calc_hash;
 *  sha512( data, length, &calc_hash );
 *  eos_assert( calc_hash == hash, "invalid hash" );
 *  @endcode
 */
__attribute__((eosio_wasm_import))
void sha512( const char* data, uint32_t length, capi_checksum512* hash );

/**
 *  Hashes `data` using `ripemod160` and stores result in memory pointed to by hash.
 *
 *  @param data - Data you want to hash
 *  @param length - Data length
 *  @param hash - Hash pointer
 *
 *  Example:
 *
 *  @code
 *  checksum calc_hash;
 *  ripemod160( data, length, &calc_hash );
 *  eos_assert( calc_hash == hash, "invalid hash" );
 *  @endcode
 */
__attribute__((eosio_wasm_import))
void ripemd160( const char* data, uint32_t length, capi_checksum160* hash );

/**
 *  Calculates the public key used for a given signature and hash used to create a message.
 *
 *  @param digest - Hash used to create a message
 *  @param sig - Signature
 *  @param siglen - Signature length
 *  @param pub - Public key
 *  @param publen - Public key length
*   @return int - number of bytes written to pub
 *
 *  Example:
*
 *  @code
 *  @endcode
 */
__attribute__((eosio_wasm_import))
int recover_key( const capi_checksum256* digest, const char* sig, size_t siglen, char* pub, size_t publen );

/**
 *  Tests a given public key with the generated key from digest and the signature.
 *
 *  @param digest - What the key will be generated from
 *  @param sig - Signature
 *  @param siglen - Signature length
 *  @param pub - Public key
 *  @param publen - Public key length
 *
 *  @pre **assert recovery key** of `pub` equals the key generated from the `digest` parameter
 *  @post Executes next statement. If was not `true`, hard return.
 *
 *  Example:
 *
 *  @code
 *  checksum digest;
 *  char sig;
 *  size_t siglen;
 *  char pub;
 *  size_t publen;
 *  assert_recover_key( digest, sig, siglen, pub, publen )
 *  // If the given public key does not match with the generated key from digest and the signature, anything below will never fire.
 *  eosio::print("pub key matches the pub key generated from digest");
 *  @endcode
 */
__attribute__((eosio_wasm_import))
void assert_recover_key( const capi_checksum256* digest, const char* sig, size_t siglen, const char* pub, size_t publen );

/// @}


/**
 *  @defgroup wax WAX Chain C extension API
 *  @brief Defines WAX %C extension API
 *  @ingroup crypto
 *  @{
 */


/**
 * Verifies an RSA signed message
 *
 * @warning WAX specific
 *
 * @param message - message buffer to verify
 * @param message_len - message buffer length
 * @param signature - signature as hex string
 * @param signature_len - signature length
 * @param exponent - public key exponent as hex string
 * @param exponent_len - exponent length
 * @param modulus - modulus as hex string (a leading zero is not allowed)
 * @param modulus_len - modulus length
 *
 * @return 0 if validation has failed, non zero if everything is Ok
 *
 * @sa https://www.emc.com/collateral/white-papers/h11300-pkcs-1v2-2-rsa-cryptography-standard-wp.pdf
 */
__attribute__((eosio_wasm_import))
int verify_rsa_sha256_sig(const void* message,   uint32_t message_len,
                          const char* signature, uint32_t signature_len,
                          const char* exponent,  uint32_t exponent_len,
                          const char* modulus,   uint32_t modulus_len);

/// }@wax


} // extern "C"
