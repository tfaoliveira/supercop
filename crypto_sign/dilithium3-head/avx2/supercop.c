#include <stdint.h>
#include <stddef.h>

#include "api.h"
#include "crypto_sign.h"

//

extern int pqcrystals_dilithium3_avx2_keypair(
  unsigned char *pk,
  unsigned char *sk
);

extern int pqcrystals_dilithium3_avx2(
  unsigned char *sm,
  unsigned long long *smlen,
  const unsigned char *m,
  unsigned long long mlen,
  const unsigned char *sk
);

extern int pqcrystals_dilithium3_avx2_open(
  unsigned char *m,
  unsigned long long *mlen,
  const unsigned char *sm,
  unsigned long long smlen,
  const unsigned char *pk
);

//

int crypto_sign_keypair(
  unsigned char *pk,
  unsigned char *sk
)
{
  return pqcrystals_dilithium3_avx2_keypair(pk, sk);
}


int crypto_sign(
  unsigned char *sm,
  unsigned long long *smlen,
  const unsigned char *m,
  unsigned long long mlen,
  const unsigned char *sk
)
{
  return pqcrystals_dilithium3_avx2(sm, smlen, m, mlen, sk);
}


int crypto_sign_open(
  unsigned char *m,
  unsigned long long *mlen,
  const unsigned char *sm,
  unsigned long long smlen,
  const unsigned char *pk
)
{
  return pqcrystals_dilithium3_avx2_open(m, mlen, sm, smlen, pk);
}


