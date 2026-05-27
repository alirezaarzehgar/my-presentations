#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <err.h>

int main(int argc, char **argv)
{
    int fd;
    uid_t ruid, euid, suid;
    gid_t rgid, egid, sgid;
    char buf[BUFSIZ];

    getresuid(&ruid, &euid, &suid);
    getresgid(&rgid, &egid, &sgid);
    printf("ruid: %d, euid: %d, suid: %d\n", ruid, euid, suid);
    printf("rgid: %d, egid: %d, sgid: %d\n", rgid, egid, sgid);

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        err(-1, "failed to open %s", argv[1]);

    read(fd, buf, sizeof(buf));
    puts(buf);

    // $ cc ./vidcat.c -o vidcat 
    // $ ./vidcat /etc/shadow
    // ruid: 1000, euid: 1000, suid: 1000
    // rgid: 100, egid: 100, sgid: 100
    // vidcat: failed tp open /etc/shadow: Permission denied

    return (EXIT_SUCCESS);
}

