*This project has been created as part of the 42 curriculum by sechavez.*

# born2beroot

## Description

### Overview

The 'born2beroot' project introduces us to the world of virtualization - mainly virtual machines. Unlike previous projects where we submit and evaluate the functionality of a program, this specific project tasks us with creating and setting up an operating system on a machine within VirtualBox.

As I am completely new to system administration, most of my time was spent researching, seeking out and understanding various online sources.

### Justification of choices

For our operating system, we had a choice between 'Debian' and 'Rocky'. The subject recommends Debian for those who are new to system administration. 

I, myself, am new to system administration, so I chose Debian. I looked into their differences a bit more and found that while Debian has easier configuration and wider documentation, Rocky Linux is aimed towards enterprise servers.

My choices for this project were mainly because the subject recommended them - though, I did some research on their counterparts mentioned on the subject, and found some reasons as to why I would've chosen them even without the subjects recommendation.

For the services, here are my choices:

*   **'AppArmor' over 'SELinux'** - AppArmor is simpler to use and easier to configure. AppArmor profiles are easily configured via editing text files in its /etc directory.

*   **'UFW' over 'FirewallD'** - As the name suggests, Uncomplicated Firewall is straightforward to use and configure via shell commands.

*   **'VirtualBox' over 'UTM'** - VirtualBox is generally more compatible with various systems compared to UTM - Since our computers are on Ubuntu Linux, I couldn't even make this choice.

As for my choices in setting up the machine:

*   **Partitioning**: The machine was partitioned with the inclusion of an encrypted Logical Volume Group - for the bonus requirements, we had to set up our partitions to be similar to a specific partition structure specified in the subject. 

*   **Security and User Management**: As was asked by the subject, several rules for User passwords and 'sudo' use have been enforced to ensure security for the system. The SSH was also configured to disable logging in with root.

*   **Services**: I made sure to only install the minimum of services that were required by the subject. I installed an extra service, 'Cockpit', to satisfy the requirements of the bonus. Cockpit is a web-based graphical interface for servers.




## Instructions

*As this project is about setting up the machine, these instructions are for navigating the machine and ensuring that everything is set up properly.*

### Mandatory

#### Starting the machine

1.  Ensure the contents of 'signature.txt' within the born2beroot repository correctly match the signature from the .vdi file of the virtual machine. To get the signature from the .vdi file, run the following command within the born2beroot virtual machines installation folder:
```bash
sha1sum born2beroot.vdi
```

2.  Open the VirtualBox program. To avoid overwriting the signature of the virtual machine, fully clone it. You can then start the clone and begin your tests.

#### Groups, AppArmor and UFW

*	To check which users belongs to a group, run the following command:
```bash
getent group <groupname>
```

*	To check if AppArmor/UFW are running, run the following commands:
```bash
systemctl status apparmor
```
```bash
systemctl status ufw
```


#### Password and Sudo policies

*	You can check the password and sudo policies manually, by inputting information that goes against what the subject asks, or by simply checking the config files. For the password policies, run the following commands:
```bash
nano /etc/login.defs
```
```bash
nano /etc/pam.d/common-password
```
*	For the sudo policies:
```bash
nano /etc/sudoers.d/sudo_config
```

#### 'monitoring.sh' and Crontab

*	The 'monitoring.sh' script can be found inside the home directory of user 'sechavez'. To view/run the file, run the following commands (must have root privileges/logged into sechavez):
```bash
nano /home/sechavez/monitoring.sh
```
```bash
bash /home/sechavez/monitoring.sh
```

*   To configure/view the crontab entry, run the following command (as root):
```bash
crontab -e
```

### Bonus part

#### Partition Structure

*	To be able to compare the Partition Structure of the virtual machine to the example in the subject, we must display the Partition Structure. To display it, run the following command:
```bash
lsblk
```

#### WordPress Website & Additional Service

*	To access and view the contents of the WordPress Website, open a web browser on your host machine, and connect to the website with the following address:
```bash
localhost:8080
```

*	To access and view the contents of the additional service I have installed, 'Cockpit', open a web browser on your host machine, and connect to the website with the following address:
```bash
localhost:9090
```

## Resources

### References

* [born2beroot Web Guide](https://42-cursus.gitbook.io/guide/1-rank-01/born2beroot)
* [Debian's Shell Commands](https://wiki.debian.org/ShellCommands)
* [Oracle VirtualBox Manual](https://www.virtualbox.org/manual/ch01.html)
* [systemd(1) Manual](https://man7.org/linux/man-pages/man1/systemd.1.html)
* [apt-get(8) Manual](https://linux.die.net/man/8/apt-get)
* [ssh(1) Manual](https://man7.org/linux/man-pages/man1/ssh.1.html)
* [UFW Manual](https://manpages.ubuntu.com/manpages/focal/man8/ufw.8.html)
* [sudo Manual](https://man7.org/linux/man-pages/man8/sudo.8.html)
* [login.defs(5) Manual](https://man7.org/linux/man-pages/man5/login.defs.5.html)
* [pam_pwquality(8) Manual](https://linux.die.net/man/8/pam_pwquality)
* [suoders(5) Manual](https://linux.die.net/man/5/sudoers)
* [Shell Scripting if-else Guide](https://www.digitalocean.com/community/tutorials/if-else-in-shell-scripts)
* [MariaDB Manual](https://mariadb.com/docs)

### Use of AI

AI assisted me in:
* Clarifying and solidifying various concepts within the project.