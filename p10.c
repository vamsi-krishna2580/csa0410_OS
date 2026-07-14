#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg {
    long type;
    char text[100];
};

int main() {
    struct msg m;
    int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);

    m.type = 1;

    printf("Enter message: ");
    fgets(m.text, sizeof(m.text), stdin);

    msgsnd(msgid, &m, sizeof(m.text), 0);

    msgrcv(msgid, &m, sizeof(m.text), 1, 0);

    printf("Received: %s", m.text);

    return 0;
}