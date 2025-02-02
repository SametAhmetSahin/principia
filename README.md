Principia Open Source Project
=========

![Principia](https://raw.githubusercontent.com/Bithack/principia/master/data-src/github-image0.gif)

Principia is a sandbox physics game originally released in November 2013. It is the successor to the Android hit game "Apparatus".

Principia can be built on Windows, Linux, Android or iOS. The iOS version lags behind and lacks a lot of UI.

Compilation on Windows and Linux should be easy, see further below.

NOTE!
More documentation and resources will come in short!

Getting involved
--------

Feel free to fork this project and send in your pull requests. This is a community project and the community decides how the project evolves. If you are serious about joining and taking a bigger role, please fill in this form:

https://forms.gle/Pu7Lw5Vjc6yD4jwVA

Please join the Official Unofficial Discord here:

https://discord.gg/qV6APzKfk9

Follow Bithack on Twitter:

https://www.twitter.com/Bithack

Building and running
--------

## Building on Windows

The game engine behind Principia (TMS) is written in the C99 standard of C. Unfortunately, the Visual Studio C compiler does not support the C99 standard. Principia must therefore be compiled using the MSYS2 MINGW64 toolchain, as described below.

Please find the latest version of the 64-bit MSYS2 here: https://www.msys2.org/

After installation, a terminal opens. Run the following command to update the environment:

	$ pacman -Syu

The terminal will then ask you to close it when done. Proceed with doign so, and then go to the start menu and run MSYS Mingw32 64-bit. It is important that you run the "MINGW64 64-Bit" version and not the "MSYS2 MSYS" or "MINGW64 32-Bit". Run the commands below to install the necessary dependencies.

	$ pacman -S --needed base-devel mingw-w64-x86_64-toolchain autotools
	$ pacman -S mingw-w64-x86_64-curl mingw-w64-x86_64-gtk2 mingw-w64-x86_64-libpng mingw-w64-x86_64-libjpeg-turbo mingw-w64-x86_64-freetype mingw-w64-x86_64-SDL2 mingw-w64-x86_64-SDL2_gfx mingw-w64-x86_64-SDL2_image mingw-w64-x86_64-SDL2_mixer mingw-w64-x86_64-SDL2_ttf

Then navigate to the 'build-windows' folder inside of where you cloned Principia, for example:

	$ cd /c/Users/<username>/Principia/build-windows

And start the building process:

	$ ./autogen.sh
	$ ./configure
	$ ./go

Principia will launch if everything was successful. Note that the compilation might take up to 10 minutes depending on your system.

### Building the Windows installer
The Windows installer uses NSIS, which must be installed first before building:

	$ pacman -S mingw-w64-x86_64-nsis

For making Windows release builds you would run the `make_release.sh` script, which builds the game in release mode, copies over necessary DLL files, and builds the installer.

## Building on Linux

Install dependencies. For Debian-based distros:

	$ sudo apt-get install automake libgtk2.0-dev libgl-dev libxss-dev libxxf86vm-dev libasound2-dev libudev-dev valgrind libcurl4-openssl-dev libpng-dev libjpeg-dev libfreetype6-dev

For Arch-based distros:

	$ sudo pacman -S gtk2 curl freetype libpng libjpeg sdl2 sdl2_gfx sdl2_image sdl2_mixer sdl2_ttf

Navigate to the build-linux directory and start the building process:

	$ cd build-linux;
	$ ./autogen.sh
	$ ./configure
	$ ./go

If everything goes well, Principia will start by default unless `--silent` is passed to the `go` script.

### Packaging for Linux
When building Principia for packaging, you would want to use the following command to replace the above. It will clean the source tree, build a release version and not automatically run Principia.

	./go --clean --release --silent

Right now Principia needs to be installed with its executable next to the data directories. Putting all of that in `/opt/principia/` and symlinking `/usr/bin/principia` => `/opt/principia/principia` should do for now.

The `build-linux` directory contains desktop files and an usable icon, which can be installed into `/usr/share/applications/` and `/usr/share/pixmaps` respectively. `principia-url-handler.desktop` is for handling principia:// protocol links and is confirmed to work on at least Firefox and Chromium.

## Building for Android (on Linux)

These instructions can likely be easily adapted to build on any platform for Android.

Download Android Studio from:
https://developer.android.com/studio

Untar the archive (your version number might differ from the example below) and run studio.sh:

$ tar xzf android-studio-2021.2.1.16-linux.tar.gz

$ cd bin; ./studio.sh

Choose Custom in the Installer, click Next a bunch of times. Android Studio will download components for a while. Once finished, in the "Welcome to Android Studio" dialog, choose "Customize" in the left menu and then click "All Settings..." at the bottom center. Open Appearance -> System Settings -> Android SDK. Click the SDK Tools tab and check the following items:

- NDK (Side by side)
- Android SDK Command-line tools

Click Apply and wait for the components to download. Close Android Studio forever.

Open a terminal and run the build scripts:

$ cd build-android;

$ export ANDROID_HOME=/home/EXAMPLE/Android/Sdk

$ ./gradlew build

ANDROID_HOME should be set to the location where Android Studio installed the SDK (which you chose during setup). You might want to put that export line in your .bashrc file.

Finally, to install the game on your device:

$ ./gradew install


License
---------
See LICENSE.md


