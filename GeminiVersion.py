import git
import sys
import subprocess

def compare_commits(commit_hash1, commit_hash2):
  """
  İki commit arasındaki değişiklikleri karşılaştırır ve word dosyasına yazar.

  Args:
    commit_hash1: İlk commit'in hash değeri.
    commit_hash2: İkinci commit'in hash değeri.
  """

  # Değişiklikleri içeren dosyayı aç
  diff_file = open("diff.txt", "w")

  # SourceTree'nin komut satırı arabirimini kullanarak diff'i al
  diff_command = ["sourcetree", "git", "diff", commit_hash1, commit_hash2, "--unified=full"]
  diff_output = subprocess.check_output(diff_command).decode()

  # Diff çıktısını satır satır işle
  for line in diff_output.splitlines():
    # Dosya eklenmişse
    if line.startswith("+++ b/"):
      filename = line[5:]
      diff_file.write(f"{filename} => eklendi\n")
      continue

    # Dosya silinmişse
    if line.startswith("--- a/"):
      filename = line[5:]
      diff_file.write(f"{filename} => silindi\n")
      continue

    # Satır değişiklikleri
    if line.startswith("+ ") or line.startswith("- ") or line.startswith("  "):
      # Eklenen satırlar yeşil
      if line.startswith("+ "):
        diff_file.write(f"\033[32m{line}\033[0m")
      # Silinen satırlar kırmızı
      elif line.startswith("- "):
        diff_file.write(f"\033[31m{line}\033[0m")
      # Diğer satırlar normal
      else:
        diff_file.write(line)

  # Dosyayı kapat
  diff_file.close()

# Örnek kullanım
commit_hash1 = sys.argv[1]
commit_hash2 = sys.argv[2]

compare_commits(commit_hash1, commit_hash2)

print("Değişiklikler diff.txt dosyasına yazıldı.")
