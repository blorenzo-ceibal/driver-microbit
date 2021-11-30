#include <stdio.h>
#include <stdlib.h>

main() {
  int i;
  const int ci = 123;

  /* declare a pointer to a const.. */
  const int *cpi;

  /* ordinary pointer to a non-const */
  int *ncpi;

  cpi = &ci;
  ncpi = &i;

  printf("ci has value %i at address %p, cpi has value %i "
    "and points at address %p.\n", ci, &ci, *cpi, cpi);
 
  /* this needs a cast
   * because it is usually a big mistake,
   * see what it permits below.
   */
  ncpi = (int *)cpi;

  /*now to get undefined behaviour...
   * modify a const through a pointer
   */
  *ncpi = 42;

  printf("ci has value %i at address %p, cpi has value %i "
    "and points at address %p.\n", ci, &ci, *cpi, cpi);
 
  exit(EXIT_SUCCESS);
}
