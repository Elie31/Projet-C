
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void formatAdresse(int a []);
void conversion(int a[]);

void main() {
int a[4];
formatAdresse(a);
conversion(a);
}
void formatAdresse(int a[]){
unsigned ip1, ip2, ip3, ip4, ip5;

int erreur = 1;
int erreur2 = 1;


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
a[0] = ip1;
a[1] = ip2;
a[2] = ip3;
a[3] = ip4;
a[4] = ip5;
printf("votre adresse ip est : %d.%d.%d.%d/%d\n",a[0],a[1],a[2],a[3],a[4]);
}

void conversion(int a[]){

int j;
int binaire[31];

for(int i=0; i<4; i++)
{
	j=0;
	while(a[i]!=0 || j<8)
	{
		binaire[j]=a[i]%2;
		a[i]=a[i]/2;
		j++;
	}
}
printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", binaire[0],binaire[1],binaire[2],binaire[3],binaire[4],binaire[5],binaire[6],binaire[7],binaire[8],binaire[9],binaire[10],binaire[11],binaire[12],binaire[13],binaire[14],binaire[15],binaire[16],binaire[17],binaire[18],binaire[19],binaire[20],binaire[21],binaire[22],binaire[23],binaire[24],binaire[25],binaire[26],binaire[27],binaire[28],binaire[29],binaire[30],binaire[31]);
/*for(int k=0; k<32; k++){
printf("%d,", binaire[k]);
}
/*printf("\n");
for(int i=31;i>=0;i--)
{
	printf("%d",binaire[i]);
}*/
}
