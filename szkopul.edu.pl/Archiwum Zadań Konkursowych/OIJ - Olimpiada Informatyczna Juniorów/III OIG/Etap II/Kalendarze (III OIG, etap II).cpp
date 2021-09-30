#include<iostream> // 100 pkt
#include<vector>


typedef std::vector <int> VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define PB push_back


const int NUMBER_OF_CALENDARS = 2;


// Wartosci w tablicy sa z zakresu [1,10^6].
// Kalendarz typu A ma indeks rowny 0, natomiast 
// kalendarz typu B ma indeks rowny 1.
int numbers_of_months_in_calendars_versions[NUMBER_OF_CALENDARS];

// Liczba z zakresu [1,10^5].
int number_of_queries_of_dates_conversion;


/* 
	Kalendarz typu A ma numer (indeks) rowny 0, natomiast 
 	kalendarz typu B ma numer (indeks) rowny 1.
 	
 	Zakladamy, ze liczba wersji kalendarzy jest stala. 
	Jesli bedziemy chcieli dynamicznie dodawac/usuwac wersje kalendarzy, 
 	to nalezy zamienic tablice wektorow na np. mape 
	(klucz - ID wersji kalendarza, 
	 wartosc - wektor sum prefiksowych dla dlugosci miesiecy w danej wersji kalendarza).
 */ 
VI preffix_sums_of_months_lengths_in_calendars_versions[NUMBER_OF_CALENDARS];


/* 
	Obliczenie numeru dnia w roku, dla okreslonej daty w ustalonej wersji kalendarza. 
*/
int find_absolute_day_number_of_year_in_a_given_calendar_version(int day_number, int month_number, int calendar_version_number){
	return preffix_sums_of_months_lengths_in_calendars_versions[calendar_version_number][month_number-1] + day_number;
}

/*
	Wyznaczenie numeru dnia i miesiaca dla docelowej wersji kalendarza.
*/
int find_month_number_in_target_calendar_version(
				  int day_number_in_source_calendar_version, 
				  int month_number_in_source_calendar_version,
				  int source_calendar_version_number, 
				  int target_calendar_version_number){
				  	
	// Wynikiem jest przynajmniej pierwszy miesiac w docelowym kalendarzu.
	int start_month = 1;
	
	// Wynikiem jest co najwyzej ostatni miesiac w docelowym kalendarzu.
	int end_month = numbers_of_months_in_calendars_versions[target_calendar_version_number];
	
	// Zmienna pomocnicza do wyszukiwania wynikowego numeru miesiaca w docelowym kalendarzu.
	int medium_month;
	
	// Wartosc ta jest stala niezaleznie od wersji kalendarza (bo, z zalozenia, wszystkie wersje kalendarzy maja taka sama liczbe dni).
	int absolute_day_number = 
						find_absolute_day_number_of_year_in_a_given_calendar_version(
									day_number_in_source_calendar_version, 
				  					month_number_in_source_calendar_version,
				  					source_calendar_version_number
						);
	
	// Wyszukiwanie binarne po wynikowym numerze miesiaca w docelowym kalendarzu. 
	while( start_month <= end_month ){
		medium_month = ( start_month + end_month ) / 2;
		
		if( preffix_sums_of_months_lengths_in_calendars_versions[target_calendar_version_number][medium_month] < absolute_day_number ){
			start_month = medium_month + 1;
		}
		else{
			if( preffix_sums_of_months_lengths_in_calendars_versions[target_calendar_version_number][medium_month-1] < absolute_day_number ){
				return medium_month;
			}
			else{
				end_month = medium_month - 1;
			}
		}
	}
	
}


int find_day_number_in_target_calendar_version(int day_number_in_source_calendar_version, 
				  							   int month_number_in_source_calendar_version,
				  							   int source_calendar_version_number,
											   int target_calendar_version_number,
											   int month_number_in_target_calendar_version){
	
	// Wartosc ta jest stala niezaleznie od wersji kalendarza (bo, z zalozenia, wszystkie wersje kalendarzy maja taka sama liczbe dni).
	int absolute_day_number = 
					find_absolute_day_number_of_year_in_a_given_calendar_version(
								day_number_in_source_calendar_version, 
				  				month_number_in_source_calendar_version,
				  				source_calendar_version_number
					);
					
	return absolute_day_number - 
		   preffix_sums_of_months_lengths_in_calendars_versions[target_calendar_version_number][month_number_in_target_calendar_version-1];
}


