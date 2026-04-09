# LAPORAN PRAKTIKUM SISOP MODUL 2

Nama  : Irsa Fairuza  
NRP  : 5027251115

## Soal 1
Pada soal 1 ini kita diminta untuk mengamankan data buku_hutang.csv milik uncle muthu dengan menjadikannya file zip yang datanya sudah diperbarui dengan mengubah status yang "Belum Lunas" menjadi "Lunas". Pengamanan file ini dilakukan dengan membuat program kasir_muthu.c yang menggunakan Sequential Process dengan Parrent dan Child Process.

1) Membuat Folder

<img width="463" height="197" alt="ss1" src="https://github.com/user-attachments/assets/3185329b-4d35-4b90-9eca-90c49149d5ee" />

Langkah awal yang harus dilakukan tentunya dengan membuat folder SISOP-2-2026-IT-115 didalam ubuntu, lalu didalam folder tersebut kita membuat file kasir_muthu.c dengan touch serta memasukan file buku_hutang.csv yang sudah ada kedalam folder ini. 

<img width="464" height="83" alt="ss2" src="https://github.com/user-attachments/assets/65078fb3-a879-425a-9846-ec6b04f1f0f3" />

Lalu karena pada folder saya terdapat dua file buku_hutang.csv maka kita hapus yang satunya.

2) Melakukan Fork Pertama

<img width="611" height="397" alt="ss3" src="https://github.com/user-attachments/assets/5d53ffdb-f69a-4f84-9828-84c77d7b4689" />

Setelah file siap, kita masuk kedalam file kasir_muthu.c tersebut lalu melakukan fork dimana upin sebagai Parrent Process dan Ipen sebagai Child Procces. Karena terdapat dua process kita harus membuat pid untuk membedakan antara ID kedua process. Jika ID dari process sudah ada maka dilakukan pengecekan, jika pid kurang dari 0 maka itu bukan ID dari kedua process itu dan terjadi error. Program langsung berhenti dengan exit (1).

Jika pid = 0 berarti waktunya Ipin menjalankan tugasnya. Disini Ipin menyiapkan variabel yang berisi argumen untuk membuat folder (mkdir) yang bernama brankas_kedai, dan -p untuk mencegah error jika folder sudah ada. Lalu diakhiri olh NULL. Perintah tersebut akan dijalankan olh excv. Begitu perintahnya berhasil Ipin akan keluar dengan exit(1).

Saat Ipin berjalan Upin menunggu ipin selesai dalam pengecekan else. Disini Upin mengecek status dari Ipin dengan waitpid, jika Ipin dagal (status != 0) maka akan keluar output peringatan. Jika Ipin berhasil maka akan keluar output sukses.

<img width="459" height="184" alt="ss5" src="https://github.com/user-attachments/assets/a3673811-46b1-4ded-9bb9-33ccdb7f32bf" />

Setelah kode fork 1 selesai dibuat kita compile dan jalankan kodenya, terlihat bahwa folder brankas_kedai berhasil dibuat.

3) Membuat Fork Kedua

<img width="608" height="281" alt="ss6" src="https://github.com/user-attachments/assets/cf0d1c89-30c9-4e98-85e1-41b8298d62ba" />

Sama seperti fork pertama, disini kita membuat pid dan melakukan pengecekan pid. Yang membedakan adalah pada saat Ipin melakukan process nya argumen yang kita minta adalah meng coppy file buku hutang dengan perintah cp dan akan ditempatkan di folder brankas_kedai yang telah dibuat. Variabel-variabel pada fork ini juga beda dengan fork sebelumnya (menggunakan angka 2).

<img width="716" height="302" alt="ss7" src="https://github.com/user-attachments/assets/b7987569-b6df-4c3a-8eeb-64e07b436f2c" />

<img width="515" height="80" alt="ss8" src="https://github.com/user-attachments/assets/77edf4fb-3c7b-4bde-80cc-9fb0830c230f" />

