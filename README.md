![cover_logo](https://github.com/haseeb-heaven/Quran-SearchEngine/blob/master/resources/quran_cloud.jpg?raw=true "")

# Quran-SearchEngine

**_QuranSearchEngine_** is application to get data from Quran using text keyword.
which fetches data from **[QuranCloud](https://alquran.cloud/) server** and shows data to user.</br>

**NOTE** : WORKS ON ALL MAJOR OS **_Windows,Linux,MacOS_**. (**Tested** on **Windows 10** and **macOS High Sierra**)</br>
It uses external tool **'CURL'** to fetch data from API ,You need to **install** that if not present in your system
using below commands.</br>
_Linux_ : **'sudo apt-get install curl'**.</br>
_Mac_ : **'brew install curl'**.</br>
_Windows_ : Its uses **Win32 Library** so no need to download anything.</br>


# Features :
1) Search from **37 different** languages.</br>
2) Search from **114** surahs.</br>
3) Output in **english** format to easily read.</br>
4) Shows Additional data aswell **Surah name,number and Revelation type**.</br>
5) Automatically detects all **errors** from **JSON and API side**.</br>
6) Portability to work on every **major OS** like **_Windows,Linux,Mac_**.</br>

# How to compile on windows :
You have to add **_WS-Library_** in your project by adding **'-l "ws2_32'** in compiler option if you are using IDE like **CodeBlocks,DevCPP**.</br>
Or If you are using **Visual Studio** then add this line of code **_#pragma comment(lib, "ws2_32")_**</br>
Or you can compile with **gcc** using this command **_gcc QuranCloudApp.c -o QuranCloudApp.exe -l "ws2_32_**</br>
**_NOTE : ITS NOT NEEDED IF YOU USING OS OTHER THAN WINDOWS, COMPILE NORMALLY_**</br>

## Searching using keywords : 

![search_engine](https://github.com/haseeb-heaven/Quran-SearchEngine/blob/master/resources/search_engine.jpg?raw=true "")

