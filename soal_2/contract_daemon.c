#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

int main() {
pid_t pid;
pid = fork();

char cwd[1024];
if (getcwd(cwd, sizeof(cwd)) == NULL) {
	perror("getcwd() error");
	exit(EXIT_FAILURE);
}

if (pid < 0) {
	exit(EXIT_FAILURE);
}

if (pid > 0) {
	exit(EXIT_SUCCESS);
}

umask(0);

pid_t sid;
sid = setsid();
if (sid < 0) {
	exit(EXIT_FAILURE);
}

if ((chdir("/")) < 0) {
	exit(EXIT_FAILURE);
}

close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);

char contract_path[1050];
sprintf(contract_path, "%s/contract.txt", cwd);

time_t rawtime;
struct tm *timeinfo;
char timestamp[80];

time(&rawtime);
timeinfo = localtime(&rawtime);
strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

FILE *fp = fopen(contract_path, "w");
if (fp != NULL) {
	fprintf(fp, "\"A promise to keep going, even when unseen.\"\n\n");
	fprintf(fp, "created at: %s\n", timestamp);
	fclose(fp);
	}

while (1) {
//programnya nanti tulis disini

sleep(5);
}

return 0;
}
