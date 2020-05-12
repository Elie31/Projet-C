
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void formatAdresse();
void main() {
formatAdresse();
}
void formatAdresse(){
unsigned ip1, ip2, ip3, ip4, ip5;

int erreur = 1;
int erreur2 = 1;
int a[5];

printf("entrer votre adresse ip : \n");
while (erreur==1){
if( scanf("%u.%u.%u.%u/%u" , &ip1 , &ip2, &ip3, &ip4, &ip5) != 5 ||
    ip1>255 || ip2>255 || ip3>255 || ip4>255 || ip5>32)
	printf("Saisie erronée, écriver sous la forme : 255.255.255.255/32\n");
else
	erreur=0;
}
//printf("entrer votre masque réseau : (0 si il n'y a pas de masque) \n");
//while (erreur2==1){
//if( scanf("/%u" , &ip5) != 1 ||
//    ip5>32 )
//        printf("Saisie erronée, écriver sous la forme : 255.255.255.255\n");
//else
//        erreur2=0;
//}
//while (erreur2==1){
//if ( scanf("/%u",&ip5) != 1 || ip5>32)
//	printf("Saisie erronée, écriver sous la forme : '/24','/19'...\n");
//else
//	erreur2=0;
//}
a[1] = ip1;
a[2] = ip2;
a[3] = ip3;
a[4] = ip4;
a[5] = ip5;
printf("votre adresse ip est : %d.%d.%d.%d/%d\n",a[1],a[2],a[3],a[4],a[5]);
}
