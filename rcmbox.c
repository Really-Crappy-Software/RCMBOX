#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
FILE *iusearchbtw;
FILE *schlorpo;
FILE *test;
  char subject[100];
  char body[1000];
  char directory[10] = "/mail/";
  char hostname[15];
  char username[16];

  if (strcmp(argv[1], "send-to") == 0) {
        strcat(directory, argv[2]);
            test = fopen(directory, "r");
    if (test == NULL ) {
        printf("rcmbox: %s: Not an email that exists, use the 'create-mbox' argument to create one\n", argv[2]);
        return -1;
    }
    iusearchbtw = fopen(directory, "a");
      schlorpo = fopen("/etc/hostname", "r");
    fgets(hostname, 15, schlorpo);
    hostname[strcspn(hostname, "\n")] = 0;
    printf("Enter your subject:(100 chars maximum)\n");
    fgets(subject, 100, stdin);
    subject[strcspn(subject, "\n")] = 0;
    printf("Now, enter your body: (1000 maximum)\n");
    fgets(body, 1000, stdin);
    fprintf(iusearchbtw, "Subject:%s\n From:%s@%s.local\n Body:%s\n\n", subject, getenv("USERNAME"), hostname, body);
    fclose(iusearchbtw);
    fclose(schlorpo);
  } else if (strcmp(argv[1], "create-mbox") == 0) {
      test = fopen("/mail/", "r");
      if (test == NULL) {
        printf("Hmm /mail does not exist. Creating\n");
        // probably going to segfault
        fclose(test);
        mkdir("/mail", S_IRWXU);
;      }
    getlogin_r(username, 16);
    schlorpo = fopen("/etc/hostname", "r");
    fgets(hostname, 15, schlorpo);
    hostname[strcspn(hostname, "\n")] = 0;
    strcat(username, "@");
    strcat(username, hostname);
    strcat(username, ".local");
    // I was too lazy to use sprintf
    strcat(directory, username);
    char *homedir = getenv("HOME");
    strcat(homedir, "/mailbox");
    iusearchbtw = fopen(homedir, "w");
    link(homedir, directory);
    fclose(schlorpo);
    fclose(iusearchbtw);
  } else if (strcmp(argv[1], "-h") == 0) {
    printf("SYNTAX: rcmbox create-mbox, OR send-to EMAIL  \n create-mbox: creates a mailbox for your user account \n send-to: sends an email to another user \n -h: displays this menu \n If you have any issues report them on Github.\n");
} else {
          printf("SYNTAX: rcmbox create-mbox, OR send-to EMAIL  \n create-mbox: creates a mailbox for your user account \n send-to: sends an email to another user \n -h: displays this menu \n If you have any issues report them on Github.\n");
      }
      }
