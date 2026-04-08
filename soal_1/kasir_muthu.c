#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
 pid_t pid = fork();

 if (pid < 0) {
	printf("Error: Proses Fork Gagal\n");
        exit(1);
 }
 else if (pid == 0) {
	char *argv[] = {"mkdir", "-p", "brankas_kedai", NULL};
	execv("/bin/mkdir", argv);
	exit(1);
 }
 else {
	printf("Ini upin lagi nunggu ipin buat file\n");
	int status;
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
        	printf("[ERROR] Aiyaa! Proses gagal, file atau folder tidak ditemukan.\n");
		exit(1);
        }

 printf("Pembuatan folder brankas_kedai berhasil ^^\n\n");

 }

 pid_t pid2 = fork();

 if (pid2 < 0) {
	printf("Error: Proses Fork 2 Gagal\n");
	exit(1);
 }
 else if (pid2 == 0) {
	char *argv2[] = {"cp", "buku_hutang.csv", "brankas_kedai/", NULL};
	execv("/bin/cp", argv2);
 }
 else {
	int status2;
	waitpid(pid2, &status2, 0);
	if (WIFEXITED(status2) && WEXITSTATUS(status2) != 0) {
        	printf("[ERROR] Aiyaa! Proses gagal, file atau folder tidak ditemukan.\n");
        	exit(1);
	}

 printf("File buku_hutang.csv berhasil di coppy ^^\n\n");

 }

 pid_t pid3 = fork();

 if (pid3 < 0) {
 	printf("Error: Proses Fork 3 Gagal\n");
        exit(1);
 }
 else if (pid3 == 0) {
	char *argv3[] = {"sh", "-c", "grep 'Belum Lunas' brankas_kedai/buku_hutang.csv > brankas_kedai/daftar_penunggak.txt", NULL};
	execv("/bin/sh", argv3);
 }
 else {
	int status3;
	waitpid(pid3, &status3, 0);
	if (WIFEXITED(status3) && WEXITSTATUS(status3) != 0) {
        	printf("[ERROR] Aiyaa! Proses gagal, file atau folder tidak ditemukan.\n");
		exit(1);
        }

 printf("Data penunggak sudah dipindah ke daftar_penunggak.txt ^^\n\n");

 }

 pid_t pid4 = fork();
 if (pid4 < 0) {
	printf("Error: Proses fork 4 gagal");
	exit(1);
 }
 else if (pid4 == 0) {
	char *argv4[] = {"zip", "-r", "rahasia_muthu.zip", "brankas_kedai", NULL};
	execv("/usr/bin/zip", argv4);
 }
 else {
	int status4;
	waitpid(pid4, &status4, 0);
	if (WIFEXITED(status4) && WEXITSTATUS(status4) != 0){
	printf("[ERROR] Aiyaa! Proses gagal, file atau folder tidak ditemukan.\n");
	}
 }
 printf("Brankas berhasil di kompres ke rahasia_muthu.zip ^^\n\n");
 printf("[INFO] Fuhh, selamat! Buku hutang dan daftar penagihan berhasil diamankan.\n");
}
