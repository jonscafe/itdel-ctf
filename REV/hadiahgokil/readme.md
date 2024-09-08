# Hadiah Gokil
# Description
Panjul mengincar pendaftaran ke sebuah aplikasi yang menawarkan hadiah untuk pendaftar ke 1000. Sayangnya ia kelewatan. Bantu panjul mencari id pengunjung ke 1000.
format: ITDEL{xxx-xxx-xxx-xxx}

# Flag
ITDEL{7B9-A34-2F6-E1C}

# Connection
http://HOSTNAME:7021

# Solver Description
Flow Solver:
1. Deobfuscate app.js
2. Baca fungsi register dan pahami mekanisme pembuatan id
3. Reverse fungsi pembuatan id
4. Gunakan fungsi reverse kepada id saat ini untuk mendapatkan id pendaftar ke 1000

# Score
500

# Author
scriptshogun

# Tags
Reverse Engineer, Web