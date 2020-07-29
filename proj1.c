//xbahda01 - Bahdanovich Viktoryia

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

if(argc>2){
fprintf(stderr,"error: invalid arguments\n");
return 1;
}

char seznam[84][100];
char arr[42][202];
char arr_num[42][202];


for ( int y = 0; y < 84; y++ ) {
	for ( int q = 0; q < 100; q++ ){
     		seznam[y][q] = '*';
	}
}

for ( int k=0; k<84; k++){
		gets(seznam[k]);
}

for ( int a = 0; a < 42; a++ ) {
    for ( int b = 0; b < 202; b++ ){
      arr[a][b] = '$';
   }
}

for ( int z = 0; z < 42; z++ ) {
    for ( int x = 0; x < 202; x++ ){
      	if( x < 100){
	arr[z][x] = seznam[2*z][x];
	}
	if( arr[z][x] == '*'){
         arr[z][x] = '$';
        }
  }
}

for ( int h = 0; h < 42; h++ ) {
    for ( int d = 0; d < 202; d++ ){
	if( arr[h][d] == '$'){
	 arr[h][d-1] = ',';
         arr[h][d] = ' ';
	 break;
       }

    }

}

int counter = 0;
for ( int z = 0; z < 42; z++ ) {
	counter++;
    for ( int x = 0; x < 202; x++ ){
        if( arr[z][x] == '$' ){
		int nex = x;
		for(int col = 0; col < 100; col++ ){
			arr[z][nex] = seznam[z+counter][col];
			nex++;
		}
		break;
	}
      }
}

for ( int h = 0; h < 42; h++ ) {
    for ( int d = 0; d < 202; d++ ){
	if( arr[h][d] == '*'){
	    arr[h][d-1] = '*';
	 break;
       }
    }
}

for ( int h = 0; h < 42; h++ ) {
    for ( int d = 0; d < 202; d++ ){
	if( arr[h][d] == '*'){
	    arr[h][d] = '$';
       }
    }
}


//prepisime arr do lower case

for(int i = 0; i<42; i++){ 
	for ( int d = 0; d < 202; d++ ){
    if(arr[i][d]<91 && arr[i][d]>64)
	arr[i][d]+=32;
  }
}

// seznam uz je prepsan dp arr

/////////// kopirovani arr do arr_num

for ( int a = 0; a < 42; a++ ) {
   for ( int b = 0; b <202; b++ ){
     arr_num[a][b] = arr[a][b];
  }
}

//////////// prepis
    for ( int a = 0; a < 42; a++ ) {
	for ( int b = 0; b <202; b++ ){
	
  //2 key
	if( arr_num[a][b] ==  'a' || arr_num[a][b] ==  'b' || arr_num[a][b] ==  'c' || arr_num[a][b] ==  'A' || arr_num[a][b] ==  'B' || arr_num[a][b] ==  'C'  ){
      arr_num[a][b] = '2';
	}

  //3
	if( arr_num[a][b] ==  'e' || arr_num[a][b] ==  'd' || arr_num[a][b] ==  'f' || arr_num[a][b] ==  'E' || arr_num[a][b] ==  'D' || arr_num[a][b] ==  'F'  ){
      arr_num[a][b] = '3';
	}

  //4
	if( arr_num[a][b] ==  'g' || arr_num[a][b] ==  'h' || arr_num[a][b] ==  'i' || arr_num[a][b] ==  'G' || arr_num[a][b] ==  'H' || arr_num[a][b] ==  'I'  ){
      arr_num[a][b] = '4';
	}

  //5
	if( arr_num[a][b] ==  'j' || arr_num[a][b] ==  'k' || arr_num[a][b] ==  'l' || arr_num[a][b] ==  'J' || arr_num[a][b] ==  'K' || arr_num[a][b] ==  'L'  ){
      arr_num[a][b] = '5';
	}

  //6
	if( arr_num[a][b] ==  'm' || arr_num[a][b] ==  'n' || arr_num[a][b] ==  'o' || arr_num[a][b] ==  'M' || arr_num[a][b] ==  'N' || arr_num[a][b] ==  'O'  ){
      arr_num[a][b] = '6';
	}

  //7
	if( arr_num[a][b] ==  'P' || arr_num[a][b] ==  'Q' || arr_num[a][b] ==  'R' || arr_num[a][b] ==  'S' || arr_num[a][b] ==  'p' || arr_num[a][b] ==  'q' || arr_num[a][b] ==  'r' || arr_num[a][b] ==  's' ){
      arr_num[a][b] = '7';
	}

  //8
	if( arr_num[a][b] ==  't' || arr_num[a][b] ==  'u' || arr_num[a][b] ==  'v' || arr_num[a][b] ==  'T' || arr_num[a][b] ==  'U' || arr_num[a][b] ==  'V' ){
      arr_num[a][b] = '8';
	}

  //9
	if(  arr_num[a][b] ==  'W' || arr_num[a][b] ==  'X' || arr_num[a][b] ==  'Y' || arr_num[a][b] ==  'Z' || arr_num[a][b] ==  'w' || arr_num[a][b] ==  'x' || arr_num[a][b] ==  'y' || arr_num[a][b] ==  'z'  ){
      arr_num[a][b] = '9';
	}

  //0
	if( arr_num[a][b] ==  '+'  ){
      arr_num[a][b] = '0';
	}


 }
}




//////////////////
if ( argc == 1){
for ( int a = 0; a < 42; a++ ) {
for ( int b = 0; b < 202; b++ ) {
	if( arr[a][b] == '$')  //tyto 2 radky jde prepsat jednim s arr[a] a %s
	  break;
	printf("%c", arr[a][b]);
   }
printf("\n");
  }
}

if (argc == 2) {
int fl = 0;
for ( int a = 0; a < 42;  ) {
		if (strstr(arr_num[a], argv[1]) == NULL )
			printf("Не нашелллл\n\n\n");

       	else if (strstr(arr_num[a], argv[1]) != NULL ){
            fl = 1;
							for ( int i = 0; i < 202; ) {
								if( arr[a][i] == '$')
								break;
								if( i == (strstr(arr_num[a], argv[1]) - arr_num[a])    ){
												for(i = (strstr(arr_num[a], argv[1]) - arr_num[a]); i<(strstr(arr_num[a], argv[1]) - arr_num[a]+strlen(argv[1])); i++){ 
													if(arr[a][i]<123 && arr[a][i]>96)
												arr[a][i]-=32;
													printf("%c", arr[a][i]);
												}
								}
								else if (i != (strstr(arr_num[a], argv[1]) - arr_num[a])   ){
								printf("%c", arr[a][i]);
								i++;
								}
						   }
			printf("\n");
		}
	a++;
}


if ( fl == 0)
printf("Not found\n");
}





return 0;
}

