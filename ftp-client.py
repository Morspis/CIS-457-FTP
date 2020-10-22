from ftplib import FTP


# ACTION PROMPT / MAIN MENU
def mainMenu():
    userChoice = 0
    choices = ['1', '2', '3', '4', '5']
    while (userChoice not in choices):
        # print menu
        print("    MAIN MENU    ")
        print("-----------------")
        print("Enter the number of an action below...")
        print("1. LIST")
        print("2. CWD")
        print("3. UPLOAD")
        print("4. DOWNLOAD")
        print("5. QUIT")

        # get user input
        userChoice = input()

        # validate selection
        if (userChoice not in choices):
            print("That is not a valid choice. Returning to menu...")

    return userChoice


# UPLOAD FILE
def uploadFile(ftp):
    print("Enter the file to upload: ")
    filename = input()
    ftp.storbinary('STOR ' + filename, open(filename, 'rb'))


# DOWNLOAD FILE
def downloadFile(ftp):
    print("Enter the file to download")
    filename = input()  # replace with your file in the directory ('directory_name')
    localfile = open(filename, 'wb')
    ftp.retrbinary('RETR ' + filename, localfile.write, 1024)
    localfile.close()


# CONNECT PROMPT

# CONNECT
def connect(ftp):
    print("Enter the URI and PORT to connect to below: ")
    print("URI: ")
    URI = input()
    print("PORT: ")
    PORT = int(input())
    print("USERNAME: ")
    USERNAME = input()
    print("PASSWORD: ")
    PASSWORD = input()
    ftp.connect(URI, PORT)
    ftp.login(user=USERNAME, passwd=PASSWORD)


def changeWorkingDirectory(ftp):
    print("Enter the directory to change to: ")
    directory = input()
    ftp.cwd(directory)


# LIST
def listFiles(ftp):
    ftp.retrlines('LIST')


# STORE
# uploadFile()
# RETRIEVE
# downloadFile()


def main():
    ftp = FTP('')
    connect(ftp)
    userChoice = 0

    while (userChoice != 5):
      userChoice = int(mainMenu())

      if (userChoice == 1):
        listFiles(ftp)

        # if user indiciates to change the current directory
      elif (userChoice == 2):
        changeWorkingDirectory(ftp)

      elif (userChoice == 3):
        uploadFile(ftp)

      elif (userChoice == 4):
        downloadFile(ftp)

      elif (userChoice == 5):
        ftp.quit()


if __name__ == "__main__":
    main()
