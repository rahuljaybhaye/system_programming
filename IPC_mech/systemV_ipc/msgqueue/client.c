
/*
       #include <sys/types.h>
       #include <sys/ipc.h>
       #include <sys/msg.h>

       int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
                1st arg: msg identifier (Return by msgget())
                2nd arg: The msgp argument is a pointer to a caller-defined struct$

                   struct msgbuf {
                       long mtype;       // message type, must be > 0
                       char mtext[1];    // message data
                           };
                 3rd arg: whole size of mtext field which is an array (or other st$
                 4th arg: message flags:-The msgflg argument is a bit mask constru$
                *mtype requied to update in structure,because its not present in m$

         retruns :- On success -> zero
                    On failuer ->  -1 with errno indicating the error,



*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>
#include<unistd.h>	//getpid()

#define SRV_MSG_TYPE 1
#define KEY 199330

struct mesg_buffer {
        long mesg_type;
        char mesg_text[20];
} message;


int main()
{
	int msgid;
	int *msgHdr;

	msgid = msgget(KEY,0);		//to get msg_identifier w.r.t. KEY
	printf("msgid:%d\n",msgid);
	message.mesg_type = 1;		//message type update in  message structure

/*
	msgHdr = tx_msg;
	msgHdr[0]=SRV_MSG_TYPE;
	msgHdr[1] = getpid();
	printf("Enter msg:\n");
	scanf("%s",&msgHdr[2]);
	msgsnd(msgid,tx_msg,20,0);
	printf("msg send:%s",tx_msg);
*/
	msgHdr = message.mesg_text;
	msgHdr[0]=SRV_MSG_TYPE;
	msgHdr[1] = getpid();
	printf("Pid:%d",getpid());
	printf("Enter msg:\n");
	scanf("%s",&msgHdr[2]);
//	msgsnd(msgid, &message, sizeof(message), 0);
	msgsnd(msgid, &message, 20, 0);
	printf("msg send:%s",message.mesg_text);



/*        printf("Write Data : ");
	  fgets(message.mesg_text,10,stdin);

	msgsnd(msgid, &message, sizeof(message), 0);
        // display the message
        printf("Data send is : %s \n", message.mesg_text);
*/

}

