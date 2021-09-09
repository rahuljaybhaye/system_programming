/*
       #include <sys/types.h>
       #include <sys/ipc.h>
       #include <sys/msg.h>

       int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
		1st arg: msg identifier (Return by msgget())
		2nd arg: The msgp argument is a pointer to a caller-defined structure $

                   struct msgbuf {
                       long mtype;       // message type, must be > 0
                       char mtext[1];    // message data
                           };
		 3rd arg: whole size of mtext field which is an array (or other structure)
       		 4th arg: message flags:-The msgflg argument is a bit mask constructed by$
		*mtype requied to update in structure,because its not present in msgsnd()

         retruns :- On success -> zero
                    On failuer ->  -1 with errno indicating the error,



*/



// C Program for Message Queue (Writer Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10

// structure for message queue
struct mesg_buffer {
	long mesg_type;
	char mesg_text[100];
} message;

int main()
{
	key_t key;
	int msgid;

	// ftok to generate unique key
	key = ftok("progfile", 65);

	// msgget creates a message queue
	// and returns identifier
	msgid = msgget(key, 0666 | IPC_CREAT);
	message.mesg_type = 1;

	printf("Write Data : ");
	fgets(message.mesg_text,MAX,stdin);

	// msgsnd to send message
	msgsnd(msgid, &message, sizeof(message), 0);

	// display the message
	printf("Data send is : %s \n", message.mesg_text);

	return 0;
}

