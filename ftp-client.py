from ftplib import FTP

def uploadFile():
 filename = 'testfile.txt' #replace with your file in your home folder
 ftp.storbinary('STOR '+filename, open(filename, 'rb'))

def downloadFile():
 filename = 'testfile.txt' #replace with your file in the directory ('directory_name')
 localfile = open(filename, 'wb')
 ftp.retrbinary('RETR ' + filename, localfile.write, 1024)
 localfile.close()


ftp = FTP('')

#CONNECT PROMPT

#CONNECT
ftp.connect('localhost',1026)
ftp.login()
ftp.cwd('directory_name') #replace with your directory


#ACTION PROMPT
#LIST
ftp.retrlines('LIST')
#STORE
uploadFile()
#RETRIEVE
downloadFile()
#QUIT
ftp.quit()