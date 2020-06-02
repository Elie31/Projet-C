
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void formatAdresse(int a []);
void conversion(int a[], int binaire[]);
<<<<<<< HEAD
//void decoderIp(int binaire[]);
//void calculerReseauHote(int binaire[]);
=======
void decoderIp(int a[],int b[]);
>>>>>>> 5736274f3f46beb17fa0240b93a9b59b9d10f073


void main() {
	int a[4];
	int b[31];
	formatAdresse(a);
	conversion(a,b);
	decoderIp(a,b);
}

void formatAdresse(int a[]){
	unsigned ip1, ip2, ip3, ip4, ip5;

	int erreur = 1;
	int erreur2 = 1;


	printf("entrer votre adresse ip : \n");
	while (erreur==1){
		if( scanf("%u.%u.%u.%u/%u" , &ip1 , &ip2, &ip3, &ip4, &ip5) != 5 ||
	    ip1>255 || ip2>255 || ip3>255 || ip4>255 || ip5>32){
			printf("Saisie erronée, écriver sous la forme : 255.255.255.255/32\n");
		}else{
			erreur=0;
		}
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


void conversion(int a[], int binaire[]){

	int j=0;

	for(int i=0; i<4; i++)
	{
		
		while(a[i]!=0){
			binaire[j]=a[i]%2;
			a[i]=a[i]/2;
			j++;
		}
		if (j<8){
			while (j<8){
				binaire[j]=0;
				j++;
			}
		}else{
			if (j<16 & j>8){
		     	   	while (j<16){
					binaire[j]=0;
					j++;
				}
			}else{
				if (j<24 & j>16){
		        		while (j<24){
						binaire[j]=0;
						j++;
					}
				}else{
					if (j<32 & j>24){
		        			while (j<32){
							binaire[j]=0;
							j++;
						}
							    
					}
				}
			}
		}
	}
<<<<<<< HEAD
	if (j<8)
		while (j<8){
		binaire[j]=0;
		j++;}
	else
		if (j<16 & j>=8)
                	while (j<16){
                	binaire[j]=0;
                	j++;}
		else
			if (j<24 & j>=16)
                		while (j<24){
                		binaire[j]=0;
                		j++;}
			else
				if (j<32 & j>=24)
                			while (j<32){
                			binaire[j]=0;
                			j++;}
}

int binaire2[31];
for (int i=0; i<32; i++){
        binaire2[i]=binaire[i];
}
int k = 0;
int l = 0;
int m = 7;
for (int i=0; i<4; i++){
        while (k<8){
                binaire2[l]=binaire[m-k];
                k++;
                l++;
        }
        m = m+8;
        k = 0;
}

for(int k=0; k<32; k++){
printf("%d,", binaire2[k]);
}
}

/*void decoderIp(int b[]){
=======

	for(int k=0; k<32; k++){
		printf("%d,", binaire[k]);
	}
		
}

>>>>>>> 5736274f3f46beb17fa0240b93a9b59b9d10f073

void decoderIp(int a[],int b[]){
	for(int i=0; i<3; i++){
		if(b[0]==0){
			printf("votre adresse ip est une classe A");
			break;
		}else{
			if(b[0]==1 && b[1]==0){
				printf("votre adresse ip est une classe B");
				break;
			}else{
				if(b[0]==1 && b[1]==1 && b[2]==0){
					printf("votre adresse ip est une classe C");
					break;
				}else{
					if(b[0]==1 && b[1]==1 && b[2]==1 && b[3]==0){
						printf("votre adresse ip est une classe D");
						break;
					}else{
						if(b[0]==1 && b[1]==1 && b[2]==1 && b[3]==1){
							printf("votre adresse ip est une classe E");
							break;
						}
					}	
				}				
			}
		}
		

	}
		

}

void calculerReseauHote(int a[], int binaire[]){
int reseau[31];
for (int i=0; i<32; i++){
	reseau[i]=binaire[i];
}
if (a[4] != 0)
	for (int k=0; k<32; i++){
	if k>=a[4]
		reseau[k]=0;
	}

}*/




<<<<<<< HEAD
=======

>>>>>>> 5736274f3f46beb17fa0240b93a9b59b9d10f073
