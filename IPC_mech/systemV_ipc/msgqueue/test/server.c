/*
       #include <sys/types.h>
       #include <sys/ipc.h>
       #include <sys/msg.h>

**     int msgget(key_t key, int msgflg);
        1st arg: Userdefine key
        2nd arg:message flag-> IPC_CREAT|<Permissions>

 The  msgget()  system  call returns the System V message queue identifier
       associated with the value of the key argument

**     ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp,
                      int msgflg);
          1st arg: message queue identifier return by msgget()
          2nd arg:   The msgp argument is a pointer to a caller-defined structure $

                   struct msgbuf {
                       long mtype;       // message type, must be > 0
                       char mtext[1];    // message data 
                           };
          3rd arg: whole size of mtext field which is an array (or other structure)
          4th arg: msgtype
          5th arg: message flags:-The msgflg argument is a bit mask constructed by$


         retruns :- On success -> the number of bytes actually copied into the mte$
                    On failuer ->  -1 with errno indicating the error,

*/



// C Program for Message Queue (Reader Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

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

	// msgrcv to receive message
	msgrcv(msgid, &message, sizeof(message), 1, 0);

	// display the message
	printf("Data Received is : %s \n",
					message.mesg_text);

	// to destroy the message queue
	msgctl(msgid, IPC_RMID, NULL);

	return 0;
}

