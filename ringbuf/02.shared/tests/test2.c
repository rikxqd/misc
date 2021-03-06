#include <stdio.h>
#include <unistd.h>
#include "shr_ring.h"

char *ring = "test.ring";

int main() {
 struct shr *s=NULL;
 int rc = -1;

 unlink(ring);
 if (shr_init(ring, 1024, 0) < 0) goto done;

 s = shr_open(ring);
 if (s == NULL) goto done;

 rc = 0;

done:
 if (s) shr_close(s);
 return rc;
}
