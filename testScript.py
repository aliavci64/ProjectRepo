import sys
import subprocess
import logging
import os

# Log dosyasının adı ve konumu
LOG_FILE = 'C:/deneme/Degistirdim'


def main():
    # Loglama ayarları
    logging.basicConfig(filename=LOG_FILE, level=logging.DEBUG, format='%(asctime)s - %(levelname)s - %(message)s')
    
    logging.info("Script started.")

    try:
        print("Arguments passed to the script:")
        for arg in sys.argv:
            print(arg)
        
        logging.info("Burayi degistirdim!!!!!!")
        for arg in sys.argv:
            logging.info(arg)

        print("\nRunning 'git --version':")
        logging.info("Running 'git --version':")
        result = subprocess.run(['git', '--version'], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        print("stdout:", result.stdout)
        print("stderr:", result.stderr)
        
        logging.info(f"stdout: {result.stdout}")
        logging.error(f"stderr: {result.stderr}")

    except Exception as e:
        logging.error(f"An error occurred: {str(e)}")

    logging.info("Script finished.\n")

if __name__ == "__main__":
    main()
