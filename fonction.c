
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void formatAdresse(int a []);
void conversion(int a[], int binaire[]);
void decoderIp(int a[], int b[]);
void calculerReseauHote(int a[], int binaire[]);



void main(){

	int a[4];
	int b[31];
	formatAdresse(a);
	conversion(a,b);
	calculerReseauHote(a,b);
	decoderIp(a,b);

}

void formatAdresse(int a[]){

FILE *f;
f=fopen("resultat.txt","a");

unsigned ip1, ip2, ip3, ip4, ip5;
int erreur = 1;
int erreur2 = 1;


	printf("Entrer votre adresse ip : \n");
	while (erreur==1){
		if( scanf("%u.%u.%u.%u/%u" , &ip1 , &ip2, &ip3, &ip4, &ip5) != 5 || ip1>255 || ip2>255 || ip3>255 || ip4>255 || ip5>32){
			printf("Saisie erronée, écriver sous la forme : 255.255.255.255/32\n");
		}else{
			erreur=0;
		}
	}

	a[0] = ip1;
	a[1] = ip2;
	a[2] = ip3;
	a[3] = ip4;
	a[4] = ip5;
	printf("Votre adresse ip est : %d.%d.%d.%d/%d\n",a[0],a[1],a[2],a[3],a[4]);
	fprintf(f,"Votre adresse ip est : %d.%d.%d.%d/%d\n",a[0],a[1],a[2],a[3],a[4]);
	fclose(f);
}


void conversion(int a[], int binaire[]){

FILE *f;
f=fopen("resultat.txt","a");

int copieAdresse[4];
int binaire2[31];


	int j=0;
	for (int i=0; i<4; i++){
		copieAdresse[i]=a[i];
	}

	for(int i=0; i<4; i++)
	{
		
		while(copieAdresse[i]!=0){
			binaire2[j]=copieAdresse[i]%2;
			copieAdresse[i]=copieAdresse[i]/2;
			j++;
		}
		if (j<8){
			while (j<8){
				binaire2[j]=0;
				j++;
			}
		}else{
			if (j<16 & j>8){
		     	   	while (j<16){
					binaire2[j]=0;
					j++;
				}
			}else{
				if (j<24 & j>16){
		        		while (j<24){
						binaire2[j]=0;
						j++;
					}
				}else{
					if (j<32 & j>24){
		        			while (j<32){
							binaire2[j]=0;
							j++;
						}
					}
				}
			}
		}
	}

	if (j<8)
		while (j<8){
		binaire2[j]=0;
		j++;}
	else
		if (j<16 & j>=8)
                	while (j<16){
                	binaire2[j]=0;
                	j++;}
		else
			if (j<24 & j>=16)
                		while (j<24){
                		binaire2[j]=0;
                		j++;}
			else
				if (j<32 & j>=24)
                			while (j<32){
                			binaire2[j]=0;
                			j++;}



for (int i=0; i<32; i++){
        binaire[i]=binaire2[i];
}
int k = 0;
int l = 0;
int m = 7;
for (int i=0; i<4; i++){
        while (k<8){
                binaire[l]=binaire2[m-k];
                k++;
                l++;
        }
        m = m+8;
        k = 0;
}

printf("Conversion binaire : ");
fprintf(f,"Conversion binaire : ");
for(int k=0; k<32; k++){
	printf("%d", binaire[k]);
		if(k==7 || k==15 || k==23){
			printf(" ");
			fprintf(f," ");
		}
}
	printf("\n");
	fprintf(f,"\n");
	fclose(f);
}


