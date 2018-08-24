Creating your own Win7x64 driver in 2018 with WinDDK7.1 is fast and easy!

1. Download and install MS WinDDK7.1
2. Create a directory on a path with no spaces in the name (e.g. c:\users\user\myDriver) and cd into the directory
3. Create your driver.h
4. Create your driver.c
5. Create your sources file
6. Create your makefile
7. Create your .inx file
8. Create your makefile.inc
9. Open a command prompt as administrator
10. c:\winddk\7600.16385.1\bin\setenv.bat c:\winddk\7600.16385.1 free x64 Win7 
11. In the directory where your driver code resides, build -ceZ
12. Copy the coinstaller (Google this if necessary) to the directory of the built objects (e.g. .\obj*\amd64\)
13. From the same dir with the built objects, Inf2cat.exe /driver:. /os:7_x64 /verbose
14. From powershell, $cert = Get-ChildItem -Path "Cert:\CurrentUser\My\" -CodeSigningCert
15. Then, from the directory with the built objects, Set-AuthenticodeSignature -FilePath .\\*.sys -Certificate $cert
16. Finally, Then, Set-AuthenticodeSignature -FilePath .\\*.cat -Certificate $cert
17. Now, you're ready to install!
