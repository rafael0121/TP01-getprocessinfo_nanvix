/*
 * Copyright(C) 2011-2016 Pedro H. Penna <pedrohenriquepenna@gmail.com>
 *
 * This file is part of Nanvix.
 *
 * Nanvix is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Nanvix is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Nanvix. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SEM_H_
#define SEM_H_
    
    #include <nanvix/const.h>
    #include <nanvix/pm.h>

	/**
	 * @brief Comand values for semaphores.
	 */

    #define sem_t unsigned

    #define ACTIVE 1
    #define INACTIVE 0

	/**@{*/
	#define GETVAL   0 /**< Returns the value of a semaphore. */
	#define SETVAL   1 /**< Sets the value of a semaphore.    */
	#define IPC_RMID 3 /**< Destroys a semaphore.            */
	/**@}*/

	/* Forward definitions. */
	extern int semget(unsigned);
	extern int semctl(int, int, int);
	extern int semop(int, int);

    // Estrutura do semáfaro 
    struct semaphore{
            int id;    /* Identificador do semáforo */
            sem_t key; /* Key do semáforo. */
            int value; /* Valor do semáforo. */
            int state; /* Estado do semáforo. */
        int procusing; /* Quantidade de processos usando o semáforo. */
    };

    // Declaração da lista de semafóros.
    EXTERN struct semaphore semtab[SEM_MAX];  

    // Declaração da função que inicializa o semáforo.
    EXTERN void sem_init();

#endif /* SEM_H_ */
