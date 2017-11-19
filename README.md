# Nilang Compiler V2.1
Not really v2 just internal versioning.

This is the repository for the NiLang Compiler.  
Before we dig in here are some handy repository to check out:
* [Nilang Specification](https://github.com/tompinn23/NI-Spec) Still not fully fleshed out, writing it is boring
* [Nilang V1](https://github.com/tompinn23/NiLang) OG NiLang Compiler built in C# and pretty poor imo.
* [Nilang Standard Library](https://github.com/tompinn23/NiLang-Standard-Library) So thats the standard library its pretty thin 

## Introduction

~~Right so here we are and you wanna build NiLang well ngl it kinda takes the piss and is only tested on Windows 7/ 10 Visual Studio 2017 Community Edition 64bit and.~~

We now have a build system!!!!!!!!!!.

### Dependencies
* LLVM 5.0.0
* Bison 3.0.4+
* Flex 2.6.3+
* Cmake 3.0.0+

## Building

##### Windows
  
To obtain flex and bison I recommend installing chocolatey from [here](https://chocolatey.org/install). Then run  
```choco install winflexbison3```

Cmake can be downloaded and installed from [cmake.org](https://cmake.org/download/)  

To build nilang do
```
git clone https://github.com/ni-lang/nilang
cd nilang
cmake -H. -Bbuild
```
If on windows 64 bit use the following command instead
```
cmake -G "Visual Studio 15 2017 Win64" -Thost=x64 -H. -Bbuild
```
Then
```
cmake --build build
```
##### Linux

You can find dependencies from your package manager.
Flex and bison may already be installed but may not be a high enough version.

To build nilang do
```
git clone https://github.com/ni-lang/nilang
cd nilang
cmake -H. -Bbuild
cmake --build build
```


Warning the build takes a long time first time as we have to build llvm
## License

Nilang V2.1 is released under the GNU GPL V3 license. Which can be found [here](https://www.gnu.org/licenses/gpl-3.0.en.html)