/*
	Dla okreslonej daty w poczatkowym kalendarzu, 
	funkcja ta wyznacza numer miesiaca 
	dla docelowego kalendarza. 
*/
void find_day_and_month_numbers_in_target_calendar_version(
					  int day_number_in_source_calendar_version, 
					  int month_number_in_source_calendar_version, 
					  char source_calendar_version_code,
					  int &day_number_in_target_calendar_version,
					  int &month_number_in_target_calendar_version){
	
	// Wyznaczenie poczatkowego i docelowego numeru kalendarza dla warunkow zadania (dokladnie 2 kalendarze)
	int source_calendar_version_number = source_calendar_version_code - 'A';
	int target_calendar_version_number = 1 - source_calendar_version_number;
		
	// Wyznaczenie numeru miesiaca w docelowej wersji kalendarza 
	month_number_in_target_calendar_version = find_month_number_in_target_calendar_version( 
																	day_number_in_source_calendar_version, 
																	month_number_in_source_calendar_version, 
																	source_calendar_version_number, 
																	target_calendar_version_number 
																);
	
	// Wyznaczenie numeru dnia w docelowej wersji kalendarza
	day_number_in_target_calendar_version = find_day_number_in_target_calendar_version( 
													day_number_in_source_calendar_version, 
				  							    	month_number_in_source_calendar_version,
				  							    	source_calendar_version_number,
													target_calendar_version_number,
													month_number_in_target_calendar_version
												);
}


/* 
	Funkcja glowna calego programu.
*/
int main(int argc, char ** argv){
	
	/* Wylaczenie synchronizacji wejscia/wyjscia */
	std::ios_base::sync_with_stdio(0);
	
	// -------------------------------------
	
	/* Inicjacja sum prefiksowych dla kazdego kalendarza */
	
	REP(i,0,NUMBER_OF_CALENDARS-1){
		preffix_sums_of_months_lengths_in_calendars_versions[i].PB(0);
	}
	
	// -------------------------------------
	
	/* Wczytywanie danych o kalendarzach */
	
	
	// Wczytanie liczby miesiecy, odpowiednio, 
	// dla kalendarza typu A 
	// oraz dla kalendarza typu B
	REP(i,0,NUMBER_OF_CALENDARS-1){
		std::cin >> numbers_of_months_in_calendars_versions[i];
	}
	
	int length_of_currently_considered_month;
	
	REP(i,0,NUMBER_OF_CALENDARS-1){
		
		// Wczytanie dlugosci miesiecy dla i-tego kalendarza 
		// (kalendarz typu A ma indeks rowny 0, natomiast 
		//  kalendarz typu B ma indeks rowny 1).
		REP(j,0,numbers_of_months_in_calendars_versions[i]-1){
			std::cin >> length_of_currently_considered_month;
		
			preffix_sums_of_months_lengths_in_calendars_versions[i].PB(
				preffix_sums_of_months_lengths_in_calendars_versions[i].back() + 
				length_of_currently_considered_month
			);
		}
	}
		
	// -------------------------------------
	
	int source_day_number;
	int source_month_number;
	char source_calendar_version_code;
	
	int target_day_number;
	int target_month_number;
	
	// -------------------------------------
	
	/* Obsluga zapytan */
	
	std::cin >> number_of_queries_of_dates_conversion;
	while( number_of_queries_of_dates_conversion-- ){
		
		std::cin >> source_day_number >> source_month_number >> source_calendar_version_code;
		
		find_day_and_month_numbers_in_target_calendar_version(
					  source_day_number, 
					  source_month_number, 
					  source_calendar_version_code,
					  target_day_number,
					  target_month_number
		);
		
		std::cout << target_day_number << " " << target_month_number << std::endl;
		
	}
	
	// -------------------------------------
	
	/* Zakonczenie pracy programu */
	
	return 0;
}

/*

Testy

	
Test #1:

In:	
3 6
20 10 4
10 10 6 4 2 2
4
11 1 A
2 1 B
2 6 B
3 3 A

Out:
1 2
2 1
4 3
1 6

*/
