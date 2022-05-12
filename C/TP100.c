
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void delay(int s){
	double timeDelay = (double) s + clock()/CLOCKS_PER_SEC;
	while(timeDelay > clock()/CLOCKS_PER_SEC){}
}
void cronometro (int tiempo_seg){
	for (int i = 1; i < tiempo_seg; i++){
	int value = rand() %50 +100;
//	printf("Ran: %d -",value);
	printf("Cronometro1: %d seg\n",i);
	delay(1);

	if(value > +145){
		break;
	}
	}
	printf("Cronometro finalizado");
}

int crono (int tiempo_seg, int temp, int jugador){
	for (int i = 1; i < tiempo_seg; i++){
	int valor_rand = rand() %50 +100;
//	printf("Ran: %d -",value);
	printf("Cronometro %d: %d seg\n",jugador,i);
	temp++;
	delay(1);
	if(valor_rand > +143){
		break;
	}
}
	return temp;
}

int main (void){
	srand(time(NULL));
	time_t now = time(NULL); //number of ms since 01/01/1970
	char *string_now = ctime(&now);
	printf("%s\n",string_now);


	struct tm *start_time = localtime(&now);
//	cronometro(15);
	int temporizador = crono(15,0,1);
	printf("\nEL tiempo del cronometro 1 se paró en: %d segundos\n\n",temporizador);
	int var2 = crono(15,temporizador,1);
	printf("\nEL tiempo del cronometro 1 se paró en: %d segundos",var2);

//	int var = 0;
//	int jugador = 1;
//	for (int j = 0; j < 3; j++){
//		int temporizador = crono(15,var,jugador);
//		printf("\nEL tiempo del cronometro 1 se paró en: %d segundos\n",temporizador);
//		var = temporizador;
//		jugador = 2;
//	}



	//	clock_t start, end;
		//	start = clock();
		//	for(int i = 0; i < 100000000; i++){}
		//	end = clock();
		//	double total = (double) (end - start) / CLOCKS_PER_SEC;
		//	printf("Tiempo de iteracion: %fs\n",total);







	//	printf("%ld\n", now);
	//	sleep(2);
	//	time_t two_secs = time(NULL);
	//	printf("%ld\n", two_secs);
	//	double diff = difftime(two_secs,now);
	//	printf("diff: %f\n",diff);


	//	struct tm *local_time = localtime(&now);
	//	printf("tm_hour: %d\n",local_time->tm_hour);
	//	printf("tm_min: %d\n",local_time->tm_min);
	//	printf("tm_sec: %d\n",local_time->tm_sec);
	//	printf("tm_mday: %d\n",local_time->tm_mday);
	//	printf("tm_mon: %d\n",local_time->tm_mon +1);
	//	printf("tm_year: %d\n",local_time->tm_year +1900);
	//	printf("tm_wday: %d\n",local_time->tm_wday);
	//	printf("tm_yday: %d\n",local_time->tm_yday);

	//	char *other_string = asctime(local_time);
	//	printf("\n%s\n", other_string);
	//
	//	clock_t start, end;
	//	start = clock();
	//	for(int i = 0; i < 100000000; i++){}
	//	end = clock();
	//	double total = (double) (end - start) / CLOCKS_PER_SEC;
	//	printf("Tiempo de iteracion: %fs\n",total);

	return 0;
}
