/*2

***** //Setting signal set local variable (64 bit), This system calls not update to signal mask variable till we used sigprocmask()

	sigset_t set;	//local variable(we have to define)
       int sigemptyset(sigset_t *set);	//(all bits:0, i.e. signals->unblock)signal set variable base address(i.e. sa_mask base base address)


       int sigfillset(sigset_t *set);	//(1:block all signal) initializes set(one) to full, including all signals.

       int sigaddset(sigset_t *set, int signum);	//(1:block perticular signal)add respectively signal signum from set.

       int sigdelset(sigset_t *set, int signum);	//(0:Unblock perticular signal)del respectively signal signum from set.



********* // sigprocmask()  is  used  to  fetch and/or change the signal mask of the calling thread

     int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);		//update signal mask variable(pcb)

	1st mem :- SIG_BLOCK/ SIG_UNBLOCK/ SIG_SETMASK -> The behavior of the call is dependent on the value of how
				If any signal block but this member is SIG_UNBLOCK then nothing will hanpen
	2nd mem:- Signal set variable base addr
	3rd mem:- Old blocking signal info addr		//If not know then stored NULL(zero)

*/

#include<stdio.h>	//printf()
#include<signal.h>	//sigaction(),sigemptyset()
#include<unistd.h>	//sleep()


int main()
{
	sigset_t mask;

	//sigemptyset(&mask);	// (no blocking) All signal stauts updating->0(signal mask variable,64 bit) 
	//sigfillset(&mask);	// (All blocking) 1 -''-

//Perticular signal-> block / unblock
	// firstly all bits update to zero then block perticular bit
	sigemptyset(&mask);
	sigaddset(&mask,14);	//perticular bit-> one: block

	//sigdelset(&mask,14);	//perticular bit -> zero : non block

//	Above updation not performed to signalmask variable till we used sigprocmask()
	sigprocmask(SIG_BLOCK,&mask,0);		//with sigfillset(),sigaddset()
	//sigprocmask(SIG_UNBLOCK,&mask,0);	// with sigemptyset(),sigdelset()

	//sigprocmask(SIG_SETMASK,&mask,0);

	while(1)
	{
		printf("sleeping\n");
		sleep(2);
		//kill(getpid(),14);
	//	kill(getpid(),SIGSEGV);
	}
}


