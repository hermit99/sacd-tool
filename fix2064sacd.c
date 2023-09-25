/**
 * https://github.com/sacd-ripper/sacd-ripper/issues/80
 *
 * Modified from the solution provided by Yao Fei feiyao@me.com
 *    Some SACD iso use 2064bytes/sector
 *    [--12--][+++2048+++][--4--] is the scheme to keep at least with the SACD I tested.
 */

#include <stdio.h>
#include <unistd.h>

typedef struct
{
  int head[3];
  int data[2048 / 4];
  int tail;
} DVD_SEC;

int main(int argc, char *argv[]) {
  DVD_SEC dvd;
  char *srcName, *dstName;
  FILE *src, *dst;
  int i, n = 0;

  if (argc != 5) {
    printf("Usage: %s -i Source_ISO_file -o Target_ISO_file\n", argv[0]);
    return -1;
  }

  for (i = 1; i < 5; i++) {
    if (strcmp(argv[i], "-i") == 0) {
      srcName = argv[++i];
    } else if (strcmp(argv[i], "-o") == 0) {
      dstName = argv[++i];
    }
  }

  if (srcName == NULL || dstName == NULL) {
    printf("Invalid arguments.\n");
    printf("Usage: %s -i Source_ISO_file -o Target_ISO_file\n", argv[0]);
    return -1;
  }

  if ((src = fopen(srcName, "rb")) == NULL) {
    printf("Can't open %s\n", srcName);
    return -1;
  }

  if ((dst = fopen(dstName, "wb")) == NULL) {
    printf("Can't open %s\n", dstName);
    return -1;
  }

  printf("Start conversion\n");
  i = 0;
  while ((n = fread(&dvd, 1, 2064, src)) > 0) {
    if (i++ % 1000 == 0) printf(".");
    fwrite(dvd.data, 2048, 1, dst);
  }

  fclose(src);
  fclose(dst);
  printf("\nDone.");
}