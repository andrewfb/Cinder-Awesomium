Cinder-Awesomium
================

Cinder block for the Awesomium web browser library.


Included is the Windows distribution of Awesomium 1.7.0 RC3, excluding their ```samples``` and ```wrappers``` folders. Please refer to the [Awesomium license](https://raw.github.com/paulhoux/Cinder-Awesomium/master/LICENSE.txt) for more information on licensing fees. Awesomium is NOT free software!


#####Using this block with the latest "appRewrite" version of Cinder
Cinder's tool for setting up empty projects, TinderBox, has been revamped and now supports a neat system for the management of plug-ins called Cinder Blocks. CinderAwesomium supports this new feature. Simply add this repository as a submodule, as described below. It will then automatically be detected by TinderBox and you can add it to your projects.
* Open a command window
* Switch to the disk containing the Cinder root folder: ```d:```
* Browse to the Cinder root folder: ```cd path\to\cinder_master```
* Add the Awesomium block as a submodule: ```git submodule add https://github.com/paulhoux/Cinder-Awesomium.git blocks/Awesomium```

See for more information:
https://forum.libcinder.org/#Topic/23286000001389463


#####Using this block with a release version of Cinder
Clone the Awesomium block to your Cinder folder:
* Open a command window
* Switch to the disk containing the Cinder root folder: ```d:```
* Browse to the Cinder root folder: ```cd path\to\cinder_master```
* Clone the repository: ```git clone https://github.com/paulhoux/Cinder-Awesomium.git blocks/Awesomium```

Alternatively, you can download the repository as a [ZIP-file](https://github.com/paulhoux/Cinder-Awesomium/zipball/master) and manually add the files to a "cinder_master\blocks\Awesomium" folder.


#####Using this block with a forked GIT version of Cinder
Add the Awesomium block as a submodule to your Cinder fork:
* Open a command window
* Switch to the disk containing the Cinder root folder: ```d:```
* Browse to the Cinder root folder: ```cd path\to\cinder_master```
* Add the Awesomium block as a submodule: ```git submodule add https://github.com/paulhoux/Cinder-Awesomium.git blocks/Awesomium```


#####Adding the block to your project
* Add the following folders to your include folders: 
 * ```cinder_master\blocks```
 * ```cinder_master\blocks\Awesomium\include``` 
* Add the following folder to your library folders: ```cinder_master\blocks\Awesomium\build\lib\msw```
* Add the following .lib files to your dependencies: ```awesomium.lib```
* Add this include statement at the top of your .cpp files: ```#include <CinderAwesomium.h>```
* Copy ALL files from ```cinder_master\blocks\Awesomium\build\bin\msw``` to your Debug and Release folders.


#####Copyright notice
Copyright (c) 2010-2012, Paul Houx - All rights reserved.
This code is intended for use with the Cinder C++ library: http://libcinder.org

Redistribution and use in source and binary forms, with or without modification, are permitted provided that
the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and	the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
