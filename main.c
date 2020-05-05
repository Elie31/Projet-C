#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
unsigned ip1, ip2, ip3, ip4;

int erreur = 1;
int a[5];

printf("entrer votre adresse ip : \n");
while (erreur==1){
if( scanf("%u.%u.%u.%u" , &ip1 , &ip2, &ip3, &ip4) != 4 ||
    ip1>255 || ip2>255 || ip3>255 || ip4>255 )
        printf("Saisie erronée, écriver sous la forme : 255.255.255.255\n");
else
        erreur=0;
}
a[1] = ip1;
a[2] = ip2;
a[3] = ip3;
a[4] = ip4;

printf("votre adresse ip est : %d.%d.%d.%d\n",a[1],a[2],a[3],a[4]);
}
