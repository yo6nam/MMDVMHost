1. Copy both files to :
/lib/systemd/system

2. Execute :
systemctl enable mmdvmhost.service && systemctl daemon-reload

3. Copy / Move the MMDVM.ini to 
/home/pi

4. Start the service with :

systemctl start mmdvmhost.service

5. View live data with :

screen -R MMDVMHost

6. Exit the screen session with CTRL + A 'followed by' d
