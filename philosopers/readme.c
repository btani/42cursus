/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readme.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:46:11 by btani             #+#    #+#             */
/*   Updated: 2023/06/04 17:48:23 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

/*funzione che crea un nuovo thread
-thread = puntatore a var. di tipo ptherad_t
-attr = argometno che permette di modificare le caratteristiche attuali del 
nuovo thread (di solito settata a NULL)
-start routine = void *function_name(void *arg) con questa funzione il thread 
inizia l-esecuzione
-arg = puntatore a dun arg da passare alla funzione start_routine
return = 0 se ok la creazione, un errore se fallisce
int	ft_pthread_create(pthread_t *restrict thread, const pthread_attr_t *restrict attr, void *(*start_routine)(void *), void *restrict arg);


funzione che blocca l'esecuzione di un thread finche il thread precedente non ha finito
-thread =  ID del thread di cui si deve aspettare la fine dell'esecuzione
-retval = puntatore a una var. che puo' contenere il return value delle funzione 
di routine del thread (si setta a NULL)
return = 0 se ok, un errore se fallisce
int	ft_pthread_join(pthread_t thread, void **retval)

int	pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr)
mutex = puntatore a una variabile del pthread_mutex_type, e' il mutex da inizializzare
mutexattr = puntatore a specifico  attributo del mutex, si sett a NULL
return = 0

int	pthread_mutex_lock(pthread_mutex_t *mutex))
return 0 se ok, errore se sbagliato
int	pthread_mutex_unlock(pthread_mutex_t *mutex)
return 0 se ok, errore se sbagliato
int	pthread_mutex_destroy(pthread_mutex_t *mutex)
                        
gcc -fsanitize=thread -g threads.c && ./a.out per controlalr ese ci sono data races

mutex: blocco che permette di regolare l'accesso ai dati e previene il fatto che le risorse
condivise vengano usate contemporaneamente


PER CONTROLLARE ERRORI SUI THREADS
-fsanitize=thread -g f(add at compilation) 
-fsanitize=address and valgrind
valgrind --tool=helgrind ./philo <args>
valgrind --tool=drd ./philo <args>
*/

typedef struct s_counter
{
	pthread_mutex_t count_mutex;
	unsigned int	count;
}		t_counter;

void	*ft_thread_routine(void *data)
{
	//ogni thread inizia qui
	pthread_t	tid;
	t_counter	*counter;
	unsigned int	i;

	tid = pthread_self();// funzione che fornisce l'ID del thread
	counter = (t_counter *)data;
	//per leggere il conteggio, si lokka il mutex
	pthread_mutex_lock(&counter->count_mutex);
	printf("%sThread: [%ld]: Count at thread start = %u.%s\n", YELLOW, tid, counter->count, NC);
	pthread_mutex_unlock(&counter->count_mutex);
	i = 0;
	while (i < TIMES_TO_COUNT)
	{
	//itera i tempi di time_to_count, incrementa il counter a ogni iterazione, lokka il mutex per la durata dell iterazione
		pthread_mutex_lock(&counter->count_mutex);
		counter->count++;
		pthread_mutex_unlock(&counter->count_mutex);
		i++;
	}
	pthread_mutex_lock(&counter->count_mutex);
	printf("%sThread: %ld: Final count = %u.%s\n", YELLOW, tid, counter->count, NC);
	pthread_mutex_unlock(&counter->count_mutex);
	return (NULL);
}


int	main(void)
{
	pthread_t	tid1;
	pthread_t	tid2;
	t_counter	counter; // struct che contiene il conto totale dei threads
	
	counter.count = 0;
	//inizializzo il mutex
	pthread_mutex_init(&counter.count_mutex, NULL);
	printf("Expected count: %s%u%s\n", GREEN, 2 * TIMES_TO_COUNT, NC);
	pthread_create(&tid1, NULL, ft_thread_routine, &counter);
	printf("Creato primo thread: %ld\n", tid1);
	pthread_create(&tid2, NULL, ft_thread_routine, &counter);
	printf("Creato secondo thread: %ld\n", tid2);
	pthread_join(tid1, NULL);
	printf("Join del primo thread: %ld\n", tid1);
	pthread_join(tid2, NULL);
	printf("Join del secondo thread: %ld\n", tid2);
	if (counter.count != (2 * TIMES_TO_COUNT))
		printf("%sERROR! Total count is: %u%s\n", RED, counter.count, NC);
	else
		printf("%sOK! Total count is: %u%s\n", GREEN, counter.count, NC);
	pthread_mutex_destroy(&counter.count_mutex);
	return (0);
}