void calculerReseauHote(int a[], int binaire[]){

FILE *f;
f=fopen("resultat.txt","a");

int k=1;
int reseauBinaire[31];
int adresseReseau[3];
int bit = 0;
int var = 31;
int x = 1;

while (k<32){
	while (k<a[4]){
		if (binaire[k]==1)
			reseauBinaire[k]=1;
		else
			reseauBinaire[k]=0;
		k++;
	}
	reseauBinaire[k]=0;
	k++;
}
for (int i=0; i<4; i++){
adresseReseau[i]=0;
}
if (a[0]>127 && a[4]>0){
reseauBinaire[0]=1;
}
for (int z=3; z>=0; z--){
	while (bit<8){
		adresseReseau[z] = adresseReseau[z]+reseauBinaire[var]*(x);
		bit = bit + 1;
		var = var-1;
		x *= 2;
	}
	bit = 0;
	x = 1;
}



printf("L'adresse reseau est : %d.%d.%d.%d\n",adresseReseau[0],adresseReseau[1],adresseReseau[2],adresseReseau[3]);
fprintf(f,"L'adresse reseau est : %d.%d.%d.%d\n",adresseReseau[0],adresseReseau[1],adresseReseau[2],adresseReseau[3]);


if (a[4]<=8){
	printf("Première IP: %d.0.0.1\n",adresseReseau[0]);
	printf("Dernière IP: %d.255.255.254\n",adresseReseau[0]);
	fprintf(f,"Première IP: %d.0.0.1\n",adresseReseau[0]);
        fprintf(f,"Dernière IP: %d.255.255.254\n",adresseReseau[0]);
}else{
	if (a[4]<=16){
        	printf("Première IP: %d.%d.0.1\n",adresseReseau[0],adresseReseau[1]);
        	printf("Dernière IP: %d.%d.255.254\n",adresseReseau[0],adresseReseau[1]);
		fprintf(f,"Première IP: %d.%d.0.1\n",adresseReseau[0],adresseReseau[1]);
		fprintf(f,"Dernière IP: %d.%d.255.254\n",adresseReseau[0],adresseReseau[1]);

	}else{
		if (a[4]<=24){
        		printf("Première IP: %d.%d.%d.1\n",adresseReseau[0],adresseReseau[1],adresseReseau[2]);
        		printf("Dernière IP: %d.%d.%d.254\n",adresseReseau[0],adresseReseau[1],adresseReseau[2]);
			fprintf(f,"Première IP: %d.%d.%d.1\n",adresseReseau[0],adresseReseau[1],adresseReseau[2]);
			fprintf(f,"Dernière IP: %d.%d.%d.254\n",adresseReseau[0],adresseReseau[1],adresseReseau[2]);
		}
	}
}
fclose(f);
}


void decoderIp(int a[], int b[]){

FILE *f;
f=fopen("resultat.txt","a");

	for(int i=0; i<3; i++){
		if(b[0]==0){
			printf("Votre adresse ip est une classe A,");
			fprintf(f,"Votre adresse ip est une classe A,");
			break;
		}else{
			if(b[0]==1 && b[1]==0){
				printf("Votre adresse ip est une classe B,");
				fprintf(f,"Votre adresse ip est une classe B,");
				break;
			}else{
				if(b[0]==1 && b[1]==1 && b[2]==0){
					printf("Votre adresse ip est une classe C,");
					fprintf(f,"Votre adresse ip est une classe C,");
					break;
				}else{
					if(b[0]==1 && b[1]==1 && b[2]==1 && b[3]==0){
						printf("Votre adresse ip est une classe D et multicast,");
						fprintf(f,"Votre adresse ip est une classe D et multicast,");
						break;
					}else{
						if(b[0]==1 && b[1]==1 && b[2]==1 && b[3]==1){
							printf("Votre adresse ip est une classe E,");
							fprintf(f,"Votre adresse ip est une classe E,");
							break;
						}
					}	
				}				
			}
		}
		

	}
	
	
	if(a[0]==10 || a[0]==172 || a[0]==192){
		printf("Privée");
		fprintf(f,"Privée");
	}else{
		printf("Public");
		fprintf(f,"Public");
	}

		
	if(a[0]==127){
		printf("et LocalHost\n");
		fprintf(f,"et LocalHost\n");	
	}else{
	
	}	

	

}

