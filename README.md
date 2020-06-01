# base-vdj-qt-plugin
A base project to help developers get started developing Virtual DJ Auto-Start Plugins using the Qt framework.  Please note that this is meant to be for educational purposes and is here to show how one could start a Graphical User Interface (GUI) upon startup of the Virtual DJ application.  If planning to distribute/release a Virtual DJ Plugin that uses the Qt framework, please make sure to follow their respective terms of service and usage agreements before doing so.

# Prerequisites
* A computer with the Windows Operating System (OS)
* Virtual DJ (https://www.virtualdj.com/download/)
  * I am using the 64 bit version for Windows
* MinGW 64 bit (https://sourceforge.net/projects/mingw-w64/)
  * Also, modify your PATH environment variable to include the path to MinGW
  * Would also recommend creating a new environment variable such as MINGW that also points to that location
* 7-Zip
* Qt (https://www.qt.io/)
  * Installing Qt will also install Qt Creator which will be used while developing the plugin.  It is recommended to install Qt before moving on to the below Environment Setup.  Note, a new 'kit' will be configured within Qt Creator that uses a statically compiled version of Qt

# Environment Setup
* Clone this repository
* Modify windows-build-qt-static.ps1:
  * $QtSrcUrl - Make sure the QtSrcURL points to the version of Qt you wish to use (at the time of this writing I used version 5.14.2)
  * $QtStaticDir - If you do not want Qt to be installed at C:\Qt\Static, you can modify this value
  * $QtVersion - Should match the version downloaded and provided in the $QtSrcUrl variable
  * $MingwDir - Should be the path to MinGW 64 (if a MINGW environment variable was created, this should be able to be used here)
  * Please note that I did not develop this script.  The original location of this script can be found here (https://wiki.qt.io/Building_a_static_Qt_for_Windows_using_MinGW).  I have made some minor updates to get the script to run successfully with the current version of Qt.  This script will statically compile Qt.  **If planning on distributing a plugin that uses a Statically Compiled version of Qt, please note that this is against the Open Source version of the License for Qt.  Please review the Open Source vs. Commercial versions of Qt before distributing an application that uses Qt.**
* Once the windows-build-qt-static.ps1 has been modified, open Windows Powershell and run the script.  It will likely take a few hours to run.
* Open Qt Creator
* Configure a new Kit that points to the Statically Compiled version of Qt

# Testing
* Once the above Environment Setup has been completed, you can open the base-vdj-qt-plugin in Qt creator
* Configure the project to use the Kit that was created in the above Environment Setup step
* Build the project
* Once the project has been built, there should be a .dll that was created.  Place the .dll file in the ${VirtualDJ}\Plugins64\AutoStart folder and launch VDJ
* VDJ and a secondary blank window should pop up
