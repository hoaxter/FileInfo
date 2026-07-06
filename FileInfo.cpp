#include <iostream>
#include <string>
#include <sys/stat.h>
#include <ctime>
#include <filesystem>

using namespace std;

#define OK "[+] "
#define FAIL "[-] "
#define INFO "[*] "
#define LOAD "[>] "
constexpr const char* EXECUTE = "[>>]";

int main(int argc, char** argv) {
    struct stat FileInfo;
    string Path;

    if (argc == 2)
    {
        Path = argv[1];
    }
    else if (argc > 2)
    {
        cout << "Usage: ./" << filesystem::path(argv[0]).filename().string() << " <\"filepath\"> \n";
        return EXIT_FAILURE;
    }
    else
    {
        cout << LOAD << "FilePath: ";
        getline(cin, Path);
    }

    if (stat(Path.c_str(), &FileInfo) == 0)
    {
        cout << OK << "Size        : " << FileInfo.st_size << " Bytes\n";
        cout << OK << "Mode        : " << FileInfo.st_mode << "\n";
        cout << OK << "DeviceId    : " << FileInfo.st_dev << "\n";

        char TimeBuffer[26];

        ctime_s(TimeBuffer, sizeof(TimeBuffer), &FileInfo.st_ctime);
        cout << OK << "Creation    : " << TimeBuffer;

        ctime_s(TimeBuffer, sizeof(TimeBuffer), &FileInfo.st_mtime);
        cout << OK << "Modification: " << TimeBuffer;

        ctime_s(TimeBuffer, sizeof(TimeBuffer), &FileInfo.st_atime);
        cout << OK << "Last Access : " << TimeBuffer;
    }
    else
    {
        cout << FAIL << "File Not Found!\n";
        cin.get();
        return EXIT_FAILURE;
    }

    cin.get();
    return EXIT_SUCCESS;
}
