# FileInfo

A simple C++ command-line utility that retrieves and displays metadata about a file using the C Runtime `stat()` API.

## Features

* Accepts a file path as a command-line argument or prompts the user for one interactively.
* Retrieves file metadata using `stat()`.
* Displays:

  * File size
  * File mode
  * Device ID
  * Creation time
  * Last modification time
  * Last access time
* Uses `std::filesystem` to display only the executable name in the usage message.
* Uses `ctime_s()` for safe conversion of timestamps into human-readable strings.

## Requirements

* C++17 or later
* Microsoft Visual Studio (or any compiler with C++17 support)

## Build

Compile the project using Visual Studio or with a C++17-compatible compiler.

Example:

```bash
g++ FileInfo.cpp -std=c++17 -o FileInfo
```

## Usage

### Interactive Mode

```text
FileInfo.exe
```

The program will prompt for a file path.

Example:

```text
[>] FilePath: C:\Users\Nitin\Documents\sample.pdf
```

### Command-Line Mode

```text
FileInfo.exe "C:\Users\Nitin\Documents\sample.pdf"
```

### Invalid Usage

If more than one command-line argument is supplied, the program displays:

```text
Usage: FileInfo.exe <filepath>
```

## Example Output

```text
[+] Size        : 20166045 Bytes
[+] Mode        : 33206
[+] DeviceId    : 3
[+] Creation    : Wed Jul  1 10:16:46 2026
[+] Modification: Mon Jun  1 23:17:09 2026
[+] Last Access : Wed Jul  1 10:16:46 2026
```

## Concepts Demonstrated

* Command-line argument handling (`argc` / `argv`)
* C++ `std::string`
* Safe user input with `getline()`
* File metadata retrieval using `stat()`
* Converting `time_t` values using `ctime_s()`
* Using `std::filesystem::path` to extract executable names
* Basic error handling with `EXIT_SUCCESS` and `EXIT_FAILURE`

## Notes

* On Windows (MSVC), `st_ctime` represents the file's **creation time**.
* On POSIX/Linux systems, `st_ctime` represents the **metadata change time**, not the creation time.
* File modification times may be older than creation times if a file has been copied or downloaded while preserving its original modification timestamp.
