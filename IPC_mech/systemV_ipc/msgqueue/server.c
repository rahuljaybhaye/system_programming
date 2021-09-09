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
		  2nd arg:   The msgp argument is a pointer to a caller-defined structure of the  following general form:

		           struct msgbuf {
	        	       long mtype;       // message type, must be > 0
		               char mtext[1];    // message data 
	        		   };
		  3rd arg: whole size of mtext field which is an array (or other structure)
		  4th arg: msgtype
		  5th arg: message flags:-The msgflg argument is a bit mask constructed by ORing together  zero  or more flags


	 retruns :- On success -> the number of bytes actually copied into the mtext array.
		    On failuer ->  -1 with errno indicating the error,

*/


#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define SRV_MSG_TYPE 1
#define KEY 199330

struct msgbuf{			//user-defined structure
	long mtype;
	char mtext[20];
	}message;

int main()
{
//	char rx_msg[20];
//	char tx_msg[20];
	int msgid;
//	key_t key;

        // ftok to generate unique key
//        key = ftok("progfile", 65);

	msgid = msgget(KEY,IPC_CREAT|0660);
	printf("msgid:%d\n",msgid);
//	msgrcv(msgid,&message,sizeof(message),SRV_MSG_TYPE,0);
	msgrcv(msgid,&message,20,SRV_MSG_TYPE,0);

//	msgrcv(msgid,rx_msg,20,SRV_MSG_TYPE,0);
	printf("Unblock\n");

	printf("client, message type:%d\n",*(message.mtext));
	printf("client, pid:%d\n",(int)*(message.mtext+4));
	printf("client msg:%s\n",message.mtext+8);

//	printf("client :%s\n",rx_msg);

}