Setelah kode siap saat dijalankan terdapat beberapa error pada penulisan, yaitu brangkas yang seharusnya brankas serta argv yang seharusnya argv2.

<img width="500" height="83" alt="ss10" src="https://github.com/user-attachments/assets/a97071fd-c8c7-4d94-b959-fd2c0697761f" />

Gambar diatas merupakan ouput setelah perbaikan kode.

4) Membuat Fork Ketiga

<img width="875" height="274" alt="ss11" src="https://github.com/user-attachments/assets/ee3d26ad-3659-48bb-bc72-fa28d8750448" />

Pada tahap ini tidak beda jauh dengan fork pertama dan kedua, disini pid yang ditetapkan yaitu pid3 dan untuk perintah yang dijalankan adalah mencari kata "Belum Lunas" pada file buku_hutang.csv menggunakan grep dan dipindahkan ke folder baru bernama daftar_penunggak.txt menggunakan '>'. Akan tetapi execv tidak mengerti argumen '>', ia akan membacanya sebagai nama file. Maka dari itu kita memanggil terminal shell (sh) yang akan membacanya, serta -c untuk memerintah si sh tersebut. Saat execv dipanggil si Child Process akan menjalankannya dengan Shell yang akan mengambil kata "Belum Lunas" dan memindahkannya ke daftar_penunggak.txt yang sudah dibuat otomatis melalui '>'.

<img width="491" height="134" alt="ss12" src="https://github.com/user-attachments/assets/e64c9e04-a758-4bc1-818f-a06211faa566" />

<img width="451" height="124" alt="ss13" src="https://github.com/user-attachments/assets/65cc6be9-7da3-409e-b223-f124e4809c45" />

Setelah Process selesai kita jalankan di terminal dan mendapat output seperti gambar diatas.

3) Membuat Fork Keempat

<img width="625" height="277" alt="ss14" src="https://github.com/user-attachments/assets/d26d8dab-3d06-4ceb-8120-cf407fb34c33" />

Langkah terakhir yaitu membuat fork keempat yang tidak beda jauh dengan fork sebelumnya. Untuk argumen atau perintah disini yaitu mengompres file brankas_kedai dengan perintah "zip" dan "-r" agar tidak ada file yang tertinggal didalam folder tersebut, file zip ini akan dinamakan rahasia_muthu.zip. Seperti sebelumnya, execv akan melakukan process tersebut dan Upin akan menunggu process nya sampai selesai dijalankan.

Setelah semua perintah selesai dijalankan maka ouput akhir yang keluar akan seperti di gambar berikut.

<img width="455" height="213" alt="ss15" src="https://github.com/user-attachments/assets/169419ac-055f-4e20-8e45-8928da62cea6" />

## Soal 2
Untuk soal dua ini kita diminta untuk membuat program daemon yang akan berjalan di background, yang nantinya akan mengeluarkan outpput setiap lima menit yang fungsinya untuk memantau apakah file contract.txt masih berjalan atau tidak. Jika daemonnya di kill ia akan menulis pesan di file work.log. Sebelum itu, saat program pertama kali jalan kita membuat file contract.txt yang berisi waktu saat ini.

<img width="337" height="35" alt="ss1" src="https://github.com/user-attachments/assets/2fa7649e-3560-47d6-b20f-c03ff4294250" />

Seperti soal sebelumnya, disini kita membuat folder soal 2 terlebih dahulu yang diisi dengan file contract_daemon.c

<img width="158" height="418" alt="ss2" src="https://github.com/user-attachments/assets/3793eb4f-d322-4e83-acf3-564d5c031658" />

