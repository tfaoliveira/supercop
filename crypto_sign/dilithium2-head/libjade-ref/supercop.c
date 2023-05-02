#include <stdint.h>
#include <stddef.h>

#include "api.h"
#include "crypto_sign.h"

//

uint8_t* __jasmin_syscall_randombytes__(uint8_t* x, uint64_t xlen)
{
  randombytes(x, xlen);
  return x;
}

//

int crypto_sign_keypair(
  unsigned char *pk,
  unsigned char *sk
)
{
  return jade_sign_dilithium_dilithium2_amd64_ref_keypair(pk, sk);
}


int crypto_sign(
  unsigned char *sm,
  unsigned long long *smlen,
  const unsigned char *m,
  unsigned long long mlen,
  const unsigned char *sk
)
{
  return jade_sign_dilithium_dilithium2_amd64_ref(sm, smlen, m, mlen, sk);
}


int crypto_sign_open(
  unsigned char *m,
  unsigned long long *mlen,
  const unsigned char *sm,
  unsigned long long smlen,
  const unsigned char *pk
)
{
  return jade_sign_dilithium_dilithium2_amd64_ref_open(m, mlen, sm, smlen, pk);
}


