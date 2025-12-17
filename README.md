# MP3 Reader and Editor

## 📌 Description

A lightweight MP3 metadata reader and editor developed in C that allows users to view and modify ID3 tag information such as title, artist, album, year, genre, composer, and comments. The project focuses on file handling and string manipulation for multimedia file processing.

## ⚙️ Features

* Read MP3 metadata (ID3 tags)
* Edit and update song details (title, artist, album, year, genre, composer, comments)
* Simple and user-friendly implementation
* Useful for organizing and managing music libraries

## 🛠️ Technologies Used

* Programming Language: C
* Concepts: File Handling, String Manipulation, Structures
* Domain: Multimedia File Processing

## ▶️ How to Compile and Run

````bash
gcc *.c -o mp3_editor
./mp3_editor --help
```bash
gcc *.c -o mp3_editor
./mp3_editor sample.mp3
````

## 📌 Command-Line Usage

### View MP3 Metadata

```bash
./mp3_editor -v <mp3_file>
```

### Edit MP3 Metadata

```bash
./mp3_editor -e <option> <new_text> <mp3_file>
```

#### Edit Options

* `-t` : Edit Song Title
* `-a` : Edit Artist Name
* `-A` : Edit Album Name
* `-y` : Edit Year
* `-m` : Edit Content
* `-c` : Edit Comment

### Help Menu

```bash
./mp3_editor --help
```

## 📚 Skills Demonstrated

* C Programming
* File Handling
* String Manipulation
* Metadata Processing
* Command-Line Argument Handling
* Critical Thinking

