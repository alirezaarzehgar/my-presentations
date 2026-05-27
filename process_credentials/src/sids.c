#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <err.h>

void show_ids()
{
    uid_t ruid, euid, suid;

    getresuid(&ruid, &euid, &suid);
    printf("ruid: %d, euid: %d, suid: %d\n", ruid, euid, suid);
}

int main(int argc, char **argv)
{
    uid_t ruid, euid, suid;

    show_ids();
    printf("Drop priviledge temporarily\n");
    if (seteuid(getuid()))
        err(-1, "failed to set UID");
    
    show_ids();
    printf("Regain priviledge\n");
    getresuid(&ruid, &euid, &suid);
    if(seteuid(suid))
        err(-1, "failed to set UID");

    show_ids();
    printf("Drop priviledge permanently\n");
    if (setuid(getuid()))
        err(-1, "failed to set UID");

    show_ids();

    // > cc sids.c -o sids
    // > sudo chown root:root sids && sudo chmod +s sids
    // > ./sids 
    // ruid: 1000, euid: 0, suid: 0
    // Drop priviledge temporarily
    // ruid: 1000, euid: 1000, suid: 0
    // Regain priviledge
    // ruid: 1000, euid: 0, suid: 0
    // Drop priviledge permanently
    // ruid: 1000, euid: 1000, suid: 1000

    
    return (EXIT_SUCCESS);
}

