#include <stdio.h> 
#include <time.h> 
 
int main(){ 
	time_t current_time; 
	time_t t = time(NULL); 
	struct tm timeStrct = *localtime(&t); 
	int year = 1900, month = 1; 
	printf("Enter birth date and time:\n"); 
	scanf("%d/%d/%d %d:%d", &timeStrct.tm_mday, &month, &year, &timeStrct.tm_hour, &timeStrct.tm_min); 
	timeStrct.tm_year = year - 1900; 
	timeStrct.tm_mon = month - 1; 
	time_t timeBirth = mktime(&timeStrct); /* рассчитывает UTC время в секундах, истекшее с 0 часов 1 января 1970 года */ 
	if (timeBirth == -1){ 
		printf("Error!"); 
	return -1; 
	} 
	time(&current_time); 
	int difference = difftime(current_time, timeBirth); /* Функция difftime() возвращает разность в секундах между временем time1 и временем time2 */
	printf("Time of life is %d seconds.\n", difference); 
	return 0; 
}

