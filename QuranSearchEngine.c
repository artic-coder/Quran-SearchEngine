/*
BISMILLAH-I-RAHMAAN-E-RAHEEM . IN THE NAME OF GOD MOST POWERFUL AND MERCIFUL.

BRIEF : QuranSearchEngine is application to get data from Quran using text keyword.
which fetches data from QuranCloud API - 'https://alquran.cloud/api' server and shows data to user.

NOTE : WORKS ON ALL MAJOR OS Windows,Linux,MacOS. (Tested on Windows 10 and macOS High Sierra)
It uses external tool 'CURL' to fetch data from API ,You need to install that if not present in your system
using below commands.
Linux : 'sudo apt-get install curl'.
Mac : 'brew install curl'.
Windows : Its uses Win32 Library so no need to download anything.

*****************************
*******App components.*****
*****************************
1) Quran search engine (search text in whole Quran.).

*********************
*******Features.*****
*********************
1) Search from 37 different languages.
2) Search from 114 surahs.
3) Output in english format to easily read.
4) Shows Additional data aswell Surah name,number and Revelation type.
5)Automatically detects all errors from JSON and API side
6)Portability to work on every major OS like Windows,Linux,Mac.
*/

/*Include Parser,URL generator and API Connector.*/
#include "qc_lib/api_parser/qc_api_parser.c"
#include "qc_lib/url_generator/qc_url_generator.c"
#include "qc_lib/api_connector/qc_api_connect.c"

void ParseJSON(char*);
int main()
{
    char search_keyword[0x32] = {NULL},surah[0x32] = {NULL},edition[0x32] = {NULL};

    printf("Quran SearchEngine (V1.0)\n");
    printf("Enter search keyword : ");
    fgets(search_keyword,0x32,stdin);
    strtok(search_keyword,"\n");

    printf("Enter surah : ");
    fgets(surah,0x32,stdin);
    strtok(surah,"\n");

    printf("Enter edition or language : ");
    fgets(edition,0x32,stdin);
    strtok(edition,"\n");

    char *search_url = QC_GenerateSearchURL(search_keyword,surah,edition);
    char *json_string = QC_ConnectAPI(search_url);
    if(json_string != NULL)
    ParseJSON(json_string);

    getchar();
    return EXIT_SUCCESS;
}


/*ParseJSON : Parses the JSON data with QC_Parser.*/
void ParseJSON(char* json_string)
{
    /*Search all  tokens.*/
    char *token_keys[] = {api_parser_tokens[QC_TEXT],api_parser_tokens[QC_SURAH_AR_NAME],api_parser_tokens[QC_SURAH_ENG_NAME],api_parser_tokens[QC_REV_TYPE],api_parser_tokens[QC_SURAH_NUM]};
    size_t token_lens = sizeof(token_keys)/sizeof(token_keys[0]);
    QC_SearchTokens(json_string,token_keys,token_lens);
}
