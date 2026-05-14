#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <shadow.h>
#include <crypt.h>
#include <pwd.h>
#include <err.h>

int main(int argc, char **argv) {
    char *pass;
    struct spwd *sp;
    struct passwd *pw;

    pw = getpwnam(argc > 1 ? argv[1] : "root");
    if (!pw)
        err(-1, "user not found");
  
    sp = getspnam(pw->pw_name);
    if (!sp)
        err(-1, "failed to read shadow file");
    
    pass = getpass("Password: ");
    if (!pass || strcmp(crypt(pass, sp->sp_pwdp), sp->sp_pwdp))
        errx(-1, "authentication failed");
    
    setenv("HOME", pw->pw_dir, 1);
    setenv("USER", pw->pw_name, 1);

    if (setgid(pw->pw_gid))
        err(-1, "failed to set GID");
    if (setuid(pw->pw_uid))
        err(-1, "failed to set UID");

    execlp(pw->pw_shell, pw->pw_shell, NULL);
    // # cc su.c -o su -lcrypt
    // # chown root:root su && chmod +s su
    // $ ./su 
    // Password: 

    return 0;
}