#include <stdio.h>
#include <stdlib.h>


char Codifica(char letra, int n);
int EhLetra(char c);
int EhMaiuscula(char c);
char Decodifica(char letra, int n);


int main(){
	int n, modo;
	char letra, NL;
	scanf("%d %d", &modo, &n);
	if(modo != 1 && modo != 2){
	        printf("Operacao invalida.");
		return 0;
	}
	
	else{
	while(letra != '.'){
			scanf("%c", &letra);
			if(modo == 1){
				NL = Codifica(letra, n);
				letra = NL;
			}else if(modo == 2){
				NL = Decodifica(letra, n);
				letra = NL;
			}
			printf("%c", letra);
			
		}
	}
	return 0;
}




char Codifica(char letra, int n){
	int EL, MAI;
	char c;
	c = letra;
	EL = EhLetra(c);
	if(EL == 1){
		MAI = EhMaiuscula(c);
	}else{
		return c;
	}
	
	if(MAI == 1){
		n = n % 26;
		if((c + (n*2)) > 90){
			c = 64 + ((c+(n*2))-90);
		}else{
			c = c + (n*2);
		}
		return c;
	}else if(MAI == 0){
		n = n % 26;
		if((c + n) > 122){
			c = 96 + ((c+n)-122);
		}else{
			c = c + n;
		}
		return c;
	}
}

int EhLetra(char c){
	if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
		return 1;
	}else{
		return 0;
	}
}

int EhMaiuscula(char c){
	if(c >= 65 && c <= 90){
		return 1;
	}else{
		return 0;
	}
}


char Decodifica(char letra, int n){
	int EL, MAI;
	char c;
	c = letra;
	EL = EhLetra(c);
	if(EL == 1){
		MAI = EhMaiuscula(c);
	}else{
		return c;
	}
	
	if(MAI == 1){
		n = n % 26;
		if((c - (n*2)) < 65){
			c = 91 - (65 - (c - (n*2)));
		}else{
			c = c - (n*2);
		}
		return c;
	}else if(MAI == 0){
		n = n % 26;
		if((c - n) < 97){
			c = 123 - (97 - (c - n));
		}else{
			c = c - n;
		}
		return c;
	}
}