Setelah masuk ke laman kodenya kita siapkan library yang dibutuhkan dan melakukan fork untuk ciptain Child Process dan juga menetapkan pid masing-masing process. Setelah itu dilakukan pengecekan, jika pid lebih dari nol maka program tidak berjalan. Jika pid lebih dari nol maka Parrent Process akan bunuh diri atau di kill dengan exit(). Tujuannya agar program parrent tidak ada lagi di terminal lalu terminal bisa dipakai untuk mengetik perintah lain. Selain itu, Child Process akan menjadi orphan dan akan berjalan di background. Child Process ini akan mengeset akses file menjadi 0 agar mendapatkan akses full terhadap file yang dibuat oleh daemon. Child Process juga membuat ID baru agar dia bisa berjalan, untuk mendapatkannya kita gunakan perintah setsid() yang memiliki return type yang sama dengan perintah fork(). Disini jika terminal dimatikan atau close Child Process ini ga akan ikut mati.

Setelah itu working directory yang kita punya diubah (pakai chdir) ke suatu directory yang pasti ada di dalam linux yaitu root (/). Lalu karena daemon tidak boleh menggunakan terminal maka kita menutup semua file descriptor standar (STDIN, STDOUT, STDERR).

Terakhir kita menyiapkan tempat untuk daemon terus berjalan menggunakan while (1). Disini ia akan terus berjalan setiap 5 detik sampai komputer dimatikan atau dibunuh dengan perintah kill.

<img width="344" height="343" alt="ss3" src="https://github.com/user-attachments/assets/909476a1-5bb9-418b-bf9a-17950038a58a" />

Selanjutnya untuk waktu saat ini yang akan ditulis pada bagian contract.txt kita pertama-tama menggunakan cwd atau Current Working Directory untuk mengetahui dimana program dijalankan. Disini kita membuat variabel cwd dgn isi character mencapai 1024. Lalu kita inisialisasikan getcwd unntuk mendapatkan tempat program berjalan dan akan disimpan di variabel cwd. Jika berhasil maka isi dari cwd akan berupa teks alamat lengkap programnya. Jika gagal atau NULL maka program akan langsung keluar dengan exit().

<img width="540" height="297" alt="ss4" src="https://github.com/user-attachments/assets/25452777-071a-41bb-9b5f-83a30e9e6212" />

Selanjutnya kita membuat variabel contract_path dengan batas 1050 character, lalu kita memanggil fungsi sprintf untuk membuat teks yang akan disimpan di variabel contract_path, isi dari teks itu adalah isi dari alamat ynag sudah disimpan di cwd (akan ditampilkan menggunakan %s).

Lalu untuk mencetak waktu pembuatan file kita menggunakan time(&rawtime) untuk mengambil waktu mentahan dari komputer serta localtime agar waktu sesuai dengan zona waktu local komputer. Setelah itu waktunya kita rapikan menggunakan strftime, yang tadinya waktunya berupa angka acak komputer menjadi teks dengan format Tahun-Bulan-Tanggal Jam:Menit:Detik. Terakhir waktu akan disimpan didalam variabel timestamp.

Selanjutnya kita membuka file contract_path dengan mode "w" yaitu write. Jika file sukses dibuka maka kita akan mengisinya menggunakan fprintf agar cetak langsung di file. Terakhir, jika sudah selesai cetak semua file harus di close dengan fclose. Lalu kita jalankan program nya.

<img width="946" height="339" alt="ss5" src="https://github.com/user-attachments/assets/ab2b0296-fe75-407d-a7df-b022fa2243fa" />

Terdapat error saat menjalankan program. Setelah diiperhatikan kita kurang menulis library untuk menyertakan waktu pada program.

<img width="185" height="108" alt="ss6" src="https://github.com/user-attachments/assets/078a610b-517c-4268-84be-9d79ce4c5a73" />

Ini merupakan library yang kita butuhkan.

Setelah itu kita coba lagi untuk meng compile dan menjalankan program. Berikut merupakan output yang didapatkan.

<img width="489" height="87" alt="ss8" src="https://github.com/user-attachments/assets/2e98c30e-46e6-4b58-a6db-4b4f340c3d77" />

