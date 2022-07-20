#include<stdio.h>
#include <netinet/in.h>
#include<stdint.h>
#include<stdlib.h>


uint32_t buf[4];

uint32_t RF(char * file) {
   uint32_t size = 4;
   FILE *p = fopen(file, "rb");
   for(uint32_t i=0; i<size; i++) { fread(&buf[i], sizeof(uint32_t), 1, p); }
   uint32_t result = (uint32_t)(buf[0] << 24 | buf[1] << 16 | buf[2] << 8 | buf[3]);
   return  buf[0];
}


int main(int argc, char * argv[]) {
    
   uint32_t n1 = RF(argv[1]);
   uint32_t n2 = RF(argv[2]);

   n1 = ntohl(n1);
   n2 = ntohl(n2);
   printf("0x%x + 0x%x = ", n1, n2);
   printf("0x%x\n", n1 + n2);

}
