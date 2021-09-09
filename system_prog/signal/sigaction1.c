/*
******
//    The sigaction() system call is used to change the action taken by a process on receipt of a specific signal.  (See signal(7) for an overview of signals.)

       signum specifies the signal and can be any valid signal except SIGKILL and SIGSTOP.


*   int sigaction(int signum, const struct sigaction *act,
                     struct sigaction *oldact);
	first mem:- signal no/ signal name
	2nd mem:- structure base address
	3rd mem:- structure base address of old signal info

	 struct sigaction
	 {
               void     (*sa_handler)(int);	//signal handler base address / SIG_DFL / SIG_IGN
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;		//Signal set variable( ***not signal mask variable) ,64 bit, each bit-> one signal (1-> block, 0-> not block)
               int        sa_flags;		//addition flags to control behaviour of signal
               void     (*sa_restorer)(void);
           };

***** //Setting sa_mask variable (64 bit), This system calls not update to signal mask variable till we used sigprocmask()

       int sigemptyset(sigset_t *set);	//(all bits:0, i.e. signals->unblock)signal set variable base address(i.e. sa_mask base base address)


       int sigfillset(sigset_t *set);	//(1:block all signal) initializes set(one) to full, including all signals.

       int sigaddset(sigset_t *set, int signum);	//(1:block perticular signal)add respectively signal signum from set.

       int sigdelset(sigset_t *set, int signum);	//(0:Unblock perticular signal)del respectively signal signum from set.



********* // sigprocmask()  is  used  to  fetch and/or change the signal mask of the calling thread

*     int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);		//update signal mask variable(pcb)

	1st mem :- SIG_BLOCK/ SIG_UNBLOCK/ SIG_SETMASK -> The behavior of the call is dependent on the value of how
	2nd mem:- Signal set variable base addr
	3rd mem:- Old blocking signal info addr		//If not know then stored NULL(zero)


********************************************************************************
sigaction() and signal() ->change signal behaviour in signal disposition table(PCB)
sigemptyset(),sigfillset(),sigaddset(),sigdelset() ---> change signal set variable(which start with sigset_t), not any modification in signal mask variable
sigprocmask()	----> modify Signal mask variable(PCB) by using signal set variable (from local variable or sigaction structure variable)

*/

#include<stdio.h>	//printf()
#include<signal.h>	//sigaction(),sigemptyset()
#include<unistd.h>	//sleep()

void mysignal_handler(int signo)		//Required above main() fun if below then error occure
{
	printf("%d:signal is received\n",signo);
	sleep(3);
}


int main()
{
	struct sigaction act;	//local variable which point to sigaction structure
	act.sa_handler = mysignal_handler;
	//act.sa_handler = SIG_IGN;
	//act.sa_handler = SIG_DFL;

	act.sa_flags = 0;	//no flags
	sigemptyset(&act.sa_mask);	//singal stauts updating-> 0(no blocking)
	//sigfillset(&act.sa_mask);
	//sigaddset(&act.sa_mask,14);
	//sigdelset(&act.sa_mask,14);
	sigprocmask(SIG_UNBLOCK,&act.sa_mask,0);
	//sigprocmask(SIG_BLOCK,&act.sa_mask,0);

	sigaction(14,&act,0);


	while(1)
	{
		printf("sleeping\n");
		sleep(2);
		//kill(getpid(),14);
	}
}


